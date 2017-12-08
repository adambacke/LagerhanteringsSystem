#include "StorageSpace.h"

StorageSpace::StorageSpace()
{
    this->IdNr = -1;
    this->Capacity = -1;
}

StorageSpace::StorageSpace(int Capacity, int IdNr, int NrOfItems)
{
    this->Capacity = Capacity;
    this->IdNr = IdNr;
    this->NrOfItems = NrOfItems;
}

StorageSpace::StorageSpace(int IdNr)
{
    this->IdNr = IdNr;
    this->Capacity = 0;
}

StorageSpace::~StorageSpace()
{
    //Tom just nu.
}

void StorageSpace::clearPlace()
{
    this->IdNr = -1;
    this->Capacity = -1;
}

QString StorageSpace::toString() const
{
    QString retVal;
    QString intConverter;

    retVal += "Serie Nr: " + intConverter.setNum(IdNr) + "\n";
    retVal += "Kapacitet: " + intConverter.setNum(Capacity) + "\n";
    retVal += "Saldo: " + intConverter.setNum(NrOfItems) + "\n";

    return retVal;
}

int StorageSpace::getIdNr()
{
    return this->IdNr;
}

void StorageSpace::setCapacity(int Capacity)
{
    this->Capacity=Capacity;
}

void StorageSpace::setIdNr(int IdNr)
{
    this->IdNr = IdNr;
}

void StorageSpace::setNrOfItems(int NrOfItems)
{
    this->NrOfItems = NrOfItems;
}

int StorageSpace::getNrOfItems()
{
    return this->NrOfItems;
}

int StorageSpace::getCapacity()
{
    return this->Capacity;
}

bool StorageSpace::operator ==(StorageSpace other)
{
    bool retVal = false;

    if(this->IdNr == other.IdNr)
    {
        retVal = true;
    }

    return retVal;
}
