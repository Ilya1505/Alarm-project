#include "choisemusic.h"
#include "ui_choisemusic.h"

ChoiseMusic::ChoiseMusic(QWidget *parent, int *indexTrack) :
    QDialog(parent),
    ui(new Ui::ChoiseMusic)
{
    ui->setupUi(this);
    this->indexTrack = indexTrack;
}

ChoiseMusic::ChoiseMusic(int *indexTrack) : ui(new Ui::ChoiseMusic)
{
    ui->setupUi(this);
    this->indexTrack = indexTrack;
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

void ChoiseMusic::on_pushButton_clicked()
{
    indexTrack = 0;
    this->close();
}
// реализовать слоты для других кнопок
