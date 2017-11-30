#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "product.h"
#include <QMessageBox>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ab =Product(1,"Adam","Backe",1,200);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    QMessageBox test;

    test.setText(ab.ToString());
    test.exec();

}
