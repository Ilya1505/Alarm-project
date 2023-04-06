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
    void test_start_1();// тест на старт будильника 1
    void test_start_2();// тест на старт будильника 2
    void test_start_3();// тест на старт будильника 3
    void test_update();// тест на обновление будильника по тику таймера
    void test_stop();// тест на остановку будильника
    void test_getMinuteToCall();// тест на получение времени до звонка будильника
    void test_stopwatch_1();// тест секундомера 1
    void test_stopwatch_2();// тест секундомера 2
    void test_media(); // тест музыки
};

#endif // ALARMTESTS_H
