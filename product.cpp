#include "product.h"

Product::Product(int IdNr,QString Name,QString Lev,int Place,int NrOfItems)
{
    this->IdNr = IdNr;
    this->Name = Name;
    this->Lev = Lev;
    this->Place = Place;
    this->NrOfItems = NrOfItems;
}

Product::Product()
{
    this->IdNr = 0;
    this->Name = "";
    this->Lev = "";
    this->Place = -1;
    this->NrOfItems = 0;
}


QString Product::getName() const
{
    return this->Name;
}

QString Product::getLev() const
{
    return this->Lev;
}

QString Product::ToString() const
{
    QString ret;

    //Ändra till convert istället. setNumb.

    ret += "Serie Nr: " + std::to_string(IdNr) + "\n";
    ret += "Namn: " + Name + "\n";
    ret += "Leverantör: " + Lev + "\n";
    ret += "Lagerplats: " + std::to_string(Place) + "\n";
    ret += "Saldo: " + std::to_string(NrOfItems) + "\n";

    return ret;
}
