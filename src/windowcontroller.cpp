#include "gamewindow.h"
#include "initwindow.h"
#include "windowcontroller.h"

// 一定要包括ui_xxx.h，否则会报错
#include "ui_initwindow.h"
#include "ui_gamewindow.h"
#include "ui_pausedialog.h"
#include "ui_losedialog.h"
#include "ui_firstlywindialog.h"
#include "ui_finallywindialog.h"

void WindowController::connectSignalsAndSlots()
{
    connect(initWindow->ui->startBtn,SIGNAL(clicked()),gameWindow,SLOT(show()));
    connect(gameWindow,SIGNAL(newChessAdded()),gameWindow,SLOT(callUpdate()));
    connect(gameWindow->gameController,SIGNAL(someoneDead()),gameWindow,SLOT(callUpdate()));
    connect(gameWindow,SIGNAL(keyEscPressed()),pauseDialog,SLOT(exec()));

    connect(pauseDialog->ui->toInitBtn,SIGNAL(clicked()),gameWindow,SLOT(close()));
    connect(pauseDialog->ui->toInitBtn,SIGNAL(clicked()),initWindow,SLOT(show()));
    connect(pauseDialog->ui->exitBtn,SIGNAL(clicked()),gameWindow,SLOT(close()));

    connect(gameWindow,SIGNAL(lost()),loseDialog,SLOT(exec()));
    connect(loseDialog->ui->toInitBtn,SIGNAL(clicked()),gameWindow,SLOT(close()));
    connect(loseDialog->ui->toInitBtn,SIGNAL(clicked()),initWindow,SLOT(show()));
    connect(loseDialog->ui->exitBtn,SIGNAL(clicked()),gameWindow,SLOT(close()));
    connect(loseDialog->ui->restartBtn,SIGNAL(clicked()),gameWindow,SLOT(restart()));

    connect(gameWindow,SIGNAL(firstlyWin()),firstlyWinDialog,SLOT(exec()));
    connect(firstlyWinDialog->ui->toInitBtn,SIGNAL(clicked()),gameWindow,SLOT(close()));
    connect(firstlyWinDialog->ui->toInitBtn,SIGNAL(clicked()),initWindow,SLOT(show()));
    connect(firstlyWinDialog->ui->exitBtn,SIGNAL(clicked()),gameWindow,SLOT(close()));
    connect(firstlyWinDialog->ui->restartBtn,SIGNAL(clicked()),gameWindow,SLOT(restart()));
    connect(firstlyWinDialog->ui->toNextBtn,SIGNAL(clicked()),mapper,SLOT(map()));
    mapper->setMapping(firstlyWinDialog->ui->toNextBtn,1);

    connect(gameWindow,SIGNAL(finallyWin()),finallyWinDialog,SLOT(exec()));
    connect(finallyWinDialog->ui->toInitBtn,SIGNAL(clicked()),gameWindow,SLOT(close()));
    connect(finallyWinDialog->ui->toInitBtn,SIGNAL(clicked()),initWindow,SLOT(show()));
    connect(finallyWinDialog->ui->exitBtn,SIGNAL(clicked()),gameWindow,SLOT(close()));
    connect(finallyWinDialog->ui->restartBtn,SIGNAL(clicked()),mapper,SLOT(map()));
    mapper->setMapping(finallyWinDialog->ui->restartBtn,1);
    connect(mapper,SIGNAL(mapped(int)),gameWindow,SLOT(restart(int)));
}

WindowController::WindowController()
{
    gameWindow=new GameWindow();
    initWindow=new InitWindow();
    pauseDialog=new PauseDialog();
    loseDialog=new LoseDialog();
    firstlyWinDialog=new FirstlyWinDialog();
    finallyWinDialog=new FinallyWinDialog();
    mapper=new QSignalMapper(this);
    connectSignalsAndSlots();
    initWindow->show();
//    setAttribute(Qt::WA_DeleteOnClose);
}

WindowController::~WindowController()
{
    delete initWindow;
    delete gameWindow;
    delete pauseDialog;
    delete loseDialog;
    delete firstlyWinDialog;
    delete finallyWinDialog;
}
