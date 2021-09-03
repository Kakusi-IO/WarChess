#ifndef FINALLYWINDIALOG_H
#define FINALLYWINDIALOG_H

#include "includedLibs.h"
#include <QDialog>


namespace Ui {
class FinallyWinDialog;
}

class FinallyWinDialog : public QDialog
{
    Q_OBJECT
    friend class WindowController;
//    QSound *victoryBGM;
public:
    explicit FinallyWinDialog(QWidget *parent = nullptr);
    ~FinallyWinDialog();

private:
    Ui::FinallyWinDialog *ui;
};

#endif // FINALLYWINDIALOG_H
