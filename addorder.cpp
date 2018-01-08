#include "addorder.h"
#include "ui_addorder.h"
#include <QMessageBox>

AddOrder::AddOrder(Storage* storage,ProductRegister* productRegister, OrderRegister* orders, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddOrder)
{
    this->storage = storage;
    this->productRegister = productRegister;
    this->orders = orders;
    ui->setupUi(this);
    this->setWindowTitle("Lägg till order");
}

AddOrder::~AddOrder()
{
    delete ui;
}

void AddOrder::on_buttonBox_accepted()
{
    int OrderNr;

    QString OrderNrString = ui->OrderNr->text();
    QString Name = ui->Name->text();
    OrderNr = OrderNrString.toInt();

    bool answer = orders->addOrderToRegister(OrderNr,Name,1);
    QMessageBox ans;
    if(answer == false)
    {
        ans.setText("Ordern är tillagd");
    }
    else
    {
         ans.setText("OrderNummret finns redan i registret");
    }
    ans.exec();

}
