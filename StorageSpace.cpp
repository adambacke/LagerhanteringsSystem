#include "StorageSpace.h"

StorageSpace::StorageSpace()
{
    this->IdNr = -1;
    this->Place = -1;
    this->Capacity = 0;
}

StorageSpace::StorageSpace(int Place, int Capacity, int IdNr)
{
    this->Place = Place;
    this->Capacity = Capacity;
    this->IdNr = IdNr;
}

StorageSpace::StorageSpace(int IdNr)
{
    this->IdNr = IdNr;
    this->Place = -1;
    this->Capacity = 0;
}

StorageSpace::~StorageSpace()
{
    //Tom just nu.
}

void StorageSpace::clearPlace()
{
    this->IdNr = -1;
}

QString StorageSpace::toString() const
{
    QString retVal;
    QString intConverter;

    retVal += "Lagerplats: " + intConverter.setNum(Place) + "\n";
    retVal += "Serie Nr: " + intConverter.setNum(IdNr) + "\n";
    retVal += "Kapacitet: " + intConverter.setNum(Capacity) + "\n";

    return retVal;
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
