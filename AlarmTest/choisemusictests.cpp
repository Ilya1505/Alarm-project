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
    QList<QPushButton*> pushButons = choiseWin->getPushButtons();
    foreach (auto button, pushButons) {
        QVERIFY2(button, "pushButton not created");
    }

    if(choiseWin != nullptr){
        delete choiseWin;
    }
}
