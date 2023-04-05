#ifndef ALARM_H
#define ALARM_H
#include <QString>

class Alarm
{
public:
    Alarm();
    ~Alarm();
    bool start(QString signalTime);// true - если запуск успешен, иначе - false
    bool update();// true - если звонок, иначе - false

private:
    QString* сallTime;// время звонка
};

#endif // ALARM_H
