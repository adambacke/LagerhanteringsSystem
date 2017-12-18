#ifndef ADDPRODUCT_H
#define ADDPRODUCT_H

#include <QDialog>
#include "storage.h"
#include "ProductRegister.h"


namespace Ui {
class AddProduct;
}

class AddProduct : public QDialog
{
    Q_OBJECT

public:
    explicit AddProduct(Storage* storage, ProductRegister* productRegister, QWidget *parent = 0);
    ~AddProduct();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AddProduct *ui;
    Storage* storage;
    ProductRegister* productRegister;

};

#endif // ADDPRODUCT_H
