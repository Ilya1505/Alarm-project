#include "mainwindowtests.h"
#include "mainwindow.h"
#include "QLabel"
#include "QPushButton"
#include "QTimeEdit"
MainWindowTests::MainWindowTests(QObject *parent)
    : QObject{parent}
{

}

// тест на проверка правильности создания всех элементов окна
void MainWindowTests::test_construction()
{
    MainWindow* mainWin = new MainWindow();
    QVERIFY2(mainWin->getStartAlarmBut(), "Push button StartBut not created");
    QVERIFY2(mainWin->getSetTimeAlarm(), "QTimeEdit SetTimeAlarm not created");
    QVERIFY2(mainWin->getTimeLabel(), "Label TimeLabel not created");
    QVERIFY2(mainWin->getEditMusicBut(), "Push button EditMusicBut not created");
    QVERIFY2(mainWin->getstopAlarmBut(), "Push button StopAlarmBut not created");

    if(mainWin != nullptr){
        delete mainWin;
    }
}

// тест проверки кнопки старта/отмены будильника 1
void MainWindowTests::test_startAlarmBut_1()
{
    MainWindow* mainWin = new MainWindow();

    QCOMPARE(mainWin->getStartAlarmBut()->text(),"Завести будильник");

    if(mainWin != nullptr){
        delete mainWin;
    }
}

// тест проверки кнопки старта/отмены будильника 2
void MainWindowTests::test_startAlarmBut_2()
{
    MainWindow* mainWin = new MainWindow();

    QTest::mouseClick(mainWin->getStartAlarmBut(), Qt::LeftButton);
    QCOMPARE(mainWin->getStartAlarmBut()->text(),"Отменить будильник");

    QTest::mouseClick(mainWin->getStartAlarmBut(), Qt::LeftButton);
    QCOMPARE(mainWin->getStartAlarmBut()->text(),"Завести будильник");

    if(mainWin != nullptr){
        delete mainWin;
    }
}
