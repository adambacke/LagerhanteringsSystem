#include "Order.h"

Order::Order()
{
    this->OrderNr = 0;
    this->Capacity = 0;
    this->name = "";
    this->NrOfOrderLines = 0;
    OrderLines = new OrderLine*[Capacity];
}

Order::Order(int OrderNr, QString name, int Capacity)
{
    this->OrderNr = OrderNr;
    this->name = name;
    this->NrOfOrderLines = 0;
    this->Capacity = Capacity;
    this->OrderLines = new OrderLine*[Capacity];
}

Order::~Order()
{
    for(int i=0;i<NrOfOrderLines;i++)
    {
        delete OrderLines[i];
    }
    delete[] OrderLines;
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
    return NrOfOrderLines;
}

bool Order::addOrderLine(int IdNr, int NrOfItems, ProductRegister &productregister)
{
    bool retVal = false;
    if(NrOfOrderLines == Capacity)
    {
        expand();
    }
    for(int i = 0;i<productregister.getCounter();i++)
    {
        if(IdNr == productregister.getProductIdNrOnPlace(i))
        {
            if(NrOfItems < productregister.getNrOfItemsOnPlace(i))
            {
                OrderLines[NrOfOrderLines] = new OrderLine(IdNr,NrOfItems);
                NrOfOrderLines++;
                productregister.changeNrOfItemsOnPlace(i,NrOfItems);
                retVal = true;
            }
        }
    }
    return retVal;
}

void Order::expand()
{
    Capacity = Capacity + 2;
    OrderLine** temp = new OrderLine*[Capacity];
    for(int i = 0;i<NrOfOrderLines;i++)
    {
        temp[i] = OrderLines[i];
    }
    delete[] OrderLines;
    OrderLines = temp;
}

QString Order::toString() const
{
    QString retVal;

    retVal += this->OrderNr + "\n";
    retVal += this->name + "\n";
    for(int i=0;i<NrOfOrderLines;i++)
    {
        retVal += OrderLines[i]->toString();
    }
    return retVal;
}

int Order::GetTotalValue(ProductRegister &produktregister) const
{

    int IdNr;
    int totalValue;
    for(int i=0;i<NrOfOrderLines;i++)
    {
        IdNr = this->OrderLines[i]->getIdNr();
        Product temp(IdNr);
        for(int t=0;t<produktregister.getCounter();t++)
        {
            if(IdNr == produktregister.getProductIdNrOnPlace(t))
            {
                totalValue = totalValue + ((produktregister.getPricePerItemOnPlace(t))*(this->OrderLines[i]->getNumberOfItems()));
            }
        }
    }
    return totalValue;

}
