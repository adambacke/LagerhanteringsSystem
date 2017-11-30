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

Product::Product(int IdNr)
{
    this->IdNr = IdNr;
    this->Name = "";
    this->Lev = "";
    this->Place = -1;
    this->NrOfItems = 0;
}

Product::~Product()
{
    //Tom...
}


QString Product::getName() const
{
    return this->Name;
}

QString Product::getLev() const
{
    return this->Lev;
}

int Product::getIdNr() const
{
    return this->IdNr;
}

int Product::getPlace() const
{
    return this->Place;
}

int Product::getNrOfItems() const
{
    return this->NrOfItems;
}

void Product::setNrOfItems(int toAdd)
{
    this->NrOfItems = this->NrOfItems + toAdd;
}

QString Product::ToString() const
{
    QString ret;
    QString Tostring;

    //Ändra till convert istället. setNumb.

    ret += "Serie Nr: " + Tostring.setNum(IdNr) + "\n";
    ret += "Namn: " + Name + "\n";
    ret += "Leverantör: " + Lev + "\n";
    ret += "Lagerplats: " + Tostring.setNum(Place) + "\n";
    ret += "Saldo: " + Tostring.setNum(NrOfItems) + "\n";

    return ret;
}

bool Product::operator ==(Product other)
{
    bool retval = false;

    if(this->IdNr == other.IdNr)
    {
        retval = true;
    }
    return retval;
}
