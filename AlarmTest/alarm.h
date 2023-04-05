#ifndef ALARM_H
#define ALARM_H
#include <QString>
#include "QTime"
#include "QHash"
#include <QMediaPlayer>
#include <QAudioOutput>

class Alarm
{
public:
    Alarm();
    ~Alarm();

    void setStatusGO(bool status);
    void setSecAfterCall(int sec);
    void setMinAfterCall(int min);
    void setTrack(int *indexTrack);

    bool getStatusGO();
    QString getCurrentTime();
    QString getCurrentTrack();
    QString getCallTime();
    QString getMinuteToCall(const QTime &timeCall);// вычисление времени до звонка
    QString timeAfterCall();// секундомер времени после звонка


    bool start(QString signalTime);// true - если запуск успешен, иначе - false
    bool update();// true - если звонок, иначе - false
    bool stop();// true - если остановка успешна, иначе - false

private:
    bool statusGO;// статус будильника: true - будильник взведен, иначе - false
    QString* currentTime;
    QString* сallTime;// время звонка
    QHash<int, QString> track;// словарь композиций
    QString currentTrack;// путь до выбранной композиции

    // секундомер после звонка будильника
    int secAfterCall;
    int minAfterCall;

    // объекты для работы с медиа
    QMediaPlayer *player;
    QAudioOutput *audioOutput;

};

#endif // ALARM_H
