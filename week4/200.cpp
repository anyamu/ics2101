// find() and list::insert
#include <iostream>
#include <list>
#include <algorithm>
#include <cstdlib>   // rand()
#include <ctime>     // time()
int main()
{
  using namespace std;
  srand(time(NULL));       // initialise the PRNG
  int i = 0;
  list<int> li;
  for (int count=0; count < 10; count++)
    li.push_back(rand()%10 * ((i % 2)? -1 : 1));
  list<int>::iterator it; // declare an iterator
  // for loop with iterators
  for (it = li.begin(); it != li.end(); it++)
    cout << "li[" << i++ << "] = \t" << *it << endl;
  int f;
  cout << "Enter a number to find: ";
  cin >> f;
  cout << "Inserting 111 before: " << f << endl;
  // find the value 'f' in the list
  it = find(li.begin(), li.end(), f);
  li.insert(it, 100); // insert the value '100' before 'f'
  // for loop with iterators
  for (i = 0, it = li.begin(); it != li.end(); it++)
    cout << "li[" << i++ << "] = \t" << *it << endl;
}
