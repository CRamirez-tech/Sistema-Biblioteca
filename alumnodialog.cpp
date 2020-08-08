#include "alumnodialog.h"
#include "ui_alumnodialog.h"

alumnoDialog::alumnoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::alumnoDialog)
{
    ui->setupUi(this);
}

alumnoDialog::~alumnoDialog()
{
    delete ui;
}
