#include "gamewindow.h"
#include "ui_gamewindow.h"


void GameWindow::setStatusLabel(const QString & status)
{
    statusLabel->setText(status);
}

void GameWindow::setInfoLabel(const QString & info)
{
    ui->infoLabel->setText(info);
}

void GameWindow::keyPressed(int key)
{
    gameController->moveChess(key);
    update();
}

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    setInfoLabel("欢迎来到英雄战旗!按下右键可以查看棋子信息。");

    //初始化状态栏
    statusLabel=new QLabel(this);
    gameController=new GameController(this);
    setStatusLabel("按下右键以放置 祖安狂人");
    ui->statusbar->addWidget(statusLabel);
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
            QBrush brush(gameController->colorsOfMaps[gameController->currentStage][5*i+j],Qt::CrossPattern);
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
    for(int i=0;i<gameController->redTeamChesses.length();++i)
    {
        Chess* chess=gameController->redTeamChesses[i];
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
    Chess* chess;

    if(event->button()==Qt::RightButton)
    {
        //查看棋子信息
        foreach(chess,gameController->blueTeamChesses)
        {
            if(chess->index()==mousePressIndex)
            {
                setInfoLabel(chess->info());
                return;
            }
        }
        foreach(chess,gameController->redTeamChesses)
        {
            if(chess->index()==mousePressIndex)
            {
                setInfoLabel(chess->info());
                return;
            }
        }

        //放置棋子
        if(!mousePressIndex.isValid() //位置超出地图
                ||gameController->chessesHasSetted == gameController->chessesPerStage[gameController->currentStage] //放置完毕
                ||gameController->colorsOfMaps[gameController->currentStage][5*mousePressIndex.y+mousePressIndex.x] == Qt::black //位置在阻挡地形上
                )
        {
            return;
        }

        Chess* newChess;
        switch(gameController->chessesHasSetted)
        {
        case 0: //放第一个
            newChess=new TankChess(mousePressIndex);
//            qDebug()<<newChess->metaObject()->className();
            setStatusLabel("按下右键以放置 德玛西亚之翼");
            break;
        case 1: //放第二个
            newChess=new AssassinChess(mousePressIndex);
            setStatusLabel("按下右键以放置 皮城女警");
            break;
        case 2: //放第三个
            newChess=new ArcherChess(mousePressIndex);
//            setStatusLabel("按下右键以放置 皮城女警");
            break;
//        default:
//            newChess=new ArcherChess(mousePressIndex);
//            setStatusLabel("");
//            break;
        }
        gameController->addChess(newChess);

        //如果用update()，不会显示女警头像，用repaint可以显示，但还是会卡死
        update();
        gameController->chessesHasSetted++;
        //qDebug()<<gameController->chessesHasSetted;

        if(gameController->chessesHasSetted == gameController->chessesPerStage[gameController->currentStage])
        {
            gameStart();
        }
    }

    //攻击
    if(event->button()==Qt::LeftButton)
    {
        foreach(chess,gameController->redTeamChesses)
        {
            if(chess->index()==mousePressIndex)
            {
                //选择到了攻击目标
                if(gameController->currentChess->distanceTo(*chess) > gameController->currentChess->attackDistance+0.01)
                {
                    setStatusLabel("攻击不到此目标，请重新选择");
                    return;
                }
                gameController->actAttack(gameController->currentChess,chess);
                gameController->attackActed=true;
                return;
            }
        }
    }
}

void GameWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_P)
    {
        //pass
        gameController->moved=true;
        return;
    }
    keyPressed(event->key());
}
void GameWindow::callUpdate()
{
    update();
}

void GameWindow::gameStart()
{
    while(!(gameController->hasLost()||gameController->hasWon()))
    {

        //蓝色方
        foreach(gameController->currentChess,gameController->blueTeamChesses)
        {
            //移动
            //qDebug()<<"进入第一个foreach";
            setStatusLabel("请移动 "+gameController->currentChess->chessName());
            gameController->moved=false;
            //走一步
            do
            {
                wait(500);
            }
            while(!gameController->moved);

            //如果是刺客，再走一步
            if(gameController->currentChess->metaObject()->className()==QString("AssassinChess"))
            {
                gameController->moved=false;
                do
                {
                    wait(500);
                }
                while(!gameController->moved);
            }

            qDebug()<<gameController->currentChess->chessName()<<" "
            <<gameController->currentChess->placeIndex.x<<" "<<gameController->currentChess->placeIndex.y;
            //攻击
            //走到了黄色地形，不能攻击
            if(gameController->colorsOfMaps
                    [gameController->currentStage]
                    [gameController->currentChess->index().x+gameController->currentChess->index().y*5] == Qt::yellow
                    )
            {
                setStatusLabel(gameController->currentChess->chessName()+" 移动到了黄色区域，此回合不能攻击");
                wait(2000);
                continue;
            }
            //无攻击目标
            if(!gameController->hasEnemyToAttack())
            {
                setStatusLabel(gameController->currentChess->chessName()+" 没有可选择的攻击目标");
                wait(2000);
                continue;
            }

            //有攻击目标
            setStatusLabel("为 "+gameController->currentChess->chessName()+" 选择攻击目标");
            gameController->attackActed=false;
            do
            {

                wait(500);
            }
            while(!gameController->attackActed);

        }
    }
    if(gameController->hasWon())
    {
        //todo
    }
    if(gameController->hasLost())
    {
        //todo
    }
}
