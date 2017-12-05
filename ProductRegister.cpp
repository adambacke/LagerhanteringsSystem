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

int ProductRegister::addProductToRegister(int IdNr, QString name, QString lev, int NrOfItems, int StoragePlaceCapacity)
{
    //-2 = Lagret är fullt. -1 = Produkten finns inte i lagret. -3 = Försöker lägga till förmånga produkter på en plats.
    // 0 = Lyckades att lägga till produkt på plats.

    Product toAdd(IdNr,name,lev,NrOfItems);
    int index = productToFind(toAdd);


    if(index == -1)
    {
        if(counter == capacity)
        {
            expand();
        }
        int indexinStorage = Storage.FindEmptyStoragePlace();
        int Succsess = Storage.addToStoragePlace(indexinStorage,StoragePlaceCapacity,IdNr,NrOfItems);

        if(Succsess == 0)
        {
            ProductArray[counter] = new Product(toAdd);
            counter++;
            index = 0;
        }
        if (Succsess == -3)
        {
            index = -3;
        }
        if (Succsess == -2)
        {
            index = -2;
        }
    }
    return index;
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
