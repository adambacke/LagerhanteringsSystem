#ifndef STORAGESPACE_H
#define STORAGESPACE_H
#include <QString>
#include "product.h"


class StorageSpace
{
private:
    int Capacity;
    int IdNr;
    int NrOfItems;

public:
    StorageSpace();
    StorageSpace(int Capacity, int IdNr, int NrOfItems);
    StorageSpace(int IdNr);
    ~StorageSpace();

    void clearPlace();

    QString toString() const;

    int getIdNr();

    void setCapacity(int Capacity);
    void setIdNr(int IdNr);
    void setNrOfItems(int NrOfItems);

    int getNrOfItems();
    int getCapacity();

    bool operator ==(StorageSpace other);
};

#endif // STORAGESPACE_H
