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
    QLabel* statusLabel;

    void setStatusLabel(const QString&);
    void setInfoLabel(const QString&);
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
private:

    Ui::GameWindow *ui;

signals:

    void newChessAdded();

public slots:
    void callUpdate();
};

#endif // GAMEWINDOW_H
