#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    storage = Storage(10);
    productregister = ProductRegister(3, &storage);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    QMessageBox test;

    productregister.addProductToRegister(1,"Köttbullar","Felix",200,300,10);
    productregister.addProductToRegister(2,"Makaroner","Barilla",200,400,10);
    test.setText(productregister.toString());
    test.exec();

}
