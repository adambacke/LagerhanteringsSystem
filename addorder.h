#ifndef ADDORDER_H
#define ADDORDER_H

#include <QDialog>

#include "storage.h"
#include "ProductRegister.h"
#include "OrderRegister.h"

namespace Ui {
class AddOrder;
}

class AddOrder : public QDialog
{
    Q_OBJECT

public:
    explicit AddOrder(Storage* storage,ProductRegister* productRegister, OrderRegister* orders, QWidget *parent = 0);
    ~AddOrder();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AddOrder *ui;
    Storage* storage;
    ProductRegister* productRegister;
    OrderRegister* orders;
};

#endif // ADDORDER_H
