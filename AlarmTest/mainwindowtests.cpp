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
    QCOMPARE(mainWin->getstopAlarmBut()->text(),"Остановить будильник через\n");


    QTest::mouseClick(mainWin->getStartAlarmBut(), Qt::LeftButton);
    QCOMPARE(mainWin->getStartAlarmBut()->text(),"Завести будильник");
    QCOMPARE(mainWin->getSetTimeAlarm()->isEnabled(), true);
    QCOMPARE(mainWin->getEditMusicBut()->isEnabled(), true);
    QCOMPARE(mainWin->getstopAlarmBut()->text(),"Остановить будильник");
    if(mainWin != nullptr){
        delete mainWin;
    }
}

// тест проверки кнопки старта/отмены будильника 3
void MainWindowTests::test_startAlarmBut_3()
{
    MainWindow* mainWin = new MainWindow();
    *mainWin->indexTrack = 4;
    QTest::mouseClick(mainWin->getStartAlarmBut(), Qt::LeftButton);
    QCOMPARE(mainWin->alarm->getCurrentTrack(), "source/Браво - Этот город самый лучший.mp3");
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
    QCOMPARE(mainWin->getstopAlarmBut()->isEnabled(), false);
    QCOMPARE(mainWin->getSetTimeAlarm()->isEnabled(), true);
    QCOMPARE(mainWin->getStartAlarmBut()->isEnabled(), true);
    QCOMPARE(mainWin->getEditMusicBut()->isEnabled(), true);

    if(mainWin != nullptr){
        delete mainWin;
    }
}

// тест таймера 1
void MainWindowTests::test_timer_1()
{
    MainWindow* mainWin = new MainWindow();

    QTest::mouseClick(mainWin->getStartAlarmBut(), Qt::LeftButton);

    QCOMPARE(mainWin->timer->isActive(), true);


    if(mainWin != nullptr){
        delete mainWin;
    }
}
// тест таймера 2
void MainWindowTests::test_timer_2()
{
    MainWindow* mainWin = new MainWindow();
    mainWin->getSetTimeAlarm()->setTime(QTime::currentTime());
    QTest::mouseClick(mainWin->getStartAlarmBut(), Qt::LeftButton);// запуск будильника
    QCOMPARE(mainWin->timer->isActive(), true);// проверка активации таймера
    mainWin->updateTime();// обновление будильника
    QCOMPARE(mainWin->timer->isActive(), false);// проверка остановки таймера
    QCOMPARE(mainWin->timerAfterCall->isActive(), true);// проверка запуска таймера после звонка
    QCOMPARE(mainWin->getstopAlarmBut()->text(),"Остановить будильник\n00:00");
    QTest::mouseClick(mainWin->getstopAlarmBut(), Qt::LeftButton);// остановка будильника
    if(mainWin != nullptr){
        delete mainWin;
    }
}

// тест таймера после звонка 1
void MainWindowTests::test_timerAfterCall_1()
{
    MainWindow* mainWin = new MainWindow();
    mainWin->getSetTimeAlarm()->setTime(QTime::currentTime());
    QTest::mouseClick(mainWin->getStartAlarmBut(), Qt::LeftButton);// запуск будильника
    mainWin->updateTime();// обновление будильника
    QCOMPARE(mainWin->timerAfterCall->isActive(), true);// проверка запуска таймера после звонка
    mainWin->updateTimeAfterCall();
    QCOMPARE(mainWin->getstopAlarmBut()->text(),"Остановить будильник\n- 0 мин 1 сек");
    mainWin->updateTimeAfterCall();
    QCOMPARE(mainWin->getstopAlarmBut()->text(),"Остановить будильник\n- 0 мин 2 сек");
    QTest::mouseClick(mainWin->getstopAlarmBut(), Qt::LeftButton);// остановка будильника
    if(mainWin != nullptr){
        delete mainWin;
    }
}

// тест таймера после звонка 2
void MainWindowTests::test_timerAfterCall_2()
{
    MainWindow* mainWin = new MainWindow();
    mainWin->getSetTimeAlarm()->setTime(QTime::currentTime());
    QTest::mouseClick(mainWin->getStartAlarmBut(), Qt::LeftButton);// запуск будильника
    mainWin->updateTime();// обновление будильника
    for(size_t i = 0; i < 60; i++) {
        mainWin->updateTimeAfterCall();
    }
    QCOMPARE(mainWin->getstopAlarmBut()->text(),"Остановить будильник\n- 1 мин 0 сек");
    QTest::mouseClick(mainWin->getstopAlarmBut(), Qt::LeftButton);// остановка будильника
    if(mainWin != nullptr){
        delete mainWin;
    }
}
