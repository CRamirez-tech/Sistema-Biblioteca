#ifndef ADMINDIALOG_H
#define ADMINDIALOG_H

#include <QDialog>
#include <QSqlTableModel>

namespace Ui {
class adminDialog;
}

class adminDialog : public QDialog
{
    Q_OBJECT
public:
    explicit adminDialog(QWidget *parent = nullptr);
    ~adminDialog();
private slots:
    void on_tabWidget_currentChanged(int index);

    void on_pushButton_2_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

    void on_lineEdit_9_textChanged(const QString &arg1);

    void on_lineEdit_10_textChanged(const QString &arg1);

    void on_lineEdit_11_textChanged(const QString &arg1);

    void on_pushButton_12_clicked();

private:
    Ui::adminDialog *ui;
    QSqlTableModel* model;
    void initParts();
};

#endif // ADMINDIALOG_H
