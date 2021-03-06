#include "product.h"

Product::Product(int IdNr, QString Name, QString Lev, int NrOfItems, int PricePerItem)
{
    this->IdNr = IdNr;
    this->Name = Name;
    this->Lev = Lev;
    this->NrOfItems = NrOfItems;
    this->PricePerItem = PricePerItem;
}

Product::Product()
{
    this->IdNr = 0;
    this->Name = "";
    this->Lev = "";
    this->NrOfItems = 0;
    this->PricePerItem = 0;
}

Product::Product(int IdNr)
{
    this->IdNr = IdNr;
    this->Name = "";
    this->Lev = "";
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

int Product::getNrOfItems() const
{
    return this->NrOfItems;
}

int Product::getPricePerItem() const
{
    return this->PricePerItem;
}

void Product::setNrOfItems(int toAdd)
{
    this->NrOfItems = this->NrOfItems + toAdd;
}

QString Product::ToString() const
{
    QString ret;
    QString Tostring;

    ret += "Serie Nr: " + Tostring.setNum(IdNr) + "\n";
    ret += "Namn: " + Name + "\n";
    ret += "Leverantör: " + Lev + "\n";
    ret += "Saldo: " + Tostring.setNum(NrOfItems) + "\n";
    ret += "Styck Pris: " + Tostring.setNum(PricePerItem) + "\n";

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
