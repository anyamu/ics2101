//Compile like so: 'g++ 010soln.cpp -std=c++11 -o 010soln.exe'
#include <iostream>
#include <cstring> // provides strlen()
#include <set> // provides std::set

//!NOTE: templatised function below.
template <typename T>
bool fncomp (T lhs, T rhs) {
  // was lhs < rhs;
  return lhs > rhs;
}
//!NOTE: templatised struct below.
template <typename T>
struct classcomp {
  bool operator() (const T& lhs, const T& rhs) const
  {
    // was lhs < rhs;
    return lhs > rhs;
  }
};
//!NOTE: this should work perfectly now.
void ExampleOfUsingClassComp(){
  classcomp<int> cc;
  std::cout << "classcomp(4, 2) = " << cc(4, 2) << std::endl;
  // The below also works by creating a temporary object
  std::cout << "classcomp(2.253, 2.255) = "
            << classcomp<double>()(2.253, 2.255)
            << std::endl;
  std::cout << "classcomp<char>()('@', 'A') = "
            <<  classcomp<char>()('@', 'A')
            << std::endl;
}
//!NOTE: the two implementations of 'PrintSetContents' below
template <class Iterator>
void PrintSetContents(const Iterator begin, const Iterator end){
  //!NOTE: 'auto' is a C++11 feature: cool huh!?
  for(auto iter = begin; iter != end; iter++)
    std::cout << "'" << (*iter) << "'" << " ";
  std::cout << std::endl;
}
//!NOTE: Below, we have an example of template specialisation
// for the 'std::set<char>' type. You could comment it out to
// see the difference between using it as opposed to the version
// above.
template <>
void PrintSetContents(std::set<char>::const_iterator begin,
                      std::set<char>::const_iterator end){
  //!NOTE: 'auto' is a C++11 feature: cool huh!?
  for(auto iter = begin; iter != end; iter++)
    std::cout << (*iter);
  std::cout << std::endl;
}
int main ()
{
  //!NOTE: should work perfectly now.
  ExampleOfUsingClassComp();

  // empty set that can contain ints
  std::set<int> first;

  int myints[]= {40,50,10,30,20};
  std::set<int> second (myints,myints+5);
  // This should be printed in order; set has an internal
  // comparator that 'looks' and 'works' like those given above.
  //!NOTE: We replace the for loop below with 'PrintSetContents'
  // for(std::set<int>::const_iterator cit = second.begin();
  //     cit != second.end(); cit++)
  //   std::cout << (*cit) << " ";
  // std::cout << std::endl;
  PrintSetContents(second.begin(), second.end());

  // a copy of second
  std::set<int> third (second);

  // Constructor that takes iterators
  std::set<int> fourth (second.begin(), second.end());

  // class/struct as Compare object
  std::set<int,classcomp<int> > fifth;

  // function pointer as Compare method
  bool(*fn_pt)(int,int) = fncomp;
  std::set<int,bool(*)(int,int)> sixth (second.begin(),
                                        second.end(), fn_pt);
  // Should print elements reversed
  for(std::set<int,bool(*)(int,int)>::iterator it = sixth.begin();
      it != sixth.end(); it++)
    std::cout << (*it)  << " ";
  std::cout << std::endl;

  char str[] = "For... He's a Jolly Good Fellow!.."
               "For He's a Jolly Good Fellow!..."
               "And so say all of us, and so say all of us."
               "I WISH TO WISH THE WISH YOU WISH TO WISH,"
               "BUT IF YOU WISH THE WISH THE WITCH WISHES, "
               "I WON'T WISH THE WISH YOU WISH TO WISH."
               "@#^&@)*(^%$#!$#&(*#!@$#!~~`1;/.,''`)";
  std::set<char> chara(str, str + strlen(str));
  //!NOTE: We replace the for loop below with 'PrintSetContents'
  // for(std::set<char>::const_iterator cch = chara.begin();
  //     cch != chara.end(); cch++)
  //   std::cout << (*cch);
  // std::cout << std::endl;
  //!TODO: comment out the line below, compile & run. Note what
  //       happens.
  PrintSetContents(chara.begin(), chara.end());
  return 0;
}
