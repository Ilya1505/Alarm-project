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

// тест на старт будильника 1
void AlarmTests::test_start_1()
{
    Alarm *alarm = new Alarm;

    QCOMPARE(alarm->start("12:10"), true);
    QCOMPARE(alarm->start("00:01"), true);
    QCOMPARE(alarm->start(""), false);

    if(alarm != nullptr){
        delete alarm;
    }
}

// тест на старт будильника 2
void AlarmTests::test_start_2()
{
    Alarm *alarm = new Alarm;

    QCOMPARE(alarm->start("12:10:1"), false);

    if(alarm != nullptr){
        delete alarm;
    }
}

// тест на старт будильника 3
void AlarmTests::test_start_3()
{
    Alarm *alarm = new Alarm;

    QCOMPARE(alarm->start("incorrect"), false);

    if(alarm != nullptr){
        delete alarm;
    }
}

// тест на обновление будильника по тику таймера 1
void AlarmTests::test_update_1()
{
    Alarm *alarm = new Alarm;

    QCOMPARE(alarm->update(), false);

    if(alarm != nullptr){
        delete alarm;
    }
}

// тест на обновление будильника по тику таймера 2
void AlarmTests::test_update_2()
{
    Alarm *alarm = new Alarm;

    QString currTime = QTime::currentTime().toString("HH:mm");
    alarm->setCallTime(currTime);
    QCOMPARE(alarm->update(), true);

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

// тест на получение времени до звонка будильника
void AlarmTests::test_getMinuteToCall()
{
    Alarm *alarm = new Alarm;
    QTime currentTime = QTime::currentTime();

    QCOMPARE(alarm->getMinuteToCall(currentTime),currentTime.toString("HH:mm:ss"));

    if(alarm != nullptr) {
        delete alarm;
    }
}

// тест секундомера 1
void AlarmTests::test_stopwatch_1()
{
    Alarm *alarm = new Alarm;

    alarm->setSecAfterCall(10);
    alarm->setMinAfterCall(2);
    QCOMPARE(alarm->timeAfterCall(), "2 мин 11 сек");

    if(alarm != nullptr) {
        delete alarm;
    }
}

// тест секундомера 2
void AlarmTests::test_stopwatch_2()
{
    Alarm *alarm = new Alarm;

    alarm->setSecAfterCall(59);
    alarm->setMinAfterCall(0);
    QCOMPARE(alarm->timeAfterCall(), "1 мин 0 сек");

    if(alarm != nullptr) {
        delete alarm;
    }
}

void AlarmTests::test_media()
{
    Alarm *alarm = new Alarm;

    QCOMPARE(alarm->getCurrentTrack(),"source/Mozart.mp3");

    int* indexTrack = new int(4);
    alarm->setTrack(indexTrack);
    QCOMPARE(alarm->getCurrentTrack(), "source/Браво - Этот город самый лучший.mp3");

    if(alarm != nullptr) {
        delete alarm;
    }
    if(indexTrack != nullptr){
        delete indexTrack;
    }
}
