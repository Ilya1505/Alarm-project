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
    void test_update_1();// тест на обновление будильника по тику таймера 1
    void test_update_2();// тест на обновление будильника по тику таймера 2
    void test_stop_1();// тест на остановку будильника 1
    void test_stop_2();// тест на остановку будильника 2
    void test_getMinuteToCall();// тест на получение времени до звонка будильника
    void test_stopwatch_1();// тест секундомера 1
    void test_stopwatch_2();// тест секундомера 2
    void test_media_1(); // тест на правильность пути до медиа
    void test_media_2(); // тест на запуск медиа 2
    void test_media_3(); // тест на запуск медиа 3
    void test_media_4(); // тест на остановку медиа 4
};

#endif // ALARMTESTS_H
