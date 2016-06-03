#ifndef ARRAY_H
#define ARRAY_H
#include <assert.h>

template <typename T>
class Array{
  int length;
  T* data;
 public:
  Array(){
    length = 0;
    data   = 0;
  }
  Array(int length){
    this->length = length;
    data         = new T[length];
  }
  ~Array(){
    delete []data;
  }
  void Erase(){
    delete []data;
    data   = 0;
    length = 0;
  }
  T& operator[](int index) const {
    assert((index >= 0) && (index < length));
    return data[index];
  }

  Array<T>& operator=(const Array<T>& rhs){
    Erase();
    data = new T[rhs.getLength()];
    length = rhs.getLength();
    for(int i = 0; i < length; i++){
      data[i] = rhs[i];
    }
    return *this;
  }

  int getLength() const;
};
template <typename T>
int Array<T>::getLength() const{
  return length;
}
#endif
