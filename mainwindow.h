#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "ProductRegister.h"
#include "storage.h"
#include "OrderRegister.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_addProduct_clicked();

    void on_removeProduct_clicked();

    void on_addOrder_clicked();

    void on_handelOrders_clicked();

    void on_ShowAll_clicked();

    void on_Clear_clicked();

private:
    Ui::MainWindow *ui;
    Product ab;
    Storage storage;
    ProductRegister productregister;
    OrderRegister orders;
};

#endif // MAINWINDOW_H
