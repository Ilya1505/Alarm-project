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
    void on_startAlarmBut_clicked();
    void updateTime();

private:
    Ui::MainWindow *ui;
    Alarm* alarm;
    QPushButton* getStartAlarmBut();
    QPushButton* getEditMusicBut();
    QPushButton* getstopAlarmBut();
    QLabel* getTimeLabel();
    QTimeEdit* getSetTimeAlarm();

};
#endif // MAINWINDOW_H
