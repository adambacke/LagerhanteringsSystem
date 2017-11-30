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

    bool addToStoragePlace(int Place, int StorageCapacity, int IdNr);
    bool removeFromStoragePlace(const int IdNr);
    int FindStoragePlace(StorageSpace &toFind) const;
};

#endif // STORAGE_H
