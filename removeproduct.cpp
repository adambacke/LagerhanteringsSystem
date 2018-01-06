#include "removeproduct.h"
#include "ui_removeproduct.h"
#include <QMessageBox>

removeProduct::removeProduct(Storage* storage,ProductRegister* productRegister,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::removeProduct)
{
    this->storage = storage;
    this->productRegister = productRegister;
    ui->setupUi(this);
    this->setWindowTitle("Ta bort en produkt");
}

removeProduct::~removeProduct()
{
    delete ui;
}

void removeProduct::on_buttonBox_accepted()
{
    int IdNr;
    QString IdNrString;
    IdNrString = ui->IdToRemove->text();
    IdNr = IdNrString.toInt();


    bool Sucsess = productRegister->removeProductFromRegister(IdNr,*storage);
    QMessageBox ans;
    if(Sucsess == true)
    {
        ans.setText("Produkten är borttagen");
    }
    else
    {
        ans.setText("Produkten finns inte i lagret");
    }
    ans.exec();
}
