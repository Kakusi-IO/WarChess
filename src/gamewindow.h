#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "includedLibs.h"
#include "chess.h"
#include "tankchess.h"
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
    QLabel* chessInfo;

public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();
protected:
    void paintEvent(QPaintEvent* event);
    void mousePressEvent(QMouseEvent *event);

private:

    Ui::GameWindow *ui;
signals:
    void newChessAdded();
public slots:
    void on_newChessAdded();
};

#endif // GAMEWINDOW_H
