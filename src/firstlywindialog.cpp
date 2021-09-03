#include "firstlywindialog.h"
#include "ui_firstlywindialog.h"

FirstlyWinDialog::FirstlyWinDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FirstlyWinDialog)
{
    ui->setupUi(this);
//    victoryBGM=new QSound(":/audio/res/victory.wav");
//    victoryBGM->play();
}

FirstlyWinDialog::~FirstlyWinDialog()
{
    delete ui;
//    victoryBGM->stop();
//    delete victoryBGM;
}
