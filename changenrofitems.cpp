#include "changenrofitems.h"
#include "ui_changenrofitems.h"
#include <QMessageBox>

changeNrOfItems::changeNrOfItems(Storage *storage, ProductRegister *productregister, OrderRegister *orders,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::changeNrOfItems)
{
    this->storage = storage;
    this->productregister = productregister;
    this->orders = orders;
    ui->setupUi(this);
}

changeNrOfItems::~changeNrOfItems()
{
    delete ui;
}

void changeNrOfItems::on_buttonBox_accepted()
{
    QString IdNrString = ui->IdNr->text();
    QString NrOfItemsString = ui->NrOfItems->text();
    int IdNr = IdNrString.toInt();
    int NrOfItems = NrOfItemsString.toInt();
    bool sucsess = false;
    int index;

    for(int i=0;i<productregister->getCounter();i++)
    {
        if(IdNr == productregister->getProductIdNrOnPlace(i))
        {
            index = i;
            if(storage->getStorageCapacityOnIndex(index) >= (storage->getNrOfItemsOnIndex(index)+NrOfItems))
            {
                i = productregister->getCounter();
                productregister->addNrOfItemsOnPlace(index,NrOfItems);
                sucsess = true;
            }
        }
    }
    QMessageBox ans;
    if(sucsess == true)
    {
        ans.setText("Du har ändrat saldot");
    }
    if(sucsess == false)
    {
        ans.setText("Det gick inte att ändra saldot");
    }
    ans.exec();
}
