#include "alarm.h"

Alarm::Alarm()
{
    statusGO = false;
    currentTime = new QString(QTime::currentTime().toString("HH:mm"));
    callTime = new QString("");

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
    if(callTime != nullptr) {
        delete callTime;
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

void Alarm::setCallTime(QString callTime)
{
    *this->callTime = callTime;
}

bool Alarm::getStatusGO()
{
    return statusGO;
}

// получение состояния медиа, true - мелодия играет, иначе - false
bool Alarm::getStatusMedia()
{
    if(player->playbackState() == QMediaPlayer::PlayingState){
        return true;
    } else{
        return false;
    }
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
    return *callTime;
}

// вычисление времени до звонка
QString Alarm::getMinuteToCall(const QTime &timeCall)
{
    long long msecToCall = QTime::currentTime().msecsTo(timeCall)+1000;
    QTime timeToCAll = QTime::currentTime().fromMSecsSinceStartOfDay(msecToCall);
    return timeToCAll.toString("HH:mm:ss");
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
     *this->callTime = signalTime;
     statusGO = true;
     return statusGO;
}

// тик таймера: true - если звонок, иначе - false
bool Alarm::update()
{
    *currentTime = QTime::currentTime().toString("HH:mm");

    if(*callTime == *currentTime) {
        //звонок будильника
        *callTime = "";
        player->setSource(QUrl::fromLocalFile(currentTrack));
        audioOutput->setVolume(50);
        player->play();
        return true;

    } else {
        return false;
    }
}

// остановка будильника: true - если остановка успешна, иначе - false
bool Alarm::stop()
{
    if(statusGO == false) {
        return statusGO;
    }
    secAfterCall = 0;
    minAfterCall = 0;
    statusGO = false;
    *callTime = "";
    player->stop();
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
