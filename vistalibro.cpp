#include "vistalibro.h"
#include "ui_vistalibro.h"
#include <QSqlQuery>
#include <QDebug>

vistaLibro::vistaLibro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::vistaLibro)
{
    ui->setupUi(this);
}

vistaLibro::~vistaLibro()
{
    delete ui;
}

void vistaLibro::on_pushButton_clicked()
{
    QString par1 = ui->lineEdit_1->text();
    QString par2 = ui->lineEdit_2->text();
    QString par3 = ui->lineEdit_3->text();
    //QString par4 = ui->lineEdit_4->text();
    //int par4i=1;
    //QString par5 = ui->lineEdit_5->text();
    //int par5i=0;
    QString par6 = ui->lineEdit_6->text();
    QSqlQuery query;
    qDebug()<<query.exec("INSERT INTO libro(titulo,autor,genero,disponible,descripcion,puntuacion) VALUES ('"+par1+"','"+par2+"','"+par3+"',1,'"+par6+"',0)");
    qDebug()<<query.lastQuery();
    this->close();
}
