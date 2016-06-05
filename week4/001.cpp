#include <vector>
#include <iostream>
using namespace std;
void VectorOfVector(){
  cout << "=============== *Vector of Vectors* ===============" << endl;
  // 'vecvec' is a vector of three ('3') 'vector<int>' each of
  // which holds two ('2') int elements, both initialised to '0'.
  vector< vector<int> > vecvec(3, vector<int>(2,0));
  // First vector<int> in 'vecvec'
  vecvec[0][0] = 0;
  vecvec[0][1] = 1;
  // Second vector<int> in 'vecvec'
  vecvec[1][0] = 10;
  vecvec[1][1] = 11;
  // Third vector<int> in 'vecvec'
  vecvec[2][0] = 20;
  vecvec[2][1] = 21;
  // We then print 'vecvec' out
  for(int l_one = 0; l_one < vecvec.size(); l_one++){
    cout << "Elements of vecvec[" << l_one << "]" << endl;
    for(int l_two = 0; l_two < vecvec[l_one].size(); l_two++)
      cout << "vecvec[" << l_one << "][" << l_two << "] =\t"
           << vecvec[l_one][l_two] << endl;
  }
}
int main(){
  vector<int> vect; // 'vect' holds ints
  //!TODO: change '6' to any number, compile and run
  for (int nCount=0; nCount < 6; nCount++)
    vect.push_back(10 - nCount);// insert at end of array
  for (int index=0; index < vect.size(); index++)
    // print out the elements in the array
    std::cout << "vect[" << index << "]"
              << vect[index] << std::endl;
  VectorOfVector();
}
