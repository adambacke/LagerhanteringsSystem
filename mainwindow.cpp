#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addproduct.h"
#include "removeproduct.h"
#include "handelorders.h"
#include "changenrofitems.h"

#include <QMessageBox>
#include <QTextStream>
#include <QFile>

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

void MainWindow::on_end_clicked()
{
    QFile productsFile("products.txt");

    if(productsFile.open(QFile::WriteOnly | QFile::Text))
    {
        QTextStream out (&productsFile);
        out << productregister.getCounter() << "\n";

        for(int i=0;i<productregister.getCounter();i++)
        {
            out << productregister.getProductIdNrOnPlace(i) << "\n";
            out << productregister.getNameOnPlace(i) << "\n";
            out << productregister.getLevOnPlace(i) << "\n";
            out << productregister.getNrOfItemsOnPlace(i) << "\n";
            out << productregister.getPricePerItemOnPlace(i) << "\n";
            out << storage.getStorageCapacityOnIndex(i) << "\n";
        }
    }


    productsFile.flush();
    productsFile.close();

    close();
}
