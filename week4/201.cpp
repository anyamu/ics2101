//sort() and reverse()
#include <iostream>
#include <vector>
#include <algorithm> // sort(); reverse()
#include <cstdlib>   // rand()
#include <ctime>     // time()
int main()
{
  using namespace std;
  srand(time(NULL));       // initialise the PRNG
  vector<int> vect;
  for(int i = 0; i < 10; i++)
    vect.push_back(rand()%10 * ((i % 2)? -1 : 1));
  int i = 0;
  vector<int>::const_iterator it; // declare an iterator
  cout << "========== *before sort* ==========" << endl;
  // for loop with iterators
  for (it = vect.begin(); it != vect.end(); it++)
    cout << "vect[" << i++ << "] = \t" << *it << endl;
  cout << "========== *after sort* ==========" << endl;
  sort(vect.begin(), vect.end()); // sort the list
  // for loop with iterators
  for (i = 0, it = vect.begin(); it != vect.end(); it++)
    cout << "vect[" << i++ << "] = \t" << *it << endl;
  cout << "========== *after reverse* ==========" << endl;
  reverse(vect.begin(), vect.end()); // reverse the list
  // for loop with iterators
  for (i = 0, it = vect.begin(); it != vect.end(); it++)
    cout << "vect[" << i++ << "] = \t" << *it << endl;
}
