#ifndef STORAGE_H
#define STORAGE_H
#include "StorageSpace.h"


class Storage
{
private:
    int capacity;
    int counter;
    StorageSpace** StorageArray;

public:
    Storage();
    Storage(int capacity);
    ~Storage();

    int addToStoragePlace(int StorageCapacity, int IdNr, int NrOfItems);
    bool removeFromStoragePlace(const int IdNr);
    int FindStoragePlace(StorageSpace &toFind) const;
    int findStoragePlaceWithIdNr(int IdNr) const;

    int FindEmptyStoragePlace();
};

#endif // STORAGE_H
