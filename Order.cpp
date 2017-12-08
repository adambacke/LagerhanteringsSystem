#include "Order.h"

Order::Order()
{

}

Order::Order(int OrderNr, QString name, OrderLine **OrderLines)
{
    this->OrderNr = OrderNr;
    this->name = name;
    int NrOfOrdeLines = 0;
    OrderLines = new OrderLine*[NrOfOrdeLines];
}

int Order::getOrderNr() const
{
    return OrderNr;
}

QString Order::getName() const
{
    return name;
}

int Order::getNrOfOrderLines() const
{
    return NrOfOrdeLines;
}

int Order::GetTotalValue() const
{
    int IdNr;
    for(int i=0;i<NrOfOrdeLines;i++)
    {
        IdNr = this->OrderLines[i]->getIdNr();
        Product temp(IdNr);





    }
}
