#include "gamewindow.h"
#include "initwindow.h"
#include "windowcontroller.h"

// 一定要包括ui_xxx.h，否则会报错
#include "ui_initwindow.h"
#include "ui_gamewindow.h"
#include "ui_pausedialog.h"

void WindowController::connectSignalsAndSlots()
{
    connect(initWindow->ui->startBtn,SIGNAL(clicked()),gameWindow,SLOT(show()));
    connect(gameWindow,SIGNAL(newChessAdded()),gameWindow,SLOT(callUpdate()));
    connect(gameWindow->gameController,SIGNAL(someoneDead()),gameWindow,SLOT(callUpdate()));
    connect(gameWindow,SIGNAL(keyEscPressed()),pauseDialog,SLOT(exec()));
    connect(pauseDialog->ui->toInitBtn,SIGNAL(clicked()),gameWindow,SLOT(close()));
    connect(pauseDialog->ui->toInitBtn,SIGNAL(clicked()),initWindow,SLOT(show()));
    connect(pauseDialog->ui->exitBtn,SIGNAL(clicked()),gameWindow,SLOT(close()));
}

WindowController::WindowController()
{
    gameWindow=new GameWindow();
    initWindow=new InitWindow();
    pauseDialog=new PauseDialog();
    connectSignalsAndSlots();
    initWindow->show();
//    setAttribute(Qt::WA_DeleteOnClose);
}

WindowController::~WindowController()
{
    delete initWindow;
    delete gameWindow;
    delete pauseDialog;
}
