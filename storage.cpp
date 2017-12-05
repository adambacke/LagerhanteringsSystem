#include "storage.h"

Storage::Storage()
{
    //Tom just nu.....
}

Storage::Storage(int capacity)
{
    this->capacity = capacity;
    this->counter = 0;
    StorageArray = new StorageSpace*[capacity];

    for(int i=0;i<capacity;i++)
    {
        StorageArray[i] = new StorageSpace(i,-1,-1,0);
    }
}

Storage::~Storage()
{
    for(int i=0;i<counter;i++)
    {
        delete StorageArray[i];
    }
    delete[] StorageArray;
}

int Storage::addToStoragePlace(int Place, int StorageCapacity, int IdNr, int NrOfItems)
{
    //-2 = Lagret är fullt. -1 = Produkten finns inte i lagret. -3 = Försöker lägga till förmånga produkter på en plats.
    // 0 = Lyckades att lägga till produkt på plats.

    StorageSpace toAdd(Place, StorageCapacity, IdNr, NrOfItems);
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
            StorageArray[Place]->setCapacity(StorageCapacity);
            StorageArray[Place]->setIdNr(IdNr);
            StorageArray[Place]->setNrOfItems(NrOfItems);
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
        StorageArray[index] = StorageArray[counter];
        counter--;
        //StorageArray[counter]->clearPlace();
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

int Storage::FindEmptyStoragePlace()
{
    int index = -1;
    for(int i=0;i<this->capacity;i++)
    {
        if(StorageArray[i]->getIdNr() == -1)
        {
            index = i;
        }
    }
    return index;
}
