#include <iostream>
#include "array.h"

using namespace std;
int main(){
  Array<int> intarray(20);
  Array<Array<int> > arrarr(10);
  for(int i = 0; i < 20; i++)
    intarray[i] = i+1;

  // This uses the copy constructor
  Array<int> iarray(intarray);
  for(int i = 0; i < iarray.getLength(); i++)
    iarray[i] *= i; // modify the original values
  for(int i = 0; i < iarray.getLength(); i++)
    cout << "iarray[" << i << "] = \t" << iarray[i] << endl;

  // This should use the overloaded operator=
  arrarr[0] = arrarr[1] = intarray;
  // modify elements of first array
  for(int i = 0; i < 20; i++)
    arrarr[0][i] += i;
  cout << "=========== [START] ===========" << endl;
  for(int i = 0; i < 20; i++)
    cout << "arrarr[0][" << i << "]\t" << "=\t"
         << arrarr[0][i] << endl;
  cout << "========== * ==========" << endl;
  for(int i = 0; i < 20; i++)
    cout << "arrarr[1][" << i << "]\t" << "=\t"
         << arrarr[1][i] << endl;
  cout << "============= [END] ============" << endl;

  return 0;
}
