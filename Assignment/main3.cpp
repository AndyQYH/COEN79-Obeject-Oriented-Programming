#include <iostream>
#include <string>
#include <math.h>
#include "assignment3.h"
//#include "assignment3.cpp"

using namespace std;
using namespace coen79_assignment3;


namespace coen79_assignment3
{
  class Computer {
    int Id;
  public:
    Computer(int id) { this->Id = id; }
    void process() { cout << "Computer::process()" << Id; }
  };

  class Employee {
    Computer* c;

  public:
    Employee() { c = new Computer(123); }
    ~Employee() {}
    void foo() {
      cout << "Employee::foo()";
      c -> process();
    }
  };

  class box {

  public:
    // Constructor definition
    box(double l = 2.0, double b = 2.0, double h = 2.0) {
      length = l;
      breadth = b;
      height = h;
      count++;

      cout << "Number of box objects created so far:" << count << endl;
 }

      double volume() {
        return length * breadth * height; }

  private:
    double length;
    double breadth;
    double height;
    static int count;
 };

  int box :: count = 0;

}


  int main()
  {
    small x, y;
    x = y; // LEGAL/ILLEGAL?
    ///x.size = y.size; // LEGAL/ILLEGAL?
    //x.size = 3; // LEGAL/ILLEGAL?
    x.h(42);  // LEGAL/ILLEGAL?
    x.k();
    f(x);

    cout << "size of x : " <<  x.Size() <<endl;

    Employee ob;
    ob.foo();

    Computer ojbk(345);
    ojbk.process();

    box Box1(3.3, 1.2, 1.5); // Declare box1

    box Box2(8.5, 6.0, 2.0); // Declare box2

    return 0;
  }
