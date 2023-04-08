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
