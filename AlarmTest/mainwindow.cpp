#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QWidget::setFixedSize(390,384);
    ui->setupUi(this);
    alarm = new Alarm();

    // установка текущего времени
    ui->timeLabel->setText(alarm->getCurrentTime());
    ui->stopAlarmBut->setEnabled(false);

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

// нажатие на кнопку "старт/отмена будильника"
void MainWindow::on_startAlarmBut_clicked()
{
    // todo дописать установку музыки и подсчет времени до звонка
    //если будильник не заведен
    if(ui->startAlarmBut->text() == "Завести будильник"){

        //если будильник не удалось завести, отмена
        if (alarm->start(ui->setTimeAlarm->text()) == false) {
            return;
        }
        //если будильник успешно завелся
        ui->startAlarmBut->setText("Отменить будильник");
        ui->setTimeAlarm->setEnabled(false);
        ui->editMusicBut->setEnabled(false);
        ui->stopAlarmBut->setText("Остановить будильник\n");

    // если будильник уже заведен, отмена завода
    } else{
        alarm->stop();
        ui->startAlarmBut->setText("Завести будильник");
        ui->setTimeAlarm->setEnabled(true);
        ui->editMusicBut->setEnabled(true);
        ui->stopAlarmBut->setText("Остановить будильник");
    }

}

// обновление таймера
void MainWindow::updateTime()
{
    ui->timeLabel->setText(alarm->getCurrentTime());
    // если будильник заведен
    if(alarm->getStatusGO() == true){

        // если будильник звенит
        if(alarm->update() == true) {
            ui->stopAlarmBut->setText("Остановить будильник\n00:00");
            ui->stopAlarmBut->setEnabled(true);
            ui->startAlarmBut->setEnabled(false);
        }
    }
}
