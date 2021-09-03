#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "includedLibs.h"
#include "chess.h"
#include "tankchess.h"
#include "assassinchess.h"
#include "archerchess.h"
#include "gamecontroller.h"
#include <QMainWindow>


class WindowController;
namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT
    friend class WindowController;

    GameController* gameController;
    QLabel *statusLabel;
    QLabel *tutorialLabel;
    void setStatusLabel(const QString&);
    void setInfoLabel(const QString&);
    void setTutorialLabel(const QString&);
    void keyPressed(int);
    void wait(unsigned int msec)
    {
        QTime _Timer = QTime::currentTime().addMSecs(msec);
        while( QTime::currentTime() < _Timer )
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();
    void gameStart();

protected:
    void paintEvent(QPaintEvent* event);
    void mousePressEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void closeEvent( QCloseEvent * event );
private:

    Ui::GameWindow *ui;

signals:
    void newChessAdded();
    void keyEscPressed();
    void firstlyWin();
    void finallyWin();
    void lost();

public slots:
    void callUpdate();
    void restart(int stage=0);
};

#endif // GAMEWINDOW_H
