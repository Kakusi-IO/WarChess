#include "finallywindialog.h"
#include "ui_finallywindialog.h"

FinallyWinDialog::FinallyWinDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FinallyWinDialog)
{
    ui->setupUi(this);
//    victoryBGM=new QSound(":/audio/res/victory.wav");
//    victoryBGM->play();
}

FinallyWinDialog::~FinallyWinDialog()
{
    delete ui;
//    victoryBGM->stop();
//    delete victoryBGM;
}
