#include "OrderLine.h"

OrderLine::OrderLine()
{

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
