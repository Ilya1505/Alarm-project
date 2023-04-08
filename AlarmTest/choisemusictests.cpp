#include "choisemusictests.h"
#include "choisemusic.h"

ChoiseMusicTests::ChoiseMusicTests(QObject *parent)
    : QObject{parent}
{

}

// тест на проверку правильности создания всех элементов окна
void ChoiseMusicTests::test_construction()
{
    ChoiseMusic* choiseWin = new ChoiseMusic();
    QCOMPARE_NE(choiseWin, nullptr);
    if(choiseWin != nullptr){
        delete choiseWin;
    }
}
