#include "storage.h"

Storage::Storage()
{
    this->capacity = 0;
    this->counter = 0;
    StorageArray = new StorageSpace*[capacity];
}

Storage::Storage(int capacity)
{
    this->capacity = capacity;
    this->counter = 0;
    StorageArray = new StorageSpace*[capacity];
}

Storage::~Storage()
{

    for(int i=0;i<counter;i++)
    {
        delete StorageArray[i];
    }
    delete[] StorageArray;

}

int Storage::addToStoragePlace(int StorageCapacity, int IdNr, int NrOfItems)
{
    //-2 = Lagret är fullt. -1 = Produkten finns inte i lagret. -3 = Försöker lägga till förmånga produkter på en plats.
    // 0 = Lyckades att lägga till produkt på plats.

    StorageSpace toAdd(StorageCapacity, IdNr, NrOfItems);
    int index = FindStoragePlace(toAdd);

    if(index == -1)
    {
        if(counter == capacity)
        {
            index = -2;
        }
        else if(StorageCapacity < NrOfItems)
        {
            index = -3;
        }
        else
        {
            StorageArray[counter] = new StorageSpace(toAdd);
            counter++;
            index = 0;
        }
    }
    return index;
}

bool Storage::removeFromStoragePlace(const int IdNr)
{
    StorageSpace toRemove(IdNr);
    int index = FindStoragePlace(toRemove);

    if(index != -1)
    {
        delete StorageArray[index];
        StorageArray[index] = StorageArray[counter - 1];
        counter--;
    }
    return index != -1;
}

int Storage::FindStoragePlace(StorageSpace& toFind) const
{
    int index = -1;
    for(int i=0; i<counter;i++)
    {
        if(toFind == *StorageArray[i])
        {
            index = i;
            i = counter;
        }
    }
    return index;
}

int Storage::findStoragePlaceWithIdNr(int IdNr) const
{
    int index = -1;

    for(int i=0;i<counter;i++)
    {
        if(IdNr == StorageArray[i]->getIdNr())
        {
            index = i;
            i = counter;
        }
    }
    return index;
}

int Storage::getNrOfItemsOnIndex(int index)
{
    return StorageArray[index]->getNrOfItems();
}

void Storage::setNrOfItemsOnIndex(int index, int NrOfItemsToRemove)
{
    StorageArray[index]->setNrOfItems(-NrOfItemsToRemove);
}

int Storage::getStorageCapacityOnIndex(int index)
{
    return StorageArray[index]->getCapacity();
}

int Storage::FindEmptyStoragePlace()
{
    int index = -1;
    for(int i=0;i<this->capacity;i++)
    {
        if(StorageArray[i]->getIdNr() == -1)
        {
            index = i;
            i = capacity;
        }
    }
    return index;
}

QString Storage::toString()
{
    QString retVal;
    for(int i=0;i<counter;i++)
    {
        retVal += StorageArray[i]->toString();
        retVal += "\n";
    }
    return retVal;
}
