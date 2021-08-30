#ifndef INITWINDOW_H
#define INITWINDOW_H

#include <QMainWindow>

class WindowController;

namespace Ui {
    class InitWindow;
}


class InitWindow : public QMainWindow
{
    Q_OBJECT

public:
    InitWindow(QWidget *parent = nullptr);
    ~InitWindow();

private:
    Ui::InitWindow *ui;
    friend class WindowController;
};
#endif // INITWINDOW_H
