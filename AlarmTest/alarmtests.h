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
    void test_create();
};

#endif // ALARMTESTS_H
