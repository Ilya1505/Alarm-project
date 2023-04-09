#include "choisemusictests.h"
#include "choisemusic.h"
#include "QLabel"
#include "QPushButton"
#include <QList>
ChoiseMusicTests::ChoiseMusicTests(QObject *parent)
    : QObject{parent}
{

}

// тест на проверку правильности создания всех элементов окна
void ChoiseMusicTests::test_construction()
{
    ChoiseMusic* choiseWin = new ChoiseMusic();
    QCOMPARE_NE(choiseWin, nullptr);
    QVERIFY2(choiseWin->getLabel(), "Label not created");
    QList<QPushButton*> pushButtons = choiseWin->getPushButtons();
    QCOMPARE(pushButtons.size(), 6);
    foreach (auto button, pushButtons) {
        QVERIFY2(button, "pushButton not created");
    }

    if(choiseWin != nullptr){
        delete choiseWin;
    }
}

// тест проверки нажатия на кнопки
void ChoiseMusicTests::test_pushButtons()
{
    //todo реализовать данный тест позже для всех кнопок
    int* index = new int(0);
    ChoiseMusic* choiseWin = new ChoiseMusic(index);
    QList<QPushButton*> pushButtons = choiseWin->getPushButtons();// получаем массив кнопок
    for (size_t i = 0; i < pushButtons.size(); i++) {
        choiseWin->show();
        QTest::mouseClick(pushButtons[i], Qt::LeftButton);// нажатие на i кнопку
        if(i != pushButtons.size()-1){
            QCOMPARE(*index, i);
        }
        QCOMPARE(choiseWin->isHidden(), true);
    }
    if(choiseWin != nullptr){
        delete choiseWin;
    }
    if(index != nullptr){
        delete index;
    }
}
