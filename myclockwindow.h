#ifndef MYCLOCKWINDOW_H
#define MYCLOCKWINDOW_H

#include <QMainWindow>
#include <QCheckBox>
#include <QSystemTrayIcon>
#include <QAction>
#include <QMenu>
#include <QToolBar>
#include <QTime>
#include <QTranslator>
#include "class_changehistory.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MyClockWindow; }
QT_END_NAMESPACE

typedef  enum{stopClock, runClock} TStateClock;

class MyClockWindow : public QMainWindow
{
    Q_OBJECT
protected:
    bool event(QEvent *event) override; //accepts events of the timer element
    void closeEvent(QCloseEvent *event) override;
    void changeEvent(QEvent * event) override;
    void changeTranslator(QString postfix);
private:
    signals:    void newTime(QString timeStr);
public:
    MyClockWindow(QWidget *parent = nullptr);
    ~MyClockWindow();

    void writeSettings();   //write data to an ini file
    void readSettings();    //read data from an ini file
    void toDataList();      //packing these pairs in class_ChangeHistory
    void fromDataList();    //upload data from class_ChangeHistory to list
    void createHeaderTable();
    void addRowfromTable();

private slots:
//    void on_actionExit_triggered();
    void on_pBtn_clear_clicked();
    void on_actionRun_Clock_triggered();
    void on_actionStop_Clock_triggered();
    void on_action_toggle_Dock_toggled(bool arg1);     //show\unshow Dock
    void iconActivated(QSystemTrayIcon::ActivationReason reason);   //show tray
    void on_actionRestart_clock_triggered();

    void on_actionRu_Russia_triggered();

    void on_actionEn_English_triggered();

private:
    Ui::MyClockWindow *ui;
    QTranslator* translator;
    static const int interval = 500;    //the interval between ticks of the timer
    int timerID;                        //unique identifier for the timer
    TStateClock stateClock;             //value of the clock state
    int fullmsecDt;                     //difference in the timer
    QTime oldTime;
    QTime newTimeDt;
    QString fileName;                   //name file for save
  //  QCheckBox *trayCheckBox;            //pointer for Check Box tray
    QSystemTrayIcon *trayIcon;          //icon for tray

    QString pathApp;                    //path to the settings file
    class_ChangeHistory dataList;
    QStringList    HeaderList = {tr("Time"),tr("Value(sec)")};  //column names
};
#endif // MYCLOCKWINDOW_H
