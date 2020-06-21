/********************************************************************************
** Form generated from reading UI file 'myclockwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYCLOCKWINDOW_H
#define UI_MYCLOCKWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyClockWindow
{
public:
    QAction *actionEn_English;
    QAction *actionRu_Russia;
    QAction *actionExit;
    QAction *actionStop_Clock;
    QAction *actionRun_Clock;
    QAction *action_toggle_Dock;
    QAction *action_trayCheckBox;
    QAction *actionRestart_clock;
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QFrame *frame;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QFrame *line;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuControl;
    QMenu *menuLanguage;
    QToolBar *toolBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QGridLayout *gridLayout_2;
    QPushButton *pBtn_clear;
    QTableWidget *tableWidget;
    QSpacerItem *verticalSpacer;

    void setupUi(QMainWindow *MyClockWindow)
    {
        if (MyClockWindow->objectName().isEmpty())
            MyClockWindow->setObjectName(QString::fromUtf8("MyClockWindow"));
        MyClockWindow->setWindowModality(Qt::NonModal);
        MyClockWindow->setEnabled(true);
        MyClockWindow->resize(355, 360);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MyClockWindow->sizePolicy().hasHeightForWidth());
        MyClockWindow->setSizePolicy(sizePolicy);
        MyClockWindow->setMinimumSize(QSize(355, 350));
        MyClockWindow->setMaximumSize(QSize(355, 700));
        actionEn_English = new QAction(MyClockWindow);
        actionEn_English->setObjectName(QString::fromUtf8("actionEn_English"));
        actionRu_Russia = new QAction(MyClockWindow);
        actionRu_Russia->setObjectName(QString::fromUtf8("actionRu_Russia"));
        actionExit = new QAction(MyClockWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/rec/img/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon);
        actionStop_Clock = new QAction(MyClockWindow);
        actionStop_Clock->setObjectName(QString::fromUtf8("actionStop_Clock"));
        actionRun_Clock = new QAction(MyClockWindow);
        actionRun_Clock->setObjectName(QString::fromUtf8("actionRun_Clock"));
        action_toggle_Dock = new QAction(MyClockWindow);
        action_toggle_Dock->setObjectName(QString::fromUtf8("action_toggle_Dock"));
        action_toggle_Dock->setCheckable(true);
        action_toggle_Dock->setChecked(true);
        action_trayCheckBox = new QAction(MyClockWindow);
        action_trayCheckBox->setObjectName(QString::fromUtf8("action_trayCheckBox"));
        action_trayCheckBox->setCheckable(true);
        action_trayCheckBox->setEnabled(true);
        actionRestart_clock = new QAction(MyClockWindow);
        actionRestart_clock->setObjectName(QString::fromUtf8("actionRestart_clock"));
        centralwidget = new QWidget(MyClockWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(0, 80));
        label->setMaximumSize(QSize(16777215, 80));
        QFont font;
        font.setPointSize(28);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setMinimumSize(QSize(210, 80));
        frame->setMaximumSize(QSize(210, 80));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        frame->setLineWidth(3);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(false);
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);
        lineEdit->setMinimumSize(QSize(150, 40));
        lineEdit->setMaximumSize(QSize(150, 40));
        QFont font1;
        font1.setPointSize(25);
        font1.setStrikeOut(false);
        lineEdit->setFont(font1);
        lineEdit->setCursor(QCursor(Qt::BusyCursor));

        gridLayout->addWidget(lineEdit, 0, 0, 1, 1);


        horizontalLayout->addWidget(frame);


        verticalLayout->addLayout(horizontalLayout);

        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setWindowModality(Qt::NonModal);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);


        gridLayout_3->addLayout(verticalLayout, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(319, 2, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        gridLayout_3->addItem(verticalSpacer_2, 1, 0, 1, 1);

        MyClockWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MyClockWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 355, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuControl = new QMenu(menubar);
        menuControl->setObjectName(QString::fromUtf8("menuControl"));
        menuLanguage = new QMenu(menubar);
        menuLanguage->setObjectName(QString::fromUtf8("menuLanguage"));
        MyClockWindow->setMenuBar(menubar);
        toolBar = new QToolBar(MyClockWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        sizePolicy1.setHeightForWidth(toolBar->sizePolicy().hasHeightForWidth());
        toolBar->setSizePolicy(sizePolicy1);
        toolBar->setMovable(false);
        toolBar->setAllowedAreas(Qt::TopToolBarArea);
        toolBar->setFloatable(false);
        MyClockWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        dockWidget = new QDockWidget(MyClockWindow);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(dockWidget->sizePolicy().hasHeightForWidth());
        dockWidget->setSizePolicy(sizePolicy2);
        dockWidget->setMinimumSize(QSize(355, 175));
        dockWidget->setMaximumSize(QSize(355, 550));
        dockWidget->setFocusPolicy(Qt::TabFocus);
        dockWidget->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidget->setAllowedAreas(Qt::BottomDockWidgetArea|Qt::TopDockWidgetArea);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        sizePolicy2.setHeightForWidth(dockWidgetContents->sizePolicy().hasHeightForWidth());
        dockWidgetContents->setSizePolicy(sizePolicy2);
        dockWidgetContents->setMaximumSize(QSize(16777215, 1700));
        gridLayout_2 = new QGridLayout(dockWidgetContents);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pBtn_clear = new QPushButton(dockWidgetContents);
        pBtn_clear->setObjectName(QString::fromUtf8("pBtn_clear"));
        sizePolicy1.setHeightForWidth(pBtn_clear->sizePolicy().hasHeightForWidth());
        pBtn_clear->setSizePolicy(sizePolicy1);
        pBtn_clear->setMinimumSize(QSize(323, 23));
        pBtn_clear->setMaximumSize(QSize(355, 23));

        gridLayout_2->addWidget(pBtn_clear, 1, 0, 1, 1);

        tableWidget = new QTableWidget(dockWidgetContents);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy3);
        tableWidget->setMinimumSize(QSize(0, 35));
        tableWidget->setMaximumSize(QSize(16777215, 700));

        gridLayout_2->addWidget(tableWidget, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 2, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout_2->addItem(verticalSpacer, 2, 0, 1, 1);

        dockWidget->setWidget(dockWidgetContents);
        MyClockWindow->addDockWidget(Qt::BottomDockWidgetArea, dockWidget);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuControl->menuAction());
        menubar->addAction(menuLanguage->menuAction());
        menuFile->addAction(actionExit);
        menuControl->addAction(actionRun_Clock);
        menuControl->addAction(actionStop_Clock);
        menuLanguage->addAction(actionEn_English);
        menuLanguage->addAction(actionRu_Russia);
        toolBar->addAction(actionExit);
        toolBar->addAction(actionRun_Clock);
        toolBar->addAction(actionStop_Clock);
        toolBar->addAction(actionRestart_clock);
        toolBar->addAction(action_toggle_Dock);
        toolBar->addAction(action_trayCheckBox);

        retranslateUi(MyClockWindow);

        QMetaObject::connectSlotsByName(MyClockWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MyClockWindow)
    {
        MyClockWindow->setWindowTitle(QCoreApplication::translate("MyClockWindow", "Electronic Clock with Input", nullptr));
        actionEn_English->setText(QCoreApplication::translate("MyClockWindow", "En-English", nullptr));
        actionRu_Russia->setText(QCoreApplication::translate("MyClockWindow", "Ru-Russian", nullptr));
        actionExit->setText(QCoreApplication::translate("MyClockWindow", "Exit", nullptr));
        actionStop_Clock->setText(QCoreApplication::translate("MyClockWindow", "Stop Clock", nullptr));
        actionRun_Clock->setText(QCoreApplication::translate("MyClockWindow", "Run Clock", nullptr));
        action_toggle_Dock->setText(QCoreApplication::translate("MyClockWindow", "toggle_Dock", nullptr));
        action_trayCheckBox->setText(QCoreApplication::translate("MyClockWindow", "tray", nullptr));
        actionRestart_clock->setText(QCoreApplication::translate("MyClockWindow", "Restart_clock", nullptr));
        label->setText(QCoreApplication::translate("MyClockWindow", "<html><head/><body><p><span style=\" color:#0000ff;\">Time:</span></p></body></html>", nullptr));
        lineEdit->setText(QCoreApplication::translate("MyClockWindow", "00:00:00", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MyClockWindow", "File", nullptr));
        menuControl->setTitle(QCoreApplication::translate("MyClockWindow", "Control", nullptr));
        menuLanguage->setTitle(QCoreApplication::translate("MyClockWindow", "Language", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MyClockWindow", "toolBar", nullptr));
        pBtn_clear->setText(QCoreApplication::translate("MyClockWindow", "Clear Table", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyClockWindow: public Ui_MyClockWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYCLOCKWINDOW_H
