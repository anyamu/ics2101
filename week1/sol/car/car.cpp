#include "car.h"

std::string Car::whosDriving(){
  return dere->getName()
    .append(" is driving a ")
    .append( car_type );
}
