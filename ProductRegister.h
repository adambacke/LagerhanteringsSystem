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

    int getCounter() const;

    int addProductToRegister(int IdNr, QString name, QString lev, int NrOfItems, int StoragePlaceCapacity, int PricePerItem);
    bool removeProductFromRegister(int IdNr, Storage &storage);
    int productToFind(Product &toFind);
    void expand();

    int getProductIdNrOnPlace(int index);
    int getPricePerItemOnPlace(int index);
    int getNrOfItemsOnPlace(int index);

    void changeNrOfItemsOnPlace(int index, int NrOfItemsToRemove);
    void addNrOfItemsOnPlace(int index, int NrOfItemsToAdd);

    QString toString();
};

#endif // PRODUCTREGISTER_H
