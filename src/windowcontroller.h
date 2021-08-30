#ifndef WINDOWCONTROLLER_H
#define WINDOWCONTROLLER_H

#include "initwindow.h"
#include "gamewindow.h"
#include <QMainWindow>
#include <QObject>

class WindowController : public QObject
{
    Q_OBJECT

public:
    InitWindow* initWindow;
    GameWindow* gameWindow;

public:
    WindowController();
    ~WindowController();
private:
    void connectSignalsAndSlots();

signals:

};

#endif // WINDOWCONTROLLER_H
