#include "gamewindow.h"
#include "ui_gamewindow.h"


GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    ui->infoLabel->setText("欢迎来到英雄战旗!");

    //初始化状态栏
    hintLabel=new QLabel(this);
    gameController=new GameController(this);
    hintLabel->setText("按下右键以放置 祖安狂人");
    ui->statusbar->addWidget(hintLabel);
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    //初始化地图
    painter.setPen(Qt::black);
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            QBrush brush(gameController->colorsOfMap[gameController->currentStage][5*i+j],Qt::CrossPattern);
            painter.setBrush(brush);
            QRect rect(50+100*j,50+100*i,100,100);
            painter.drawRect(rect);
        }
    }

    //绘制棋子
    for(int i=0;i<gameController->blueTeamChesses.length();++i)
    {
        Chess* chess=gameController->blueTeamChesses[i];
        if(chess->alive)
        {
            int x=100*chess->index().x+50;
            int y=100*chess->index().y+50;
            painter.drawPixmap(x,y,100,100,QPixmap(chess->pixmapPath));
        }
    }
}

void GameWindow::mousePressEvent(QMouseEvent *event)
{
    Index mousePressIndex=Index::pointToIndex(QPoint(event->x(),event->y()));
    if(event->button()==Qt::RightButton)
    {
        if(!mousePressIndex.isValid()||gameController->chessesHasSetted >= gameController->chessesPerStage[gameController->currentStage])
        {
            return;
        }
        Chess* newChess;
        switch(gameController->chessesHasSetted)
        {
        case 0:
            newChess=new TankChess(mousePressIndex);
            hintLabel->setText("按下右键以放置 德玛西亚之翼");
            break;
        case 1:
            newChess=new AssassinChess(mousePressIndex);
            hintLabel->setText("按下右键以放置 皮城女警");
            break;
        case 2:
            newChess=new ArcherChess(mousePressIndex);
            hintLabel->setText("按下右键以放置 寒冰射手");
        default:
            newChess=new ArcherChess(mousePressIndex);
            hintLabel->setText("");
            break;
        }
        gameController->addChess(newChess);
        update();
        gameController->chessesHasSetted++;
    }
}

void GameWindow::on_newChessAdded()
{
    update();
}
