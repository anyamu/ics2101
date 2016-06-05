#include <iostream>
#include <string>

//!TODO: remove the 'virtual' keyword from the methods, compile,
//       run and take note of the results.
class Pen {
  std::string pen_name;
public:
  Pen(std::string pen_name = "Pen"){
    //!TODO: remove the 'this->' part, compile and
    //       observe the results!
    this->pen_name = pen_name;
  }
  // No need to make this 'virtual' since it is not 'overriden'
  // by derived/child/sub classes.
  std::string getName(){
    return pen_name;
  }
  virtual std::string drawLine();
  virtual std::string drawCircle();
};
std::string Pen::drawLine(){
  return getName().append(" draws a line.");
}
std::string Pen::drawCircle(){
  return getName().append(" draws a circle.");
}

class FountainPen : public Pen {
public:
  /////////////////////////////////////////////////////////////
  // //!TODO: what would happen if you used this version of  //
  // //       Constructor in the comment box below           //
  // /////////////////////////////////////////////////////// //
  // // FountainPen(std::string pen_name = "FountainPen") // //
  // //   : Pen(pen_name) {}                              // //
  // /////////////////////////////////////////////////////// //
  /////////////////////////////////////////////////////////////
  FountainPen(std::string pen_name)
    : Pen(pen_name) {}
  FountainPen() : Pen(std::string("FountainPen")){}
  virtual std::string drawLine();
  virtual std::string drawCircle();
};
std::string FountainPen::drawLine(){
  return getName().append(" draws a line.");
}
std::string FountainPen::drawCircle(){
  return getName().append(" draws a circle.");
}

class RollerBallPen : public Pen{
public:
  RollerBallPen(std::string pen_name)
    : Pen(pen_name) {}
  RollerBallPen() : Pen(std::string("RollerBallPen")){}
  virtual std::string drawLine() {
    return getName().append(" draws a line.");
  }
  virtual std::string drawCircle(){
    return getName().append(" draws a circle.");
  }
};

using namespace std;

void WriteWithPen(Pen &pen){
  cout << pen.drawLine() << endl;
  cout << pen.drawCircle() << endl;
}

int main(){
  FountainPen fp;
  WriteWithPen(fp);
  RollerBallPen rbp("A Pen that Uses a Roller Ball");
  WriteWithPen(rbp);
  Pen pen;
  WriteWithPen(pen);
}
