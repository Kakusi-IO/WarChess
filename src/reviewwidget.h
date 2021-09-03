#ifndef REVIEWWIDGET_H
#define REVIEWWIDGET_H

#include <QWidget>

namespace Ui {
class ReviewWidget;
}

class ReviewWidget : public QWidget
{
    Q_OBJECT
    friend class WindowController;
    friend class GameController;
public:
    explicit ReviewWidget(QWidget *parent = nullptr);
    ~ReviewWidget();

private:
    Ui::ReviewWidget *ui;
};

#endif // REVIEWWIDGET_H
