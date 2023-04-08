#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "alarm.h"
#include "QTimer"
#include "QTimeEdit"
#include "QMessageBox"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    friend class MainWindowTests;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_startAlarmBut_clicked();// нажатие на кнопку "старт/отмена будильника"
    void updateTime();// обновление состояние будильника по тику таймера
    void updateTimeAfterCall();// секундомер после звонка будильника
    void on_stopAlarmBut_clicked();// нажатие на кнопку "Остановить будильник"

private:
    Ui::MainWindow *ui;
    Alarm* alarm;
    QTimer* timer;
    QTimer* timerAfterCall;// секундомер после звонка будильника
    int *indexTrack;// номер композиции


    QPushButton* getStartAlarmBut();
    QPushButton* getEditMusicBut();
    QPushButton* getstopAlarmBut();
    QLabel* getTimeLabel();
    QTimeEdit* getSetTimeAlarm();

};
#endif // MAINWINDOW_H
