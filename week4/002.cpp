#include <iostream>
#include <deque>
using namespace std;
int main()
{
  deque<int> deq; //'deq' is a 'deque' object holding ints
  for(int nCount=0; nCount < 3; nCount++){
    deq.push_back(nCount); // insert at end of array
    deq.push_front(10 - nCount); // insert at front of array
  }
  // Print out the elements of 'deq'
  for(int nIndex=0; nIndex < deq.size(); nIndex++)
    cout << deq[nIndex] << " "; 
  cout << endl;
}
