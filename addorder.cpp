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

    orders->addOrderToRegister(OrderNr,Name,1);

    QMessageBox ans;

    ans.setText("Ordern är tillagd");

    ans.exec();

}
