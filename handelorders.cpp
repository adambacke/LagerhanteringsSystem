#include "handelorders.h"
#include "ui_handelorders.h"
#include "addorder.h"

#include <QMessageBox>

handelOrders::handelOrders(Storage *storage, ProductRegister *productregister, OrderRegister *orders, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::handelOrders)
{
    this->storage = storage;
    this->productregister = productregister;
    this->orders = orders;
    ui->setupUi(this);
}

handelOrders::~handelOrders()
{
    delete ui;
}

void handelOrders::on_ShowOrder_clicked()
{
    QString OrderNrString = ui->OrderNr->text();


    if(OrderNrString == "")
    {
        ui->textBrowser->setText("Ange ett OrderNummer.");
    }
    else
    {
        int OrderNr = OrderNrString.toInt();

        QString OrderString = orders->toStringSpecific(OrderNr);
        int index;
        for(int i=0;i<orders->getCounter();i++)
        {
            if(OrderNr == orders->getOrderNrAtIndex(i))
            {
                index = i;
                i = orders->getCounter();
            }
        }
        QString temp;
        OrderString = OrderString + "Totalt Ordervärde: " + temp.setNum(orders->getTotalValueAtIndex(index,*productregister)) + " kr";
        ui->textBrowser->setText(OrderString);
    }
}

void handelOrders::on_clear_clicked()
{
    ui->textBrowser->clear();
    ui->OrderNr->clear();
}

void handelOrders::on_createOrder_clicked()
{
    AddOrder addorder(storage,productregister,orders);
    addorder.setModal(true);
    addorder.exec();
}

void handelOrders::on_addOrderLine_clicked()
{
    QString OrderNrString = ui->orderNr2->text();
    QString IdNrString = ui->idNr->text();
    QString NrOfItemsString = ui->nrOfItems->text();

    int OrderNr = OrderNrString.toInt();
    int IdNr = IdNrString.toInt();
    int NrOfItems = NrOfItemsString.toInt();

    bool sucsess = orders->addOrderLineTooOrder(OrderNr,IdNr,NrOfItems,*productregister);
    QMessageBox ans;
    if(sucsess == true)
    {
        ans.setText("Orderraden är tillagd");
    }
    else
    {
        ans.setText("Det gick inte att lägga till orderraden");
    }
    ans.exec();
    if(sucsess == true)
    {
    ui->orderNr2->clear();
    ui->idNr->clear();
    ui->nrOfItems->clear();
    }
}

void handelOrders::on_Goback_clicked()
{
    this->close();
}
