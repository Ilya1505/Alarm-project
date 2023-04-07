#include "mainwindowtests.h"
#include "mainwindow.h"
#include "QLabel"
#include "QPushButton"
#include "QTimeEdit"
#include "QTime"
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
    QCOMPARE(mainWin->getSetTimeAlarm()->isEnabled(), false);
    QCOMPARE(mainWin->getEditMusicBut()->isEnabled(), false);
    QCOMPARE(mainWin->getstopAlarmBut()->text(),"Остановить будильник\n");


    QTest::mouseClick(mainWin->getStartAlarmBut(), Qt::LeftButton);
    QCOMPARE(mainWin->getStartAlarmBut()->text(),"Завести будильник");
    QCOMPARE(mainWin->getSetTimeAlarm()->isEnabled(), true);
    QCOMPARE(mainWin->getEditMusicBut()->isEnabled(), true);
    QCOMPARE(mainWin->getstopAlarmBut()->text(),"Остановить будильник");
    if(mainWin != nullptr){
        delete mainWin;
    }
}

// тест на проверку обновления по тику таймера 1
void MainWindowTests::test_update_1()
{
    MainWindow* mainWin = new MainWindow();
    mainWin->updateTime();
    QCOMPARE(mainWin->getTimeLabel()->text(), QTime::currentTime().toString("HH:mm:ss"));

    if(mainWin != nullptr){
        delete mainWin;
    }
}

// тест проверки кнопки остановки будильника 1
void MainWindowTests::test_stopAlarmBut_1()
{
    MainWindow* mainWin = new MainWindow();

    mainWin->getstopAlarmBut()->setEnabled(true);
    QTest::mouseClick(mainWin->getStartAlarmBut(), Qt::LeftButton);
    QTest::mouseClick(mainWin->getstopAlarmBut(), Qt::LeftButton);
    QCOMPARE(mainWin->getStartAlarmBut()->text(), "Завести будильник");
    QCOMPARE(mainWin->getstopAlarmBut()->text(), "Остановить будильник");

    if(mainWin != nullptr){
        delete mainWin;
    }
}
