#include "Order.h"

Order::Order()
{

}

Order::Order(int OrderNr, QString name, OrderLine **OrderLines, int Capacity)
{
    this->OrderNr = OrderNr;
    this->name = name;
    int NrOfOrdeLines = 0;
    this->Capacity = Capacity;
    OrderLines = new OrderLine*[Capacity];
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

int Order::addOrderLine(int IdNr, int NrOfItems)
{

}

void Order::expand()
{
    Capacity = Capacity + 2;
    OrderLine** temp = new OrderLine*[Capacity];
    for(int i = 0;i<NrOfOrdeLines;i++)
    {
        temp[i] = OrderLines[i];
    }
    delete[] OrderLines;
    OrderLines = temp;
}

int Order::GetTotalValue(ProductRegister &produktregister) const
{
    /*
    int IdNr;
    int totalValue;
    for(int i=0;i<NrOfOrdeLines;i++)
    {
        IdNr = this->OrderLines[i]->getIdNr();
        Product temp(IdNr);
        for(int t=0;t<produktregister.getCounter();t++)
        {
            if(temp == *produktregister.ProductArray[t])
            {
                totalValue = totalValue + ((produktregister.ProductArray[t]->getPricePerItem())*(this->OrderLines[i]->getNumberOfItems()));
            }
        }
    }
    return totalValue;
    */
}
