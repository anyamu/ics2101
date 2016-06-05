#ifndef DRIVER_H
#define DRIVER_H

#include <string>

class Driver{
  std::string jina;
 public:
  Driver(std::string name = "Dereva");
  std::string getName();
};

#endif
