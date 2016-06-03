#include <iostream>
#include <string>

#include "car.h"
#include "driver.h"

using namespace std;
int main(){
  Driver *d = new Driver("Ms. Pop Diva");
  {
    cout << "Our driver is, " << d->getName()
         << "!" << endl;
    // Inside this block, object 'car' exists but is destroyed
    // once you go out of this block
    Car car(d);
    cout << car.whosDriving() << "!!" << endl;
  }
  // Has our driver survived the crash!!?
  cout << "Lone survivor: " << d->getName() << endl;
  delete d;
}
