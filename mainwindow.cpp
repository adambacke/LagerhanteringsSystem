#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    storage(100),
    productregister(3, &storage),
    orders(3)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    QMessageBox test;
    bool retval;

    productregister.addProductToRegister(1,"Köttbullar","Felix",200,300,10);
    productregister.addProductToRegister(2,"Makaroner","Barilla",200,400,10);
    orders.addOrderToRegister(1,"Adam",2);
    retval = orders.addOrderLineTooOrder(1,1,20,productregister);
    retval = orders.addOrderLineTooOrder(1,2,40,productregister);
    test.setText(storage.toString());
    test.exec();

}
