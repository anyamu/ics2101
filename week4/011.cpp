//Compile like so: 'g++ 011.cpp -std=c++11 -o 011.exe'
#include <iostream>
#include <map>
#include <string>

int main()
{
  //!NOTE: usual way to insert elements into 'map'
  std::map<int,char> example_one = {{1,'a'}, {2,'b'}};
  //!NOTE: How to search for a 'key'
  auto search = example_one.find(2);
  if(search != example_one.end())
    std::cout << "Found: key = " << search->first    // 'key'
              << ", value = "    << search->second   // 'value'
              << std::endl;
  else
    std::cout << "Not found\n";
  std::map<std::string,int> my_map;
  // Another way to insert elements into a 'map'
  my_map["x"] = 11;
  my_map["y"] = 23;
  auto it = my_map.find("x");
  if (it != my_map.end())       // if found then print value
    std::cout << "x: " << it->second << "\n";
  it = my_map.find("z");
  if (it != my_map.end())       // if found then print value
    std::cout << "z1: " << it->second << "\n";
  //!NOTE: Accessing a non-existing element creates it!
  if (my_map["z"] == 42)        // if found then print value
    std::cout << "Oha!\n";
  //!NOTE: "z" should have been created in the 'map'.
  it = my_map.find("z");        // 
  if (it != my_map.end())       // if found then print value
    std::cout << "z2: " << it->second << "\n";
}
