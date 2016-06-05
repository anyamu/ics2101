#include <iostream>
#include <list>
using namespace std;
// The List STL template requires overloading operators =, == and <.
class LstExample
{
  friend ostream &operator<<(ostream &, const LstExample &);

public:

  int x;
  int y;
  float z;
  int count;

  int getCount(){
    static int counter = 0;
    return counter++;;
  }

  LstExample();
  LstExample(const LstExample &);
  LstExample(int, int, double);
  ~LstExample(){};
  LstExample &operator=(const LstExample &rhs);
  int operator==(const LstExample &rhs) const;
  int operator<(const LstExample &rhs) const;
};
// Constructor
LstExample::LstExample(): x(0), y(0),z(0.0){ count = getCount(); }
// Copy constructor to handle pass by value.
LstExample::LstExample(const LstExample &copyin)
  :x(copyin.x), y(copyin.y), z(copyin.z){ count = getCount(); }
// Constructor
LstExample::LstExample(int x, int y, double z)
  :x(x), y(y),z(z){ count = getCount(); }

//!NOTE: the function below was declared as a friend
//       of the class LstExample and is thus not a member
//       of the class: but it can access any member variables
//       of the class!
ostream& operator<<(ostream &out, const LstExample &rhs)
{
  out << rhs.count << "]: x = " << rhs.x << ",\t"
      << "y = " << rhs.y << ",\t"
      << "z = " << rhs.z << std::endl;
   return out;
}
LstExample& LstExample::operator=(const LstExample &rhs)
{
   this->x = rhs.x;
   this->y = rhs.y;
   this->z = rhs.z;
   return *this;
}
int LstExample::operator==(const LstExample &rhs) const
{
   if( this->x != rhs.x) return 0;
   if( this->y != rhs.y) return 0;
   if( this->z != rhs.z) return 0;
   return 1;
}
// This function is required for built-in STL list functions like sort()
int LstExample::operator<(const LstExample &rhs) const
{
   if( this->x == rhs.x && this->y == rhs.y && this->z < rhs.z) return 1;
   if( this->x == rhs.x && this->y < rhs.y) return 1;
   if( this->x < rhs.x ) return 1;
   return 0;
}
int main()
{
   list<LstExample> List; // List holds elements that are LstExample type
   LstExample lstExm(7, 2, 4.2355);
   cout << "Object [#" << lstExm;

   //!NOTE: calls to 'push_back' create new objects using the copy-constructor
   List.push_back(lstExm);
   //!NOTE: Two (2) objects of 'LstExample' class are created below for each
   //       line.
   List.push_back(LstExample(5, 2, 4.2355));
   List.push_back(LstExample(5, 2, 2.2355));
   List.push_back(LstExample(3, 7, 7.2355));

   // Below we use the in-built list iterator to access an element
   // 'x' in the class LstExample.
   list<LstExample>::iterator i;
   cout << "x = [ ";
   for(i=List.begin(); i != List.end(); ++i) 
     cout << "[#" << i->count << "]="
          << (*i).x << ", ";
   cout << "]" << endl;

   cout << "=============== *List before sorting* ===============" << endl;
   // print with overloaded operator (the one declared 'friend')
   list<LstExample>::size_type j = 0;
   for(i=List.begin(); i != List.end(); ++i) 
     cout << "List[" << *i; 
   cout << endl;

   List.sort();
   cout << "=============== *List after sorting* ===============" << endl;
   // print with overloaded operator (the one declared 'friend')
   for(i=List.begin(); i != List.end(); ++i)
     cout << "List[" << *i;
   cout << endl;

   return 0;
}
