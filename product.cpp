#include "product.h"

Product::Product(int IdNr,QString Name,QString Lev,int Place,int NrOfItems)
{
    this->IdNr = IdNr;
    this->Name = Name;
    this->Lev = Lev;
    this->Place = Place;
    this->NrOfItems = NrOfItems;
}


QString Product::getName() const
{
    return this->Name;
}

QString Product::getLev() const
{
    return this->Lev;
}
