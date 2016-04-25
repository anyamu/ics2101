#include <iostream>
#include <string>

class Student {
  std::string name;
  std::string id;
public:
  Student(std::string name, std::string id) :
    name(name), id(id){}
  std::string getName(){ return name; }
  //!TODO Write the getId() method
};
class University {
  Student *stud;
  std::string name;
public:
  University(std::string name, Student *stud)
    : name(name), stud(stud) {}
  University(Student *stud = NULL)
    : University("Strathmore University", stud) {}
  //!TODO Write a method getAllStudents() that prints the
  // Name of the University and all the students at the
  // university
  //!TODO Write a method that yields the name of the
  // university
};

using namespace std;

int main(){
  Student *stud = new Student("Mr. Smart Student", "00001");
  cout << "Student name: " << stud->getName()
       << " has Student ID: " << stud->getId() << endl;
  {
    University uni(stud);
    uni.getAllStudents();
  }
  cout << stud->getName() << " ID: " << stud->getId()
       << " will be out of school soon" << endl;
  return 0;
}
