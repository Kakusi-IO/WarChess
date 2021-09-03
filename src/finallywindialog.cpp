#include "finallywindialog.h"
#include "ui_finallywindialog.h"

FinallyWinDialog::FinallyWinDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FinallyWinDialog)
{
    ui->setupUi(this);
}

FinallyWinDialog::~FinallyWinDialog()
{
    delete ui;
}
