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
    //~Product();

    QString getName() const;
    QString getLev() const;



};

#endif // PRODUCT_H
