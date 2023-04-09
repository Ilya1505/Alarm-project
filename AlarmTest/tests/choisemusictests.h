#ifndef CHOISEMUSICTESTS_H
#define CHOISEMUSICTESTS_H

#include <QObject>
#include <QTest>

class ChoiseMusicTests : public QObject
{
    Q_OBJECT
public:
    explicit ChoiseMusicTests(QObject *parent = nullptr);

private slots:
    void test_construction();// тест на проверка правильности создания всех элементов окна
    void test_pushButtons();// тест проверки нажатия на кнопки

};

#endif // CHOISEMUSICTESTS_H
