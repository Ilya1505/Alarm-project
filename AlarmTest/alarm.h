#ifndef ALARM_H
#define ALARM_H
#include <QString>
#include "QTime"

class Alarm
{
public:
    Alarm();
    ~Alarm();

    void setStatusGO(bool status);
    void setSecAfterCall(int sec);
    void setMinAfterCall(int min);

    bool getStatusGO();
    QString getCurrentTime();
    QString getCallTime();
    QString getMinuteToCall(const QTime &timeCall);// вычисление времени до звонка
    QString timeAfterCall();// секундомер времени после звонка


    bool start(QString signalTime);// true - если запуск успешен, иначе - false
    bool update();// true - если звонок, иначе - false
    bool stop();// true - если остановка успешна, иначе - false

private:
    bool statusGO;// статус будильника: true - будильник взведен, иначе - false
    QString* currentTime;
    QString* сallTime;// время звонка

    // секундомер после звонка будильника
    int secAfterCall;
    int minAfterCall;

};

#endif // ALARM_H
