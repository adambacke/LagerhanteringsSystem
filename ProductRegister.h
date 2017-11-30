#ifndef PRODUCTREGISTER_H
#define PRODUCTREGISTER_H
#include "product.h"
#include <QString>


class ProductRegister
{
private:
    int capacity;
    int counter;
    Product **ProductArray;


public:
    ProductRegister();
    ProductRegister(int capacity);
    ~ProductRegister();

    bool addProductToRegister(int IdNr, QString name, QString lev, int Place, int NrOfItems);
    bool removeProductFromRegister(int IdNr);
    int productToFind(Product &toFind);
    void expand();

    QString toString();
};

#endif // PRODUCTREGISTER_H
