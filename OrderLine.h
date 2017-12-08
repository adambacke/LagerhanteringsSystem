#ifndef ORDERLINE_H
#define ORDERLINE_H


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

    //Implementera allt!!
};

#endif // ORDERLINE_H
