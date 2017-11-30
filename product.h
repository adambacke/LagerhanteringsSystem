#ifndef PRODUCT_H
#define PRODUCT_H
#include <QString>


class Product
{
private:
    int IdNr;
    QString Name;
    QString Lev;
    int Place;
    int NrOfItems;


public:
    Product(int IdNr,QString Name,QString Lev,int Place,int NrOfItems);
    Product();
    Product(int IdNr);
    ~Product();

    QString getName() const;
    QString getLev() const;
    int getIdNr() const;
    int getPlace() const;
    int getNrOfItems() const;

    void setNrOfItems(int toAdd);

    QString ToString() const;

    bool operator ==(Product other);



};

#endif // PRODUCT_H
