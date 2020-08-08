#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "alumnodialog.h"
#include "admindialog.h"

#include <QtSql>
#include <QMessageBox>
#include <QSqlDatabase>

MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    if (!QSqlDatabase::drivers().contains("QSQLITE")){
            QMessageBox::critical(
                        nullptr,
                        "No cargo la base de datos.",
                        "No se encuentra el driver de dase de datos."
                        );
    }
    QSqlDatabase bd = QSqlDatabase::addDatabase("QSQLITE");
    bd.setDatabaseName("./core.sqlite");
    if(!bd.open()){
        QMessageBox::critical(nullptr,
                              "Error al abrir la base de datos",
                              bd.lastError().text());
    }
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS usuario (dni INTEGER NOT NULL PRIMARY KEY, contrasenia VARCHAR(255) NOT NULL, nombre VARCHAR(255) NOT NULL, apellidos VARCHAR(255) NOT NULL, fecha_de_creacion VARCHAR(10) NOT NULL DEFAULT '1999-01-01', rango INT NOT NULL);");
    query.exec("CREATE TABLE IF NOT EXISTS libro (titulo VARCHAR(255) NOT NULL, autor VARCHAR(255) NOT NULL, genero VARCHAR(255) NOT NULL, disponible BOOL NOT NULL DEFAULT TRUE, descripcion VARCHAR(255), puntuacion INT NOT NULL)");
    query.exec("CREATE TABLE IF NOT EXISTS pedido (idUsuario INTEGER NOT NULL, idLibro INTEGER NOT NULL, fecha_de_prestamo VARCHAR(10) NOT NULL, fecha_de_devolucion VARCHAR(255), FOREIGN KEY (idUsuario) REFERENCES usuario(id), FOREIGN KEY (idLibro) REFERENCES libro(id))");
    query.exec("CREATE TABLE IF NOT EXISTS penalizacion (idUsuario INTEGER NOT NULL, idLibro INTEGER NOT NULL, fecha_de_castigo VARCHAR(10) NOT NULL, FOREIGN KEY (idUsuario) REFERENCES usuario(id), FOREIGN KEY (idLibro) REFERENCES libro(id))");
    query.exec("INSERT INTO usuario(dni,contrasenia,nombre,apellidos,fecha_de_creacion,rango) VALUES(74859975,'36388794be2cf5f298978498ff3c64a2','Cristhian Jevinson','Ramirez Machaca','01-08-2020',3)");
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_clicked()
{
    adminDialog g(this);
    this->close();
    g.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    alumnoDialog g(this);
    this->close();
    g.exec();
}
//https://www.youtube.com/watch?v=FJMq1Exy-iE
