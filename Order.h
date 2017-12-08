#ifndef ORDER_H
#define ORDER_H
#include "OrderLine.h"
#include "storage.h"
#include "ProductRegister.h"

class Order
{
private:
    int OrderNr;
    QString name;
    int NrOfOrdeLines;
    OrderLine **OrderLines;
    int Capacity;

public:
    Order();
    Order(int OrderNr, QString name, OrderLine **OrderLines, int Capacity);

    int getOrderNr() const;
    QString getName() const;
    int getNrOfOrderLines() const;

    int GetTotalValue(ProductRegister &produktregister) const;

    int addOrderLine(int IdNr, int NrOfItems);
    void expand();
    bool removeOrderLine();

    QString toString() const;
};

#endif // ORDER_H
