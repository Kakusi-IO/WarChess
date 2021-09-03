#include "firstlywindialog.h"
#include "ui_firstlywindialog.h"

FirstlyWinDialog::FirstlyWinDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FirstlyWinDialog)
{
    ui->setupUi(this);
}

FirstlyWinDialog::~FirstlyWinDialog()
{
    delete ui;
}
