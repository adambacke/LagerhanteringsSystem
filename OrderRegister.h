#ifndef ORDERREGISTER_H
#define ORDERREGISTER_H

#include "Order.h"
#include "ProductRegister.h"

class OrderRegister
{
private:
    int capacity;
    int counter;
    Order **OrderArray;

public:
    OrderRegister();
    OrderRegister(int capacity);
    ~OrderRegister();

    int getCounter() const;
    int getCapacity() const;

    void expand();

    void addOrderToRegister(int OrderNr, QString name, int NrOfrderLines);
    bool addOrderLineTooOrder(int OrderNr, int IdNr, int NrOfItems, ProductRegister &productregister);
};

#endif // ORDERREGISTER_H
