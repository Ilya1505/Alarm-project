#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QPushButton* MainWindow::getStartAlarmBut()
{
    return ui->startAlarmBut;
}

QPushButton* MainWindow::getEditMusicBut()
{
    return ui->editMusicBut;
}

QPushButton* MainWindow::getstopAlarmBut()
{
    return ui->stopAlarmBut;
}

QLabel* MainWindow::getTimeLabel()
{
    return ui->timeLabel;
}

QTimeEdit* MainWindow::getSetTimeAlarm()
{
    return ui->setTimeAlarm;
}

void MainWindow::on_startAlarmBut_clicked()
{
    // todo доделать данный метод позже до конца

    //если будильник не заведен
    if(ui->startAlarmBut->text() == "Завести будильник"){

        //если будильник успешно завелся
        ui->startAlarmBut->setText("Отменить будильник");

    // если будильник уже заведен, отмена завода
    } else{
        ui->startAlarmBut->setText("Завести будильник");
    }

}

