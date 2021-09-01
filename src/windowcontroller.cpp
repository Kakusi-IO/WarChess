#include "gamewindow.h"
#include "initwindow.h"
#include "windowcontroller.h"

// 一定要包括ui_xxx.h，否则会报错
#include "ui_initwindow.h"
#include "ui_gamewindow.h"

void WindowController::connectSignalsAndSlots()
{
    connect(initWindow->ui->startBtn,SIGNAL(clicked()),gameWindow,SLOT(show()));
    connect(gameWindow,SIGNAL(newChessAdded()),gameWindow,SLOT(on_newChessAdded()));
}

WindowController::WindowController()
{
    gameWindow=new GameWindow();
    initWindow=new InitWindow();
    connectSignalsAndSlots();
    initWindow->show();
}

WindowController::~WindowController()
{
    delete initWindow;
    delete gameWindow;
}
