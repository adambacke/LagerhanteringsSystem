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

bool OrderRegister::addOrderToRegister(int OrderNr, QString name, int NrOfrderLines)
{
    if(counter == capacity)
    {
        expand();
    }
    OrderArray[counter] = new Order(OrderNr,name,NrOfrderLines);
    counter++;
}