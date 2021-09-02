#include "initwindow.h"
#include "ui_initwindow.h"

InitWindow::InitWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::InitWindow)
{
    ui->setupUi(this);
}

InitWindow::~InitWindow()
{
    delete ui;
}

void InitWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.drawPixmap(0,0,800,600,QPixmap(":/pixmap/res/Classic_Garen_Splash.jpg"));
}

