#ifndef WINDOWCONTROLLER_H
#define WINDOWCONTROLLER_H

#include "initwindow.h"
#include "gamewindow.h"
#include "gamecontroller.h"
#include "pausedialog.h"
#include "losedialog.h"
#include "includedLibs.h"
#include "firstlywindialog.h"
#include "finallywindialog.h"
#include "reviewwidget.h"
#include <QMainWindow>
#include <QObject>

class WindowController : public QObject
{
    Q_OBJECT
    InitWindow* initWindow;
    GameWindow* gameWindow;
    PauseDialog* pauseDialog;
    LoseDialog* loseDialog;
    FirstlyWinDialog* firstlyWinDialog;
    FinallyWinDialog* finallyWinDialog;
    ReviewWidget* reviewWidget;

    QSignalMapper* mapper;



public:
    WindowController();
    ~WindowController();
public slots:
    void requestForReview();
private:
    void connectSignalsAndSlots();

signals:

};

#endif // WINDOWCONTROLLER_H
