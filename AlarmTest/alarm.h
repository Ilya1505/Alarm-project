#ifndef ALARM_H
#define ALARM_H
#include <QString>

class Alarm
{
public:
    Alarm();
    ~Alarm();

    void setStatusGO(bool status);
    bool getStatusGO();


    bool start(QString signalTime);// true - если запуск успешен, иначе - false
    bool update();// true - если звонок, иначе - false
    bool stop();// true - если остановка успешна, иначе - false

private:
    bool statusGO;// статус будильника: true - будильник взведен, иначе - false
    QString* сallTime;// время звонка
};

#endif // ALARM_H
