#include "alarmtests.h"
#include "alarm.h"

AlarmTests::AlarmTests(QObject *parent)
    : QObject{parent}
{

}

// тест на создание объекта
void AlarmTests::test_create()
{
    Alarm *alarm = new Alarm;
    QCOMPARE_NE(alarm, nullptr);
    if(alarm != nullptr){
        delete alarm;
    }
}

// тест на старт будильника
void AlarmTests::test_start()
{
    Alarm *alarm = new Alarm;

    QCOMPARE(alarm->start("12:10"), true);
    QCOMPARE(alarm->start(""), false);

    if(alarm != nullptr){
        delete alarm;
    }
}

// тест на обновление будильника по тику таймера
void AlarmTests::test_update()
{
    Alarm *alarm = new Alarm;

    QCOMPARE(alarm->update(), false);

    if(alarm != nullptr){
        delete alarm;
    }
}

// тест на остановку будильника
void AlarmTests::test_stop()
{
    Alarm *alarm = new Alarm;

    alarm->setStatusGO(false);
    QCOMPARE(alarm->stop(), false);

    alarm->setStatusGO(true);
    QCOMPARE(alarm->stop(), true);

    if(alarm != nullptr){
        delete alarm;
    }
}
