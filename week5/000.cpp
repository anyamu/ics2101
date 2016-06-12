#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cassert> // assert()
class PotPart{
public:
  enum PPart{HANDLE, LID, SNOUT, NPARTS};
  PotPart(PPart id) : id(id){}
  friend std::ostream&
  operator<<(std::ostream&, const PotPart&);
private:
  static std::string parts[NPARTS];
  PPart id;
};
//!NOTE: note the two constructs below and compare them in
//       `class PotPart' above.
std::string PotPart::parts[NPARTS] = {"Handle","Lid", "Snout"};
std::ostream&
operator<<(std::ostream& out, const PotPart& pot){
  return out << pot.parts[pot.id];
}
class Pot{
  std::vector<PotPart*> parts;
public:
  ~Pot();
  void addPart(PotPart* part){ parts.push_back(part); }
  friend std::ostream&
  operator<<(std::ostream&, const Pot&);
};
//!NOTE: compare with above declaration
std::ostream&
operator<<(std::ostream& out, const Pot& pot){
  out << " has [";
  for(auto part: pot.parts) out << (*part) << ' ';
  return out << ']';
}
class PotBuilder{ //!NOTE: the `builder' class.
protected:
  Pot* pot;
public:
  PotBuilder(): pot(0){}
  void createPot(){ pot = new Pot; }
  //!NOTE: below, we have pure virtual functions :)
  virtual void buildHandle() = 0;
  virtual void buildLid() = 0;
  virtual void buildSnout() = 0;
  virtual std::string getPotName() const = 0;
  Pot* getPot(){
    Pot* newpot = pot;
    pot = 0;
    return newpot;
  }
};
class TumblerBuilder : public PotBuilder{
public:
  void buildHandle(){
    pot->addPart(new PotPart(PotPart::HANDLE));
  }
  void buildLid(){}  //!NOTE: cups without lids
  void buildSnout(){}//!NOTE: cups without snouts
  std::string getPotName() const{
    return "Water Tumbler";
  }
};
class ClayPotBuilder : public PotBuilder{
  void buildHandle(){
    pot->addPart(new PotPart(PotPart::HANDLE));
  }
  void buildLid(){
    pot->addPart(new PotPart(PotPart::LID));
  }
  void buildSnout(){
    pot->addPart(new PotPart(PotPart::SNOUT));
  }
  std::string getPotName() const{
    return "Clay Pot";
  }
};
class Potter{
  PotBuilder* builder;
public:
  Potter() : builder(0){}
  void setBuilder(PotBuilder* builder){
    this->builder = builder;
  }
  void make(){
    assert(builder);
    builder->createPot();
    builder->buildHandle();
    builder->buildLid();
    builder->buildSnout();
  }
};
using namespace std;
Pot *
makeAPot(Potter& potter, PotBuilder* pattern){
  potter.setBuilder(pattern);
  potter.make();
  Pot* pot = pattern->getPot();
  cout << "Made a " << pattern->getPotName() << endl;
  return pot;
}
int main(){
  map<string, int> kitchen;
  kitchen["tumblers"] = 4;
  kitchen["pots"]     = 2;

  vector<Pot*> containers;
  ClayPotBuilder* cpb = new ClayPotBuilder;
  TumblerBuilder* tmb = new TumblerBuilder;
  Potter potter;
  map<string, int>::const_iterator cit = kitchen.begin();
  while(cit != kitchen.end()){
    PotBuilder* pattern;
    if(cit->first == "tumblers")
      pattern = tmb;
    else if(cit->first == "pots")
      pattern = cpb;
    for(int i = 0; i < cit->second; ++i)
      containers.push_back(makeAPot(potter, pattern));
    ++cit;
  }
  delete tmb;
  delete cpb;
  int i = 0;
  for(auto container: containers)
    cout << "Container " << i++
         << " " << (*container) << endl;
}
