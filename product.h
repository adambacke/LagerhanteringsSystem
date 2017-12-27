#ifndef PRODUCT_H
#define PRODUCT_H
#include <QString>


class Product
{
private:
    int IdNr;
    QString Name;
    QString Lev;
    int NrOfItems;
    int PricePerItem;


public:
    Product(int IdNr, QString Name, QString Lev, int NrOfItems, int PricePerItem);
    Product();
    Product(int IdNr);
    ~Product();

    QString getName() const;
    QString getLev() const;
    int getIdNr() const;
    int getNrOfItems() const;
    int getPricePerItem() const;

    void setNrOfItems(int toAdd);

    QString ToString() const;

    bool operator ==(Product other);

};

#endif // PRODUCT_H
