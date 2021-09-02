#include "pausedialog.h"
#include "ui_pausedialog.h"

PauseDialog::PauseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PauseDialog)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
}

PauseDialog::~PauseDialog()
{
    delete ui;
}
