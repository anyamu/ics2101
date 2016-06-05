#include <iostream>       // std::cout
#include <stack>          // std::stack
#include <vector>         // std::vector
#include <deque>          // std::deque
#include <cstdlib>        // rand()
#include <ctime>          // time()
int main ()
{
  // random number generator with time seed
  srand(time(NULL));
  // These two will be adapted into stacks
  // deque with 3 elements & default values: 100,100,100
  std::deque<int> mydeque (3,100);
  // vector with 2 elements & default values: 200,200
  std::vector<int> myvector (2,200);
  // empty stack below
  std::stack<int> first;
  std::cout << "size of first: " << first.size() << '\n';
  // 'second' adapts 'mydeque' to a stack
  std::stack<int> second(mydeque);
  std::cout << "size of second: " << second.size() << '\n';
  // empty stack adapting a vector
  std::stack<int,std::vector<int> > third;
  // 'fourth' adapts 'myvector' to a stack
  std::stack<int,std::vector<int> > fourth (myvector);
  // rand(): generate pseudo-random numbers
  for(int i = 0; i < 10; ++i){
    third.push(rand() % 200);  // only numbers between 0-199
    fourth.push(rand() % 100); // only numbers between 0-99
  }
  std::cout << "size of third: " << third.size() << '\n';
  int i = 0;
  while(!third.empty()){
    std::cout << "third[" << i++ << "] = "
              << third.top() << std::endl;
    //!TODO: remove the line below, compile, run: = infinite loop
    third.pop();
  }
  std::cout << "size of third: " << third.size() << '\n';
  std::cout << "size of fourth: " << fourth.size() << '\n';
  //!TODO: repeat the above 8 lines for stack 'fourth'
  //       immediately below this comment.
  std::stack<int> mystack;
  for (int i=0; i<5; ++i){
    std::cout << "mystack[" << i << "] = " << i << std::endl;
    mystack.push(i);
  }
  std::cout << "size of mystack: " << mystack.size() << '\n';
  std::cout << "Popping out elements in reverse order...";
  while (!mystack.empty()){
      std::cout << ' '<< mystack.top(); // This returns last value.
      mystack.pop();                    // This destroys last value.
    }
  std::cout << '\n';
  return 0;
}
