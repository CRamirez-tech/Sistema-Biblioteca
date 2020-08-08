#ifndef VISTALIBRO_H
#define VISTALIBRO_H

#include <QDialog>

namespace Ui {
class vistaLibro;
}

class vistaLibro : public QDialog
{
    Q_OBJECT

public:
    explicit vistaLibro(QWidget *parent = nullptr);
    ~vistaLibro();

private slots:
    void on_pushButton_clicked();

private:
    Ui::vistaLibro *ui;
};

#endif // VISTALIBRO_H
