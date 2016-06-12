#include <iostream>
#include <vector>
class Subject{
  std::vector< class Observer *> observers;
  int value; //!NOTE: the thing being observed for changes
public:
  void attach(Observer * obs){
    observers.push_back(obs);
  }
  void setValue(int val){
    value = val;
    notify();
  }
  int getValue(){ return value;  }
  void notify();
};
class Observer{
  Subject* subject;
  int denom;
public:
  Observer(Subject* subject, int denom)
    : subject(subject), denom(denom){
    //!NOTE: adds itself as an observer of subject.
    subject->attach(this); 
  }
  virtual void update() = 0;
protected:
  Subject* getSubject(){ return subject; }
  int getDivisor(){ return denom; }
};
class DivObserver : public Observer{
public:
  DivObserver(Subject* subj, int denom)
    : Observer(subj, denom){}
  void update(){
    int v = getSubject()->getValue(), d = getDivisor();
    std::cout << v << " div " << d << " = " << v/d
              << std::endl;
  }
};
void Subject::notify(){ 
  for(auto obs: observers)
    (obs)->update();
}
class ModObserver : public Observer{
public:
  ModObserver(Subject* subj, int denom)
    : Observer(subj, denom){}
  void update(){
    int v = getSubject()->getValue(), d = getDivisor();
    std::cout << v << " mod " << d << " = " << v%d
              << std::endl;
  }
};
class AddObserver : public Observer{
public:
  AddObserver(Subject* subj, int denom)
    : Observer(subj, denom){}
  void update(){
    int v = getSubject()->getValue(), d = getDivisor();
    std::cout << v << " add " << d << " = " << v+d
              << std::endl;
  }
};
using namespace std;
int main(){
  Subject subj;
  DivObserver div(&subj, 3);
  ModObserver mod(&subj, 7);
  AddObserver add(&subj, 42);
  cout << "==================== subj.setValue(20) ===================="
       << endl;
  subj.setValue(20);
  cout << "==================== subj.setValue(0) ===================="
       << endl;
  subj.setValue(0);
  cout << "==================== subj.setValue(-294) ===================="
       << endl;
  subj.setValue(-294);
}
