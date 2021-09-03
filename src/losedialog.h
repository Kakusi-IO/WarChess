#ifndef LOSEDIALOG_H
#define LOSEDIALOG_H

#include <QDialog>

namespace Ui {
class LoseDialog;
}

class LoseDialog : public QDialog
{
    Q_OBJECT
    friend class WindowController;
public:
    explicit LoseDialog(QWidget *parent = nullptr);
    ~LoseDialog();

private:
    Ui::LoseDialog *ui;
};

#endif // LOSEDIALOG_H
