#ifndef PRODUCTREGISTER_H
#define PRODUCTREGISTER_H
#include "product.h"
#include "storage.h"
#include <QString>


class ProductRegister
{
private:
    int capacity;
    int counter;
    Product **ProductArray;
    Storage* storage;


public:
    ProductRegister();
    ProductRegister(int capacity, Storage *storage);
    ~ProductRegister();

    int addProductToRegister(int IdNr, QString name, QString lev, int NrOfItems, int StoragePlaceCapacity, int PricePerItem);
    bool removeProductFromRegister(int IdNr);
    int productToFind(Product &toFind);
    void expand();

    QString toString();
};

#endif // PRODUCTREGISTER_H
