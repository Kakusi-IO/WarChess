#ifndef WINDOWCONTROLLER_H
#define WINDOWCONTROLLER_H

#include "initwindow.h"
#include "gamewindow.h"
#include "gamecontroller.h"
#include "pausedialog.h"
#include <QMainWindow>
#include <QObject>

class WindowController : public QObject
{
    Q_OBJECT
    InitWindow* initWindow;
    GameWindow* gameWindow;
    PauseDialog* pauseDialog;

public:
    WindowController();
    ~WindowController();
private:
    void connectSignalsAndSlots();

signals:

};

#endif // WINDOWCONTROLLER_H
