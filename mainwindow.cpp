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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Product ab(1,"Adam","Backe",1,200);

    QMessageBox test;

    test.setText(ab.getLev());
    QTextStream(stdout) << ab.getName() << endl;
    test.exec();

}
