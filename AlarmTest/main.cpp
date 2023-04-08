#include "mainwindow.h"
#include "alarmtests.h"
#include "mainwindowtests.h"
#include "choisemusictests.h"
#include <QApplication>
#include <QtTest>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    freopen("test.log", "w", stdout);// открытие файла на запись тестов
    QTest::qExec(new AlarmTests, argc, argv);// выполнение тестов класса будильника
    QTest::qExec(new MainWindowTests, argc, argv);// выполнение тестов класса главного окна
    QTest::qExec(new ChoiseMusicTests, argc, argv);// выполнение тестов класса окна выбора мелодии
    return a.exec();
}
