#ifndef ALARMTESTS_H
#define ALARMTESTS_H

#include <QObject>
#include <QTest>

class AlarmTests : public QObject
{
    Q_OBJECT
public:
    explicit AlarmTests(QObject *parent = nullptr);
private slots:
    void test_create();// тест на создание объекта
    void test_start();// тест на старт будильника
    void test_update();// тест на обновление будильника по тику таймера
    void test_stop();// тест на остановку будильника
    void test_getMinuteToCall();// тест на получение времени до звонка будильника
};

#endif // ALARMTESTS_H
