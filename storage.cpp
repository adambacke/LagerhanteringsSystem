#include "storage.h"

Storage::Storage()
{

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

bool Storage::addToStoragePlace(int Place, int StorageCapacity, int IdNr)
{
    StorageSpace toAdd(Place, StorageCapacity, IdNr);
    int index = FindStoragePlace(toAdd);

    if(index == -1)
    {
        if(counter == capacity)
        {
            //GE ETT MEDDLEANDE OM ATT ARRAYEN ÄR FULL!
        }
        StorageArray[counter] = new StorageSpace(toAdd);
    }
    return index == -1;
}

bool Storage::removeFromStoragePlace(const int IdNr)
{
    StorageSpace toRemove(IdNr);
    int index = FindStoragePlace(toRemove);

    if(index != -1)
    {
        delete StorageArray[index];
        StorageArray[index] = StorageArray[--counter];
        StorageArray[counter]->clearPlace();
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
