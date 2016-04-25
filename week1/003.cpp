#include <iostream>
#include <string>

class Shape{
  std::string sname;
  std::string colour;
public:
  Shape(std::string sname,
        std::string colour="red"): colour(colour)
  {
    sname = sname;
  }
  void draw();
  std::string getName() { return sname; }
};
class Circle : public Shape{
public:
  Circle(){}
};
// class Rectangle : public Shape{
// };
// class Triangle : public Shape{
// };

int main(int argc, char **argv){
  Circle circ;
  std::cout << circ.getName() << std::endl;
  return 0;
}
