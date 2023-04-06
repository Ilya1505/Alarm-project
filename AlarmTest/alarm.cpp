#include "alarm.h"

Alarm::Alarm()
{
    statusGO = false;
    currentTime = new QString(QTime::currentTime().toString("HH:mm"));
    сallTime = new QString("");

    // инициализация словаря композиций
    track[0] = "source/Mozart.mp3";
    track[1] = "source/Yiruma - River Flows In You.mp3";
    track[2] = "source/atc-around-the-world.mp3";
    track[3] = "source/OneRepublic - All the Right Moves.mp3";
    track[4] = "source/Браво - Этот город самый лучший.mp3";

    // композиция по умолчанию
    currentTrack = track[0];

    //объекты для работы с медиа
    player = new QMediaPlayer;
    audioOutput = new QAudioOutput;
    player->setAudioOutput(audioOutput);

    secAfterCall = 0;
    minAfterCall = 0;
}

Alarm::~Alarm()
{
    if(сallTime != nullptr) {
        delete сallTime;
    }
    if(currentTime != nullptr) {
        delete currentTime;
    }
}

void Alarm::setStatusGO(bool status)
{
    this->statusGO = status;
}

void Alarm::setSecAfterCall(int sec)
{
    secAfterCall = sec;
}

void Alarm::setMinAfterCall(int min)
{
    minAfterCall = min;
}

// установка композиции по номеру
void Alarm::setTrack(int *indexTrack)
{
    currentTrack = track[*indexTrack];
}

bool Alarm::getStatusGO()
{
    return statusGO;
}

QString Alarm::getCurrentTime()
{
    return QTime::currentTime().toString("HH:mm:ss");
}

QString Alarm::getCurrentTrack()
{
    return currentTrack;
}

QString Alarm::getCallTime()
{
    return *сallTime;
}

// вычисление времени до звонка
QString Alarm::getMinuteToCall(const QTime &timeCall)
{
    // todo реализовать вычисление времени позже до конца
    QTime time = timeCall;
    return time.toString("HH:mm:ss");
}

// запуск будильника: true - если запуск успешен, иначе - false
bool Alarm::start(QString signalTime)
{

    // если нет времени звонка, отмена запуска
    if(signalTime=="") {
        return false;
    }

    // проверка корректности времени
    QStringList timeList = signalTime.split(":");
    if(timeList.size() != 2){
        return false;
    }
    try {
        timeList[0].toInt();
        timeList[1].toInt();
    } catch (...) {
        return false;
    }
     *this->сallTime = signalTime;
     statusGO = true;
     return statusGO;
}

// тик таймера: true - если звонок, иначе - false
bool Alarm::update()
{
    //todo реализовать данный метод позже до конца
    return false;
}

// остановка будильника: true - если остановка успешна, иначе - false
bool Alarm::stop()
{
    //todo доделать данные метод похже до конца
    if(statusGO == false) {
        return statusGO;
    }
    statusGO = false;
    return !statusGO;

}

// секундомер после звонка
QString Alarm::timeAfterCall()
{
    secAfterCall++;
    if(secAfterCall > 59) {
        secAfterCall = 0;
        minAfterCall++;
    }

    QString result = QString::number(minAfterCall) + " мин " + QString::number(secAfterCall) + " сек";
    return result;
}
