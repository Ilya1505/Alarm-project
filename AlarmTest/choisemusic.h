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
    explicit ChoiseMusic(QWidget *parent = nullptr);
    ~ChoiseMusic();

private:
    Ui::ChoiseMusic *ui;
    QLabel* getLabel();
    QList<QPushButton*> getPushButtons();

};

#endif // CHOISEMUSIC_H
