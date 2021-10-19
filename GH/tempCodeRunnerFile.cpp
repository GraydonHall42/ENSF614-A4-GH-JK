MyArray& MyArray::operator =(const MyArray& rhs){
  sizeM=rhs.sizeM;
  delete[] storageM;
  storageM = new EType[rhs.sizeM];
  for(int i=0; i<sizeM; i++){
    storageM[i] = rhs.storageM[i];
  }
  return *this;
}