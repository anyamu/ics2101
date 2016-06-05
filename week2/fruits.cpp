#include <iostream>

class CitrusFruit{
protected:
  float ph;
public:
  CitrusFruit(float ph) : ph(ph){}
  const char * getName(){ return "Citrus Fruit";}
  float getPh(){ return ph;  }
};

class Lemon : public CitrusFruit {
public:
  Lemon(float ph) : CitrusFruit(ph){}
  const char * getName(){ return "Lemon Fruit";}
  float getPh(){ return ph * 2.0;  }
};

using namespace std;
int main(){
  Lemon lemon(2.0);
  //This is perfectly legal!
  CitrusFruit &rlemon = lemon;
  CitrusFruit *plemon = &lemon;
  cout << "lemon is a " << lemon.getName()
       << " and has a pH " << lemon.getPh() << endl;
  cout << "rlemon is a " << rlemon.getName()
       << " and has a pH " << rlemon.getPh() << endl;
  cout << "plemon is a " << plemon->getName()
       << " and has a pH " << plemon->getPh() << endl;
  }
