#include "choisemusic.h"
#include "ui_choisemusic.h"

ChoiseMusic::ChoiseMusic(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChoiseMusic)
{
    ui->setupUi(this);
}

ChoiseMusic::~ChoiseMusic()
{
    delete ui;
}
QLabel* ChoiseMusic::getLabel()
{
    return ui->label;
}
QList<QPushButton*> ChoiseMusic::getPushButtons()
{
    QList<QPushButton*> pushButtons = {
        ui->pushButton,
        ui->pushButton_2,
        ui->pushButton_3,
        ui->pushButton_4,
        ui->pushButton_5,
        ui->pushButton_6,
    };
    return pushButtons;
}
