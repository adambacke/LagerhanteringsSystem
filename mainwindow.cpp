#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addproduct.h"
#include "removeproduct.h"
#include "handelorders.h"
#include "changenrofitems.h"

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

    //QMessageBox test;
    //bool retval;

    productregister.addProductToRegister(1,"Köttbullar","Felix",200,300,10);
    productregister.addProductToRegister(2,"Makaroner","Barilla",200,400,10);
    productregister.addProductToRegister(3,"Ketchup","Felix",100,150,30);
    //orders.addOrderToRegister(1,"Adam",2);
    //retval = orders.addOrderLineTooOrder(1,1,20,productregister);
    //retval = orders.addOrderLineTooOrder(1,2,40,productregister);
    //retval = productregister.removeProductFromRegister(1,storage);
    //test.setText(productregister.toString());
    //test.exec();

}

void MainWindow::on_addProduct_clicked()
{
    AddProduct addProduct(&storage,&productregister);
    addProduct.setModal(true);
    addProduct.exec();
}

void MainWindow::on_removeProduct_clicked()
{
    removeProduct removeproduct(&storage,&productregister);
    removeproduct.setModal(true);
    removeproduct.exec();
}

void MainWindow::on_addOrder_clicked()
{
    changeNrOfItems change(&storage,&productregister,&orders);
    change.setModal(true);
    change.exec();
}

void MainWindow::on_handelOrders_clicked()
{
    handelOrders handelorders(&storage,&productregister,&orders);
    handelorders.setModal(true);
    handelorders.exec();
}

void MainWindow::on_ShowAll_clicked()
{
    ui->showAllProducts->setText(productregister.toString());
}

void MainWindow::on_Clear_clicked()
{
    ui->showAllProducts->clear();
}
