#include "alarm.h"

Alarm::Alarm()
{
    сallTime = new QString("");
}

Alarm::~Alarm()
{
    if(сallTime != nullptr) {
        delete сallTime;
    }
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
