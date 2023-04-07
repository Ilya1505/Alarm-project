#ifndef MAINWINDOWTESTS_H
#define MAINWINDOWTESTS_H

#include <QObject>
#include <QTest>


class MainWindowTests : public QObject
{
    Q_OBJECT
public:
    explicit MainWindowTests(QObject *parent = nullptr);

private slots:
    void test_construction();// тест на проверка правильности создания всех элементов окна
    void test_startAlarmBut_1();// тест проверки кнопки старта/отмены будильника 1
    void test_startAlarmBut_2();// тест проверки кнопки старта/отмены будильника 2

};

#endif // MAINWINDOWTESTS_H