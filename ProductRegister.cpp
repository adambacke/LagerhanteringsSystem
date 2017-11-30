#include "ProductRegister.h"

ProductRegister::ProductRegister()
{
    capacity = 0;
    counter = 0;
    ProductArray = new Product*[capacity];

}

ProductRegister::ProductRegister(int capacity)
{
    this->capacity = capacity;
    this->counter = 0;
    ProductArray = new Product*[capacity];
}

ProductRegister::~ProductRegister()
{
    for(int i=0;i<counter;i++)
    {
        delete ProductArray[i];
    }
    delete[] ProductArray;
}

bool ProductRegister::addProductToRegister(int IdNr, QString name, QString lev, int Place, int NrOfItems)
{
    Product toAdd(IdNr,name,lev,Place,NrOfItems);
    int index = productToFind(toAdd);

    if(index == -1)
    {
        if(counter == capacity)
        {
            expand();
        }
        ProductArray[counter] = new Product(toAdd);
        counter++;
    }
    return index == -1;
}

bool ProductRegister::removeProductFromRegister(int IdNr)
{
    Product toRemove(IdNr);
    int index = productToFind(toRemove);

    if(index != -1)
    {
        delete ProductArray[index];
        ProductArray[index] = ProductArray[--counter];
        ProductArray[counter] = nullptr;
    }
    return index != -1;
}

int ProductRegister::productToFind(Product &toFind)
{
    int index = -1;

    for(int i=0; i<counter;i++)
    {
        if(toFind == *ProductArray[i])
        {
            index = i;
            i = counter;
        }
    }
    return index;
}

void ProductRegister::expand()
{
    capacity = capacity + 2;
    Product** temp = new Product*[capacity];
    for(int i = 0;i<counter;i++)
    {
        temp[i] = ProductArray[i];
    }
    delete[] ProductArray;
    ProductArray = temp;
}

QString ProductRegister::toString()
{
    QString retVal;

    for(int i=0;i<counter;i++)
    {
        retVal += ProductArray[i]->ToString();
        retVal += "\n";
    }

    return retVal;
}
