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
}
