#include <iostream>
#include <list>
using namespace std;
int main()
{
  list<int> L;
  L.push_back(0);          // Inserts "0" at 'X': [X] = [0]
  L.push_front(0);         // Inserts "0" at 'X': [X, 0] = [0, 0]
  L.insert(++L.begin(),2); // Inserts "2" at 'X':  [0, X, 0] = [0, 2, 0]
  // L.insert(L.begin(),2);   Inserts "2" at 'X':  [X, 0, 0] = [2, 0, 0]
  L.push_back(5);  // Inserts "5" at 'X': [0, 2, 0, X]
  L.push_back(6);  // Inserts "6" at 'X': [0, 2, 0, 5, X]
  L.insert(L.end(),7); // == L.push_back(7);
  list<int>::iterator i;  // An iterator to iterate-through the list
  for(i=L.begin(); i != L.end(); ++i)
    cout << *i << " ";
  cout << endl;
  return 0;
}
