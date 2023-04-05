#ifndef ALARM_H
#define ALARM_H
#include <QString>

class Alarm
{
public:
    Alarm();
    bool start(QString signalTime);// true - если запуск успешен, иначе - false
};

#endif // ALARM_H
