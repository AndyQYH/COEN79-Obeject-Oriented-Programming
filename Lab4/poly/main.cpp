#include <iostream>
#include "poly.h"

using namespace coen79_lab4;
using namespace std;

int main()
{
  polynomial A, B, C;
  double integralA, integralB;

  A.assign_coef(2,1);
  A.assign_coef(-3,1);
  A.assign_coef(2,1);
  A.assign_coef(-5,3);

  B = A.antiderivative();
  C = B.antiderivative();

  integralA = A.definite_integral(0,2);
  integralB = B.definite_integral(0,2);



  cout << A << endl;
  cout << B << endl;
  cout << C << endl;
  cout << integralA << endl;
  cout << integralB << endl;






  return 0;
}
