#include "alarm.h"

Alarm::Alarm()
{
    statusGO = false;
    сallTime = new QString("");
}

Alarm::~Alarm()
{
    if(сallTime != nullptr) {
        delete сallTime;
    }
}

void Alarm::setStatusGO(bool status)
{
    this->statusGO = status;
}

bool Alarm::getStatusGO()
{
    return statusGO;
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
