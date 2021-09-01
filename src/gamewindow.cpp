#include "gamewindow.h"
#include "ui_gamewindow.h"


GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);

    //初始化状态栏
    chessInfo=new QLabel(this);
    chessInfo->setText("按下左键以查看战棋信息");
    ui->statusbar->addWidget(chessInfo);
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
    QColor colors[25]={
        Qt::yellow,Qt::green,Qt::black,Qt::green,Qt::green,
        Qt::green,Qt::yellow,Qt::green,Qt::green,Qt::green,
        Qt::green,Qt::green,Qt::yellow,Qt::green,Qt::green,
        Qt::green,Qt::green,Qt::green,Qt::yellow,Qt::green,
        Qt::green,Qt::green,Qt::black,Qt::green,Qt::yellow

    };
    painter.setPen(Qt::black);
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            QBrush brush(colors[5*i+j],Qt::CrossPattern);
            painter.setBrush(brush);
            QRect rect(50+100*j,50+100*i,100,100);
            painter.drawRect(rect);
        }
    }

    //todo: 下面这段代码有问题，即使是调用了clear也不行
    //绘制棋子
    gameController->blueTeamChesses.clear();
    for(int i=0;i<gameController->blueTeamChesses.size();++i)
    {
        Chess* chess=gameController->blueTeamChesses[i];
        int x=100*chess->index().x+50;
        int y=100*chess->index().y+50;
        painter.drawPixmap(x,y,100,100,QPixmap(chess->pixmapPath));
    }

}

void GameWindow::mousePressEvent(QMouseEvent *event)
{
    Index mousePressIndex=Index::pointToIndex(QPoint(event->x(),event->y()));
    if(event->button()==Qt::RightButton)
    {
        if(mousePressIndex.isValid())
        {
            Chess* newChess=new TankChess(mousePressIndex);
            gameController->addChess(newChess);
//            emit newChessAdded();
            update();
        }
    }
}

void GameWindow::on_newChessAdded()
{
    update();
}
