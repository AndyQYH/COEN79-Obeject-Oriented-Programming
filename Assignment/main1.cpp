#include <iostream>
#include <math.h>
#include "assignment1.h"

using namespace std;
using namespace coen79_assignment1;

//print out all the private varaibles of a polar point
void printPolarCoordInfo(polar_coord & p)
{
    cout << "Radius: " << p.get_r() << endl;
    cout << "Angle: " << p.get_angle() << endl;
    cout << endl;
}

//convert polar coordinate to cartesian coordinate
void toCartesian(polar_coord & p)
{
  double theta = p.get_angle() * M_PI / 180;
  cout << "In Cartesian:" << endl;
  cout << "X: " << p.get_r() * cos(theta) << endl;
  cout << "Y: " << p.get_r() * sin(theta) << endl;
  cout << endl;
}

class CMyClass {
 public:
 static int m_i;
};
 int CMyClass::m_i = 0;

 CMyClass myObject1;
 CMyClass myObject2;
 CMyClass myObject3;
//testing
int main(int argc, const char* argv[])
{
  CMyClass::m_i = 2;
  myObject1.m_i = 1;
  cout << myObject1.m_i << endl;
  cout << myObject2.m_i << endl;

  myObject2.m_i = 3;
  myObject3.m_i = 4;
  cout << myObject1.m_i << endl;
  cout << myObject2.m_i << endl;

  point myPoint1, myPoint2, myPoint3;
  double shift = 8.5;
  myPoint1 = shift + myPoint2;
  myPoint3 = myPoint1.operator+ (shift);
  myPoint1 = myPoint1 + shift;

  polar_coord p1(2, 30), p2, p3(6,0);

  cout << "Initial Values:" <<endl;
  cout << "p1:" <<endl;
  printPolarCoordInfo(p1);
  cout << "p2:" <<endl;
  printPolarCoordInfo(p2);
  cout << "p3:" <<endl;
  printPolarCoordInfo(p3);

  p1.set_angle(30);
  p2.set_angle(60);
  p3.set_angle(90);

  cout << "Modified Values:" <<endl;
  cout << "p1:" <<endl;
  printPolarCoordInfo(p1);
  toCartesian(p1);
  cout << "p2:" <<endl;
  printPolarCoordInfo(p2);
  toCartesian(p2);
  cout << "p3:" <<endl;
  printPolarCoordInfo(p3);
  toCartesian(p3);

return 0;
}
