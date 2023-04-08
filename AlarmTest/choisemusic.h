#ifndef CHOISEMUSIC_H
#define CHOISEMUSIC_H

#include <QDialog>
#include <QList>
#include <QLabel>

namespace Ui {
class ChoiseMusic;
}

class ChoiseMusic : public QDialog
{
    Q_OBJECT
    friend class ChoiseMusicTests;
public:
    explicit ChoiseMusic(QWidget *parent = nullptr, int *indexTrack = nullptr);
    explicit ChoiseMusic(int *indexTrack);
    ~ChoiseMusic();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::ChoiseMusic *ui;
    QLabel* getLabel();
    QList<QPushButton*> getPushButtons();
    int *indexTrack;

};

#endif // CHOISEMUSIC_H
