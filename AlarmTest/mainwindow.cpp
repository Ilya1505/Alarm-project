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

    //запуск таймера
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    timer->start(1000);

    //секундомер после звонка будильника
    timerAfterCall = new QTimer();
    connect(timerAfterCall, SIGNAL(timeout()), this, SLOT(updateTimeAfterCall()));

    // инициализации мелодии по умолчанию
    indexTrack = new int(0);

    //создание окна списка композиций
    windowMusic = new ChoiseMusic(this, indexTrack);
}

MainWindow::~MainWindow()
{
    delete ui;
    if(indexTrack != nullptr){
        delete indexTrack;
    }
    if(timer != nullptr){
        delete timer;
    }
    if(alarm != nullptr){
        delete alarm;
    }
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
    //если будильник не заведен
    if(ui->startAlarmBut->text() == "Завести будильник"){
        alarm->setTrack(indexTrack);//установка мелодии
        //если будильник не удалось завести, отмена
        if (alarm->start(ui->setTimeAlarm->text()) == false) {
            return;
        }
        //если будильник успешно завелся
        ui->startAlarmBut->setText("Отменить будильник");
        ui->setTimeAlarm->setEnabled(false);
        ui->editMusicBut->setEnabled(false);
        ui->stopAlarmBut->setText("Остановить будильник через\n"+alarm->getMinuteToCall(ui->setTimeAlarm->time()));

    // если будильник уже заведен, отмена завода
    } else{
        alarm->stop();
        ui->startAlarmBut->setText("Завести будильник");
        ui->setTimeAlarm->setEnabled(true);
        ui->editMusicBut->setEnabled(true);
        ui->stopAlarmBut->setText("Остановить будильник");
    }

}

// обновление состояние будильника по тику таймера
void MainWindow::updateTime()
{
    ui->timeLabel->setText(alarm->getCurrentTime());
    // если будильник заведен
    if(alarm->getStatusGO() == true){

        // вычисление времени до звонка
        ui->stopAlarmBut->setText("Остановить будильник через\n"+alarm->getMinuteToCall(ui->setTimeAlarm->time()));

        // если будильник звенит
        if(alarm->update() == true) {
            ui->stopAlarmBut->setText("Остановить будильник\n00:00");
            ui->stopAlarmBut->setEnabled(true);
            ui->startAlarmBut->setEnabled(false);
            timer->stop();
            timerAfterCall->start(1000);
        }
    }
}

// нажатие на кнопку "Остановить будильник"
void MainWindow::on_stopAlarmBut_clicked()
{
    alarm->stop();
    timerAfterCall->stop();
    ui->startAlarmBut->setText("Завести будильник");
    timer->start(1000);
    ui->stopAlarmBut->setEnabled(false);
    ui->setTimeAlarm->setEnabled(true);
    ui->stopAlarmBut->setText("Остановить будильник");
    ui->startAlarmBut->setEnabled(true);
    ui->editMusicBut->setEnabled(true);
}

//секундомер после звонка будильника
void MainWindow::updateTimeAfterCall()
{
    ui->stopAlarmBut->setText("Остановить будильник\n- " + alarm->timeAfterCall());
}
