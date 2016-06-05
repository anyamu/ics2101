#include <iostream>
#include <set> // provides the std::set container
// templatise the function below
bool fncomp (int lhs, int rhs) {
  return lhs<rhs;
}
// templatise the struct below
struct classcomp {
  bool operator() (const int& lhs, const int& rhs) const
  {
    return lhs < rhs;
  }
};
//!NOTE: Should work with templatised fncomp, classcomp
void ExampleOfUsingClassComp(){
  classcomp<int> cc; // explicit object 'cc'
  std::cout << "classcomp(4, 2) = " << cc(4, 2) << std::endl;
  // The call below also works by creating a temporary object
  std::cout << "classcomp<double>()(2.253, 2.255) = "
            <<  classcomp<double>()(2.253, 2.255)
            << std::endl;
  std::cout << "classcomp<char>()('@', 'A') = "
            <<  classcomp<char>()('@', 'A')
            << std::endl;
}
int main ()
{
  // Once you templatise the struct,
  // the function call below should work
  ExampleOfUsingClassComp();

  std::set<int> first; // empty set of ints

  int myints[]= {10,20,30,40,50};
  std::set<int> second (myints,myints+5); // range
  //!NOTE: uses 'copy constructor' to create 'third' from
  //       'second'.
  std::set<int> third (second);
  //!NOTE: uses constructor that takes iterators to create
  //       'fourth' from 'second';
  std::set<int> fourth (second.begin(), second.end());
  //!NOTE: making classcomp the Compare object
  std::set<int,classcomp> fifth;
  //!NOTE: making use of a function pointer as Compare object
  bool(*fn_pt)(int,int) = fncomp;
  std::set<int,bool(*)(int,int)> sixth (fn_pt);
  return 0;
}
