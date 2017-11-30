#include "mainwindow.h"
#include "ui_mainwindow.h"

//#include "ProductRegister.h"
//#include "storage.h"

#include <QMessageBox>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ab =Product(1,"Adam","Backe",1,200);
    ProductRegister test2 (3);
    //test2.addProductToRegister(1,"Adam","Backe",1,200);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    QMessageBox test;

    test2.addProductToRegister(1,"Köttbullar","Felix",1,200);
    test2.addProductToRegister(2,"Makaroner","Barilla",2,200);
    test.setText(test2.toString());
    test.exec();

}
