#include <iostream>
#include <string>
class SteeringWheel{
};
class Driver{
  std::string jina;
public:
  Driver(std::string name = "Dereva")
    : jina(name){}
  std::string getName(){ return jina; }
};
class Car{
  Driver *dere;
  SteeringWheel s_wheel;
  std::string car_type;
public:
  Car(Driver *driver = NULL,
      std::string ct) :
    dere(driver), car_type(ct){}
  Car(Driver *driver = NULL) : Car(driver, "Mercedes") {
  }
  std::string whosDriving(){
    return dere->getName()
      .append(" is driving a ")
      .append( car_type );
  }
};
using namespace std;
int main(){
  Driver *d = new Driver("Ms. Pop Diva");
  cout << "Our driver is, " << d->getName()
       << "!" << endl;
  {
    // Inside this block, object 'car' exists but is destroyed
    // once you go out of this block
    Car car(d);
    cout << car.whosDriving() << "!!" << endl;
  }
  // Has our driver survived the crash!!?
  cout << "Lone survivor: " << d->getName() << endl;
  delete d;
}
