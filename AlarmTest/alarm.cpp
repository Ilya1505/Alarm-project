#include "alarm.h"

Alarm::Alarm()
{
    statusGO = false;
    currentTime = new QString(QTime::currentTime().toString("HH:mm"));
    сallTime = new QString("");
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

bool Alarm::getStatusGO()
{
    return statusGO;
}

QString Alarm::getCurrentTime()
{
    return QTime::currentTime().toString("HH:mm:ss");
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
    // todo реализвать метод start позднее полностью
    if(signalTime != "") {
        return true;
    } else {
        return false;
    }
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
    // todo доделать секундомер позже

    QString result = QString::number(minAfterCall) + " мин " + QString::number(secAfterCall) + " сек";
    return result;
}
