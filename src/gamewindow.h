#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
class WindowController;
namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

private:
    Ui::GameWindow *ui;
    friend class WindowController;
};

#endif // GAMEWINDOW_H
