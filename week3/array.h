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
  //!NOTE: Copy constructor below
  Array(const Array<T>& arr)
   : Array(arr.getLength())
    {
      for(int i = 0; i < length; i++)
        data[i] = arr[i];
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
  //!NOTE: overloaded 'operator=' below
  Array<T>& operator=(const Array<T>& rhs){
    // erase everything first
    Erase();
    // resize 'data' to hold new items
    data   = new T[rhs.getLength()];
    length = rhs.getLength();
    // copy the items into 'data'
    for(int i = 0; i < length; i++)
      data[i] = rhs[i];
    // return a reference to this object
    return *this;
  }
  int getLength() const;
};
template <typename T>
int Array<T>::getLength() const{
  return length;
}
#endif
