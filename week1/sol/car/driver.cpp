#include "driver.h"
Driver::Driver(std::string name)
{
  jina = name;
}
std::string Driver::getName()
{
  return jina;
}
