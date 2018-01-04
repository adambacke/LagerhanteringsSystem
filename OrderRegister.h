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

    QString toString();
    QString toStringSpecific(int OrderNr);

    int getOrderNrAtIndex(int index) const;
    int getTotalValueAtIndex(int index, ProductRegister &produkt) const;
    int getOrderNrOfOrderLinesAtIndex(int index) const;
    QString getOrderNameAtIndex(int index) const;

    int getOrderLineIdNrAtIndex(int index, int orderLineIndex);
    int getOrderLineNrOfItemsAtIndex(int index, int orderLineIndex);
};

#endif // ORDERREGISTER_H
