#include <iostream>
#include <string>

class Shape{
protected:
  std::string name;
public:
  Shape(std::string name = "Amorphous Base Shape"): name(name){}
  std::string getName(){ return name; }
};

class Triangle : public Shape{
public:
  Triangle(std::string name = "Nice Triangle!") : Shape(name){}
};

using namespace std;
int main(){
  Triangle tria;
  cout << tria.getName() << endl;
  return 0;
}
