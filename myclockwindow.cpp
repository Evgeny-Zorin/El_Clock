#include <QDebug>
#include <QRegExp>
#include <QRegExpValidator>
#include <QDir>
#include <QSettings>
#include <fstream>
#include <QEvent>
#include <QCloseEvent>
#include <QTableWidget>
#include <QLocale>
#include "myclockwindow.h"
#include "ui_myclockwindow.h"


MyClockWindow::MyClockWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MyClockWindow)
{
    ui->setupUi(this);
    pathApp = QCoreApplication::applicationDirPath();
    dataList.clear();
    qRegisterMetaTypeStreamOperators<class_ChangeHistory>("class_ChangeHistory");
    createHeaderTable();


    //~~~~~~~~
    connect(this->ui->action_toggle_Dock,SIGNAL(toggled(bool)), this, SLOT(on_action_toggle_Dock_toggled(bool))); //for DockWidget
    ui->dockWidget->setWindowTitle(tr("Change's table:"));
    //~~~~~~~~
    trayIcon = new QSystemTrayIcon(this);                                       //icon initialization
    trayIcon->setIcon(this->style()->standardIcon(QStyle::SP_ComputerIcon));    //selected a standard image
    trayIcon->setToolTip(tr("Program works in the system tray."));              //Работа со сворачиванием программы трей
    QAction * viewWindow = new QAction(tr("Maximize the window"), this);        //action Expand the window

    connect(viewWindow, SIGNAL(triggered()), this, SLOT(show()));               //return from the tray
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(close()));          //go to tray
    ui->menuControl->addAction(viewWindow);

    trayIcon->show();       //showing the app icon in the tray
    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));      //connecting the icon click signal to the handler

    //fileName = QCoreApplication::applicationDirPath() + QDir::separator() + "settings.txt";
    QRegExp regExp ("^([0-1][0-9]|2[0-3]):([0-5][0-9]):([0-5][0-9])$"); //regular expression
        ui->lineEdit->setValidator(new QRegExpValidator(regExp));       //installing the validator in the display

    ui->lineEdit->setText(QTime::currentTime().toString()); // initial clock reading
    ui->actionRun_Clock->setEnabled(false);                 //freeze button
    timerID = QObject::startTimer(interval);                //creating a timer
    connect(this,SIGNAL(newTime(QString)),ui->lineEdit,SLOT(setText(QString)));
    fullmsecDt = 0;
    connect(this, SIGNAL(triggered()),this, SLOT(on_actionRestart_clock_triggered()));

    readSettings(); //время скачет,необходима проверка системное время-время в дисплей
    //~~~~~~~~~~~~~~~~~

}



void MyClockWindow::createHeaderTable()
{ //create the horizontal (column) headers
    ui->tableWidget->setColumnCount(2);
    //ui->tableWidget->setRowCount(1);
    ui->tableWidget->setHorizontalHeaderLabels(HeaderList);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);    //prevent changing the table
}


void MyClockWindow::on_action_toggle_Dock_toggled(bool arg1)
{
    qDebug()<<"Dock: checked: "<<arg1;  //double function call and double message->bad
    if(arg1)
    ui->dockWidget->setVisible(true);
    else
    ui->dockWidget->setVisible(false);

}

bool MyClockWindow::event(QEvent *event)
{ if (event->type() == QEvent::Timer)     //Event recognition from a timer
    {
        //Forming a string representation of the time to display
      QString timeStr  = QTime::currentTime().addMSecs(fullmsecDt).toString();   //taking the system clock readings
      emit newTime(timeStr);              //Signal generation
        return true;
    }
    return  QMainWindow::event(event);    //call standard event handling
}
void MyClockWindow::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    qDebug()<<"iconActivated";
    switch (reason)
    {
    case QSystemTrayIcon::Trigger:      //The event is ignored if the checkbox is not selected
        if(ui->action_trayCheckBox->isChecked())
        {
            if(!this->isVisible()){
                this->show();           //if hidden, it opens to the screen
            } else {
                this->hide();           //if the window is visible, it is hidden,
            }
        }
        break;
    default:
        break;
    }
}

void MyClockWindow::closeEvent(QCloseEvent *event)
{
    //If the window is visible and the checkbox is checked, then the application isn't terminated
    //the window is simply hidden, which is accompanied by
    //corresponding pop-up message
    if(this->isVisible() && ui->action_trayCheckBox->isChecked())
    {
        qDebug()<<"isVisible";
        event->setAccepted(false);  //disable closing of the window
        this->hide();               //to hide the window
        QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::MessageIcon(QSystemTrayIcon::Information);

        trayIcon->showMessage("MyClockWindow",
                              tr("The app is minimized to the tray. "
                                 "To expand the app window, click the app icon in the tray!"),
                              icon,
                              300);
    }
   else
    {
       writeSettings();
       QObject::killTimer(timerID);    //delete the timer
    }

}

MyClockWindow::~MyClockWindow()
{
    qDebug()<<" By-by";
    delete ui;

}

void MyClockWindow::writeSettings()
{
    qDebug()<<"writeSettings";
    QSettings settings(pathApp + QDir::separator() + "settins.ini", QSettings::IniFormat);
    settings.beginGroup("MyClockWindow");
    settings.setValue("size", size());
    settings.setValue("state", saveState());
    settings.endGroup();

    settings.beginGroup("FullmsecDt");
    settings.setValue("fullmsecDt", fullmsecDt);
    settings.endGroup();

    settings.beginGroup("ListData");    //Open group
    toDataList();                       //move
    QVariant variant = QVariant::fromValue(dataList);//to QVariant
    settings.setValue("dataList", variant); //write to file
    settings.endGroup();                    //close group

}

void MyClockWindow::readSettings()
{
    qDebug()<<"readSettings";
    qDebug()<<"pathApp: "<<pathApp;
    QSettings settings(pathApp + QDir::separator() + "settins.ini", QSettings::IniFormat);
    settings.beginGroup("MyClockWindow");
    resize(settings.value("size").toSize());
    restoreState(settings.value("state").toByteArray());
    settings.endGroup();

    settings.beginGroup("FullmsecDt");
    fullmsecDt = settings.value("fullmsecDt").toInt();
    settings.endGroup();


    settings.beginGroup("ListData");
    QVariant variant = settings.value("dataList");
    settings.endGroup();
     if(variant.canConvert<class_ChangeHistory>())
       dataList = variant.value<class_ChangeHistory>();
       fromDataList(); //

}

void MyClockWindow::toDataList()
{
    Record tmp;
    dataList.clear();
     for(int r = 0; r < ui->tableWidget->rowCount(); ++r)
       {
        if(ui->tableWidget->item(r, 0) != 0)    //<~~~important!!!~~~~~~~~~~~~~~
        {
         qDebug()<<"toDataList "<<ui->tableWidget->item(0,0)->text();
         tmp.first = ui->tableWidget->item(r, 0)->text();
         tmp.second = ui->tableWidget->item(r, 1)->text().toLongLong();
         dataList<<tmp;
         qDebug()<<"toDataList tmp: "<< tmp;
        }
        else
            qDebug()<<" empty Item!";
        }

}

void MyClockWindow::fromDataList()
{
   qDebug()<<"fromDataList";
    on_pBtn_clear_clicked();    //clear tableWidget
    Record tmp;
     QTableWidgetItem *newItem;
     qDebug()<<"dataList.count(): "<<dataList.count();
     for(int i = 0; i < dataList.count() ; ++i)
     {
        tmp =dataList[i];
        qDebug()<<"fromDataList tmp: "<< tmp;
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
         for (int c = 0; c < ui->tableWidget->columnCount(); ++c)
           {
               if(c == 0)
               {
                   newItem = new QTableWidgetItem(tmp.first);
                   newItem->setTextAlignment(Qt::AlignCenter);
                   qDebug()<<"newItem.first: "<<newItem->text();
                   ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, c, newItem);
               }else
               {
                   qDebug()<<"fromDataList tmp.second"<<tmp.second;
                   newItem = new QTableWidgetItem(QString::number(tmp.second));
                   newItem->setTextAlignment(Qt::AlignCenter);
                   qDebug()<<"newItem.second: "<<newItem->text().toLongLong();
                   ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, c, newItem);
              }
           }
     }
     dataList.clear();
}


void MyClockWindow::on_pBtn_clear_clicked()
{
    qDebug()<<"clearContents";
    qDebug()<<"rowCount: "<<ui->tableWidget->rowCount();
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
}

void MyClockWindow::on_actionStop_Clock_triggered()
{
    ui->actionStop_Clock->setEnabled(false);        //freeze button
    ui->label->setText(tr("Edit:"));
    ui->label->setStyleSheet("color: red");
    QObject::killTimer(timerID);
    stateClock = stopClock;
    //~~~~~//take an old time
    QString strOldTime = ui->lineEdit->text();
    oldTime = QTime::fromString(strOldTime);
    if (oldTime.isValid())
         qDebug() << " oldTime: "<< oldTime.toString("hh:mm:ss");

    ui->lineEdit->setEnabled(true);                 //open the display for editing
    ui->actionRun_Clock->setEnabled(true);          //unfreeze button
}

void MyClockWindow::addRowfromTable()
{
    int Dt = oldTime.secsTo(newTimeDt);     //the difference between old and new time
    qDebug()<<" int Dt: "<<Dt;
    QString fullDt = QString::number(Dt);
    qDebug()<<"fullDt: "<<fullDt;

    if( Dt!= 0) //if the change was made
    {
        ui->tableWidget->insertRow( ui->tableWidget->rowCount() );
        QTableWidgetItem *newItemT, *newItemV;

        newItemT = new QTableWidgetItem(newTimeDt.toString());
        newItemT->setTextAlignment(Qt::AlignCenter);
        //newItemT = new QTableWidgetItem(oldTime.toString());  //maybe this?
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0,newItemT);

        newItemV = new QTableWidgetItem(fullDt);
        newItemV->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1,newItemV);
    }
    //fullmsecDt = 0;
}

void MyClockWindow::on_actionRun_Clock_triggered()
{
    qDebug()<<"on_actionRun_Clock_triggered";
    ui->actionRun_Clock->setEnabled(false);         //freeze button
    ui->label->setText(tr("Time:"));
    ui->label->setStyleSheet("color: blue");
    QString strNewTime = ui->lineEdit->text();      //take a new time
    newTimeDt = QTime::fromString(strNewTime);      //converting a string to QTime
    fullmsecDt = QTime::currentTime().msecsTo(newTimeDt);  //calculating the difference
    timerID = QObject::startTimer(interval);       //start a timer
    stateClock = runClock;
    ui->lineEdit->setEnabled(false);                //close the display for editing
    ui->actionStop_Clock->setEnabled(true);         //unfreeze button

    addRowfromTable();
}


void MyClockWindow::on_actionRestart_clock_triggered()
{//think about it better
    qDebug()<<"on_actionRestart_clock_changed";
    on_actionStop_Clock_triggered();
    ui->lineEdit->setText(QTime::currentTime().toString()); // initial clock reading
    fullmsecDt = 0;
    on_actionRun_Clock_triggered();
}

void MyClockWindow::on_actionRu_Russia_triggered()
{
    changeTranslator("ru_RU");
}

void MyClockWindow::on_actionEn_English_triggered()
{
     changeTranslator("en_EN");
}


void MyClockWindow::changeTranslator(QString postfix)
{
    QApplication::removeTranslator(translator); //disabling the current translator
    translator = new QTranslator(this);
    translator->load(QApplication::applicationName() + "_" + postfix); //uploading a new dictionary
    QApplication::installTranslator(translator);    //connecting a translator with a new dictionary
    //ui->statusBar->showMessage(tr("Current Language changed to %1").arg(postfix));

}

void MyClockWindow::changeEvent(QEvent *event)
{
    if(event->type() == QEvent::LanguageChange)
    {
        ui->retranslateUi(this);
    }
    else
    QMainWindow::changeEvent(event);
}




