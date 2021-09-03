#ifndef FIRSTLYWINDIALOG_H
#define FIRSTLYWINDIALOG_H

#include "includedLibs.h"
#include <QDialog>

namespace Ui {
class FirstlyWinDialog;
}

class FirstlyWinDialog : public QDialog
{
    Q_OBJECT
    friend class WindowController;
//    QSound *victoryBGM;
public:
    explicit FirstlyWinDialog(QWidget *parent = nullptr);
    ~FirstlyWinDialog();

private:
    Ui::FirstlyWinDialog *ui;
};

#endif // FIRSTLYWINDIALOG_H
