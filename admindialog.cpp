#include "admindialog.h"
#include "ui_admindialog.h"
#include "vistalibro.h"

#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>

adminDialog::adminDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminDialog)
{
    ui->setupUi(this);
    initParts();
}

adminDialog::~adminDialog()
{
    delete ui;
}
void adminDialog::initParts(){
    model = new QSqlTableModel(this);
    model->setTable("libro");
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->setDragEnabled(false);

    model = new QSqlTableModel(this);
    model->setTable("usuario");
    model->select();
    ui->tableView_2->setModel(model);
    ui->tableView_2->hideColumn(0);
    ui->tableView_2->hideColumn(1);

    QStringList list;
    QSqlQuery query;
    ui->comboBox->addItems(list);
}
void adminDialog::on_tabWidget_currentChanged(int index)
{
    QSqlQuery query;
    switch (index) {
    case 0:
        model = new QSqlTableModel(this);
        model->setTable("libro");
        model->select();
        ui->tableView->setModel(model);
        break;
    case 1:
        model = new QSqlTableModel(this);
        model->setTable("usuario");
        model->select();
        ui->tableView_2->setModel(model);
        ui->tableView_2->hideColumn(0);
        ui->tableView_2->hideColumn(1);
        break;
    case 2:

        break;
    }
}

void adminDialog::on_pushButton_2_clicked()
{
    vistaLibro g(this);
    g.exec();
    model->setTable("libro");
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->update();
}

void adminDialog::on_lineEdit_textChanged(const QString &arg1)
{

    model->setTable("libro");
    if(arg1 != ""){
        model->setFilter("titulo='"+arg1+"'");
    }
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->update();
}

void adminDialog::on_lineEdit_2_textChanged(const QString &arg1)
{
    model->setTable("libro");
    if(arg1 != ""){
        model->setFilter("autor='"+arg1+"'");
    }
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->update();
}

void adminDialog::on_pushButton_4_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,
                                  "Verifique su decisión",
                                  "Realmente desea eliminar los libros seleccionados.",
                                  QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::Yes) {
          QModelIndexList indexes = ui->tableView->selectionModel()->selection().indexes();
          for (int i = 0; i < indexes.count(); ++i)
          {
              QModelIndex index = indexes.at(i);
              model->removeRow(index.row());
          }
          model->select();
          ui->tableView->setModel(model);
          ui->tableView->update();
      }
}

void adminDialog::on_pushButton_7_clicked()
{
    model->setTable("libro");
    QString arg1 = ui->comboBox_2->currentText();
    qDebug()<<arg1<<"puntuacion="+arg1;
    if(arg1 != ""){
        model->setFilter("puntuacion="+arg1);
    }
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->update();
}

void adminDialog::on_lineEdit_9_textChanged(const QString &arg1)
{
}

void adminDialog::on_lineEdit_10_textChanged(const QString &arg1)
{

}

void adminDialog::on_lineEdit_11_textChanged(const QString &arg1)
{

}

void adminDialog::on_pushButton_12_clicked()
{

}
