#include <iostream>
#include <vector>     // vector
#include <map>
#include <string>
#include <cstdlib>   // rand()
#include <ctime>     // time()
int main()
{
  using namespace std;
  srand(time(NULL));       // initialise the PRNG
  vector<string> fruits({"apple", "orange","banana",
                         "grapes", "mango", "peach"});

  cout << "=======  map<int, string>::const_iterator =======" << endl;
  //!NOTE: the form of 'map_fruits'
  map<int, string> map_fruits;
  //!NOTE: iterator for map with key='int'; value='string'
  map<int, string>::const_iterator it; // declare an iterator
  int key = 0, i = 0;
  for(auto fruit: fruits)
    {
      key = rand()%10 * ((i++ % 2)? -1 : 1);
      cout << "Key: \t" << key << " \tValue: \t" << fruit << endl;
      //!NOTE: take note what happens when two keys are the same
      map_fruits.insert(make_pair(key, fruit));
    }
  it = map_fruits.begin(); // assign it to the start of the map
  while (it != map_fruits.end()) // while it hasn't reach the end
    {
      // print the value of the element it points to
      cout << "Key: \t"<< it->first << " \tValue: \t" << it->second << endl; 
      ++it; // and iterate to the next element
    }

  cout << "=======  map<string, int>::const_iterator =======" << endl;
  //!NOTE: the form of 'map_ints'
  map<string, int> map_ints;
  //!NOTE: iterator for map with key='string'; value='int'
  map<string, int>::const_iterator st; // declare an iterator
  //!NOTE: Example of a map with key='string'; value='int'
  int value = 0;
  for(auto fruit: fruits)
    {
      value = rand()%10 * ((i++ % 2)? -1 : 1);
      cout << "Key: \t" << fruit << " \tValue: \t" << value << endl;
      map_ints.insert(make_pair(fruit, value));
    }

  //!NOTE: map with key='string'; value='key'
  st = map_ints.begin(); // assign it to the start of the map
  while (st != map_ints.end()) // while it hasn't reach the end
    {
      // print the value of the element it points to
      cout << "Key: \t"<< st->first << " \tValue: \t" << st->second << endl; 
      ++st; // and iterate to the next element
    }
}
