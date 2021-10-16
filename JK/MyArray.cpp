// MyArray.cpp
// ENSF 614 Fall 2021 Lab 4 Exercise A

#include "MyArray.h"

MyArray::MyArray() : sizeM(0)
{
    storageM = new EType[0];
}
// Create empty array.
// PROMISES: size() == 0.

MyArray::MyArray(const EType *builtin, int sizeA) : sizeM(sizeA)
{
    if (sizeA < 0)
    {
        return;
    }

    storageM = new EType[sizeA];

    for (int i = 0; i < sizeA; i++)
    {
        storageM[i] = builtin[i];
    }
}
// Create object by copying a built-in array.
// REQUIRES
//   sizeA >= 0. Elements builtin[0] ... builtin[sizeA - 1] exist.
// PROMISES
//   size() == sizeA.
//   For i from 0 to sizeA-1, element i of object == builtin[i].

MyArray::MyArray(const MyArray &source) : sizeM(source.sizeM)
{
    storageM = new EType[source.sizeM];

    for (int i = 0; i < source.sizeM; i++)
    {
        storageM[i] = source.storageM[i];
    }
}

MyArray &MyArray::operator=(const MyArray &rhs)
{
    if (this != &rhs)
    {
        delete[] storageM;
        sizeM = rhs.sizeM;
        storageM = new EType[rhs.sizeM];
        for (int i = 0; i < rhs.sizeM; i++)
        {
            storageM[i] = rhs.storageM[i];
        }
    }
    return *this;
}

MyArray::~MyArray()
{
    delete storageM;
    storageM = nullptr;
    sizeM = 0;
}

int MyArray::size() const
{
    return sizeM;
}
// PROMISES: Return value is number of elements stored.

EType MyArray::at(int i) const
{
    return storageM[i];
}
// REQUIRES: 0 <= i && i < size().
// PROMISES: Return value is a reference to element i of array.

void MyArray::set(int i, EType new_value)
{
    storageM[i] = new_value;
}
// REQUIRES: 0 <= i && i < size().
// PROMISES: assigns new_value to the ith element of storageM

void MyArray::resize(int new_size)
{
    EType *temp = new EType[new_size];
    for (int i = 0; (i < new_size) || (i < sizeM); i++)
    {
        temp[i] = storageM[i];
    }

    delete[] storageM;
    storageM = temp;
    sizeM = new_size;
}
// REQUIRES: new_size >= 0.
// PROMISES
//   size() == new_size.
//   If the operation shrinks the array or does not change the size,
//   values of elements 0, 1, ... new_size - 1 are preserved.
//   If the operation increases the size,
//   values of elements 0, 1, ... one less than the old size
//   are preserved.