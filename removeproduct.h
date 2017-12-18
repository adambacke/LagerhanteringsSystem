#ifndef REMOVEPRODUCT_H
#define REMOVEPRODUCT_H

#include <QDialog>
#include "storage.h"
#include "ProductRegister.h"

namespace Ui {
class removeProduct;
}

class removeProduct : public QDialog
{
    Q_OBJECT

public:
    explicit removeProduct(Storage* storage,ProductRegister* productRegister,QWidget *parent = 0);
    ~removeProduct();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::removeProduct *ui;
    Storage* storage;
    ProductRegister* productRegister;
};

#endif // REMOVEPRODUCT_H
