#include "addproduct.h"
#include "ui_addproduct.h"
#include <QMessageBox>

AddProduct::AddProduct(Storage* storage,ProductRegister* productRegister, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddProduct)
{
    this->storage = storage;
    this->productRegister = productRegister;
    ui->setupUi(this);
    this->setWindowTitle("Lägg till produkt");
}

AddProduct::~AddProduct()
{
    delete ui;
}

void AddProduct::on_buttonBox_accepted()
{
    QString name;
    int IdNr;
    QString lev;
    int capacity;
    int PricePerItem;
    int NrOfItems;

    name = ui->productName->text();
    lev = ui->Lev->text();
    QString IdNrString = ui->IdNrText->text();
    IdNr = IdNrString.toInt();
    QString capacityString = ui->capicety->text();
    capacity = capacityString.toInt();
    QString PricePerItemString = ui->pricePerItem->text();
    PricePerItem = PricePerItemString.toInt();
    QString NrOfItemsString = ui->NrOfItems->text();
    NrOfItems = NrOfItemsString.toInt();

    int answer = productRegister->addProductToRegister(IdNr,name,lev,NrOfItems,capacity,PricePerItem);
    QMessageBox ans;

    if(answer == -2)
    {
      ans.setText("Lagret är fullt!");
    }
    else if(answer == -3)
    {
        ans.setText("Går inte att lägga till så många på platsen");
    }
    else if (answer == 0)
    {
        ans.setText("Produkten är tillagd");
    }
    ans.exec();
}
