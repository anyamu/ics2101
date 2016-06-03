#ifndef CAR_H
#define CAR_H

#include <string>

#include "driver.h"

class SteeringWheel{
};

class Car{
  Driver *dere;
  SteeringWheel s_wheel;
  std::string car_type;
 public:
  //!FIX: Parameters with default arguments should
  //      appear last in the parameter list of a
  //      function/method in C++.
  /********************************************************/
  /*!WRONG: Car(Driver *driver = NULL, std::string ct)    */
  /*          : dere(driver),car_type(ct){}               */
  /********************************************************/

 Car(std::string ct, Driver *driver = NULL)
   : dere(driver),car_type(ct){}

 Car(Driver *driver = NULL)
   : Car("Mercedes", driver){}

  std::string whosDriving();
};

#endif
