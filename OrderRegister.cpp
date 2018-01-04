#include "OrderRegister.h"

OrderRegister::OrderRegister()
{
    this->capacity = 0;
    this->counter = 0;
    OrderArray = new Order*[capacity];
}

OrderRegister::OrderRegister(int capacity)
{
    this->capacity = capacity;
    this->counter = 0;
    OrderArray = new Order*[capacity];
}

OrderRegister::~OrderRegister()
{
    for(int i=0;i<counter;i++)
    {
        delete OrderArray[i];
    }
    delete[] OrderArray;
}

int OrderRegister::getCounter() const
{
    return this->counter;
}

int OrderRegister::getCapacity() const
{
    return this->capacity;
}

void OrderRegister::expand()
{
    capacity = capacity + 2;
    Order** temp = new Order*[capacity];
    for(int i = 0;i<counter;i++)
    {
        temp[i] = OrderArray[i];
    }
    delete[] OrderArray;
    OrderArray = temp;
}

void OrderRegister::addOrderToRegister(int OrderNr, QString name, int NrOfrderLines)
{
    if(counter == capacity)
    {
        expand();
    }
    OrderArray[counter] = new Order(OrderNr,name,NrOfrderLines);
    counter++;
}

bool OrderRegister::addOrderLineTooOrder(int OrderNr, int IdNr, int NrOfItems, ProductRegister &productregister)
{
    bool retVal = false;
    for(int i=0;i<counter;i++)
    {
        if(OrderNr == OrderArray[i]->getOrderNr())
        {
            OrderArray[i]->addOrderLine(IdNr,NrOfItems,productregister);
            retVal = true;
        }
    }
    return retVal;
}

QString OrderRegister::toString()
{
    QString retVal;

    for(int i=0;i<counter;i++)
    {
        retVal = retVal + OrderArray[i]->toString() + "\n";
    }
    return retVal;
}

QString OrderRegister::toStringSpecific(int OrderNr)
{
    QString retVal;
    for(int i=0; i<counter;i++)
    {
        if(OrderNr == OrderArray[i]->getOrderNr())
        {
            retVal = OrderArray[i]->toString();
            i = counter;
        }
    }
    return retVal;
}

int OrderRegister::getOrderNrAtIndex(int index) const
{
    return OrderArray[index]->getOrderNr();
}

int OrderRegister::getTotalValueAtIndex(int index, ProductRegister &produkt) const
{
    return OrderArray[index]->GetTotalValue(produkt);
}

int OrderRegister::getOrderNrOfOrderLinesAtIndex(int index) const
{
    return OrderArray[index]->getNrOfOrderLines();
}

QString OrderRegister::getOrderNameAtIndex(int index) const
{
    return OrderArray[index]->getName();
}

int OrderRegister::getOrderLineIdNrAtIndex(int index, int orderLineIndex)
{
    return OrderArray[index]->getOrderLineIdNrAtIndex(orderLineIndex);
}

int OrderRegister::getOrderLineNrOfItemsAtIndex(int index, int orderLineIndex)
{
    return OrderArray[index]->getOrderLineNrOfItemsAtIndex(orderLineIndex);
}
