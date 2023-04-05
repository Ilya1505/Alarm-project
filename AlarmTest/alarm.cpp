#include "alarm.h"

Alarm::Alarm()
{

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
