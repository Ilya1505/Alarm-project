#ifndef CHOISEMUSIC_H
#define CHOISEMUSIC_H

#include <QDialog>

namespace Ui {
class ChoiseMusic;
}

class ChoiseMusic : public QDialog
{
    Q_OBJECT

public:
    explicit ChoiseMusic(QWidget *parent = nullptr);
    ~ChoiseMusic();

private:
    Ui::ChoiseMusic *ui;
};

#endif // CHOISEMUSIC_H
