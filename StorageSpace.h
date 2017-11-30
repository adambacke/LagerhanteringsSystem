#ifndef STORAGESPACE_H
#define STORAGESPACE_H
#include <QString>
#include "product.h"


class StorageSpace
{
private:
    int Place;
    int Capacity;
    int IdNr;

public:
    StorageSpace();
    StorageSpace(int Place, int Capacity, int IdNr);
    StorageSpace(int IdNr);
    ~StorageSpace();

    void clearPlace();

    QString toString() const;

    bool operator ==(StorageSpace other);
};

#endif // STORAGESPACE_H
