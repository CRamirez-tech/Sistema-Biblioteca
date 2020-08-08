#ifndef ALUMNODIALOG_H
#define ALUMNODIALOG_H

#include <QDialog>

namespace Ui {
class alumnoDialog;
}

class alumnoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit alumnoDialog(QWidget *parent = nullptr);
    ~alumnoDialog();

private:
    Ui::alumnoDialog *ui;
};

#endif // ALUMNODIALOG_H
