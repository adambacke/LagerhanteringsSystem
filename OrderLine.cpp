#include "OrderLine.h"

OrderLine::OrderLine()
{
    this->IdNr = 0;
    this->NumberOfItems = 0;
}

OrderLine::OrderLine(int IdNr, int NumberOfItems)
{
    this->IdNr = IdNr;
    this->NumberOfItems = NumberOfItems;
}

OrderLine::~OrderLine()
{
    //Tom...
}

int OrderLine::getIdNr() const
{
    return IdNr;
}

int OrderLine::getNumberOfItems() const
{
    return NumberOfItems;
}

bool OrderLine::operator ==(OrderLine Other)
{
    bool retVal = false;
    if(this->IdNr == Other.IdNr)
    {
        retVal = true;
    }
    return retVal;
}

QString OrderLine::toString()
{
    QString retVal;
    QString Tostring;

    retVal += Tostring.setNum(IdNr) + "\t";
    retVal += Tostring.setNum(NumberOfItems) + "\n";

    return retVal;
}
