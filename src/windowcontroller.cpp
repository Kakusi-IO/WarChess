#include "gamewindow.h"
#include "initwindow.h"
#include "windowcontroller.h"

// 一定要包括ui_xxx.h，否则会报错
#include "ui_initwindow.h"
#include "ui_gamewindow.h"

void WindowController::connectSignalsAndSlots()
{
    connect(initWindow->ui->startBtn,SIGNAL(clicked()),gameWindow,SLOT(show()));
}

WindowController::WindowController()
{

}

WindowController::~WindowController()
{
    delete initWindow;
    delete gameWindow;
}
