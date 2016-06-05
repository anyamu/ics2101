#include <iostream>
#include <vector>
#include <cstdlib>   // rand()
#include <ctime>     // time()
int main()
{
  using namespace std;
  srand(time(NULL));       // initialise the PRNG
  vector<int> vect;
  int i = 0;
  for(; i < 10; i++)
    //!NOTE: we should have numbers between _ and _?
    vect.push_back((rand()%100 + 100));
  i = 0;
  vector<int>::const_iterator it; // declare an read-only iterator
  it = vect.begin(); // assign it to the start of the vector
  while (it != vect.end()) // while it hasn't reach the end
    {
      cout << "vect[" << i++ << "] = \t"
           << *it << endl; // print value 'it' points to.
      ++it; // and iterate to the next element
    }
}
