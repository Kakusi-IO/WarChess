#ifndef FINALLYWINDIALOG_H
#define FINALLYWINDIALOG_H

#include <QDialog>

namespace Ui {
class FinallyWinDialog;
}

class FinallyWinDialog : public QDialog
{
    Q_OBJECT
    friend class WindowController;
public:
    explicit FinallyWinDialog(QWidget *parent = nullptr);
    ~FinallyWinDialog();

private:
    Ui::FinallyWinDialog *ui;
};

#endif // FINALLYWINDIALOG_H
