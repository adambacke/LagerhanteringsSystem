#ifndef HANDELORDERS_H
#define HANDELORDERS_H

#include <QDialog>
#include "storage.h"
#include "ProductRegister.h"
#include "OrderRegister.h"

namespace Ui {
class handelOrders;
}

class handelOrders : public QDialog
{
    Q_OBJECT

public:
    explicit handelOrders(Storage* storage,ProductRegister* productregister, OrderRegister* orders, QWidget *parent = 0);
    ~handelOrders();

private slots:
    void on_ShowOrder_clicked();

    void on_clear_clicked();

    void on_createOrder_clicked();

    void on_addOrderLine_clicked();

    void on_Goback_clicked();

private:
    Ui::handelOrders *ui;
    Product* ab;
    Storage* storage;
    ProductRegister* productregister;
    OrderRegister* orders;

};

#endif // HANDELORDERS_H
