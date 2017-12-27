#ifndef CHANGENROFITEMS_H
#define CHANGENROFITEMS_H

#include <QDialog>
#include "storage.h"
#include "ProductRegister.h"
#include "OrderRegister.h"

namespace Ui {
class changeNrOfItems;
}

class changeNrOfItems : public QDialog
{
    Q_OBJECT

public:
    explicit changeNrOfItems(Storage* storage,ProductRegister* productregister, OrderRegister* orders, QWidget *parent = 0);
    ~changeNrOfItems();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::changeNrOfItems *ui;
    Product* ab;
    Storage* storage;
    ProductRegister* productregister;
    OrderRegister* orders;
};

#endif // CHANGENROFITEMS_H
