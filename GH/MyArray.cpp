/* File Name: MyArray.cpp
* Lab # and Assignment #: Lab #4 Exercise A
* Lab section: 1
* Completed by: Graydon Hall and Jared Kraus
* Submission Date: 2021-10-19
*/

#include <iostream>
using namespace std;

#include "MyArray.h"

MyArray::MyArray(){
  sizeM = 0;
  storageM = new EType[0];
}

MyArray::MyArray(const EType *builtin, int sizeA):sizeM(sizeA){
  storageM = new EType[sizeA];
  for(int i=0; i<sizeA; i++){
    storageM[i] = builtin[i];
  }
}

// copy constructor
MyArray::MyArray(const MyArray& source):sizeM(source.sizeM){
  storageM = new EType[sizeM];
  for(int i=0; i<sizeM; i++){
    storageM[i] = source.storageM[i];
  }
}

//Destructor
MyArray::~MyArray(){
  sizeM = 0;
  delete storageM;
}

MyArray& MyArray::operator =(const MyArray& rhs){
  sizeM=rhs.sizeM;
  storageM = new EType[rhs.sizeM];
  for(int i=0; i<sizeM; i++){
    storageM[i] = rhs.storageM[i];
  }
}

int MyArray::size() const{
  return sizeM;
}

EType& MyArray::at(int i) const{
  return storageM[i];
}

void MyArray::set(int i, EType new_value){
  storageM[i] = new_value;
}


void MyArray::resize(int new_size){
  sizeM = new_size;
  EType* tempHolder;
  tempHolder = new EType[new_size];

  // figure out if new or old array is smaller
  int smaller;
  if(new_size < sizeM){
    smaller = new_size;
  }
  else{
    smaller = sizeM;
  }

  for(int i=0; i<smaller; i++){
    tempHolder[i] = storageM[i];
  }

  delete storageM;
  storageM = tempHolder;

}