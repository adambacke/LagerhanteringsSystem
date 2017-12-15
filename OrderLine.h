#ifndef ORDERLINE_H
#define ORDERLINE_H

#include <QString>



class OrderLine
{
private:
    int IdNr;
    int NumberOfItems;

public:
    OrderLine();
    OrderLine(int IdNr, int NumberOfItems);
    ~OrderLine();

    int getIdNr() const;
    int getNumberOfItems() const;

    bool operator == (OrderLine Other);

    QString toString();
};

#endif // ORDERLINE_H
