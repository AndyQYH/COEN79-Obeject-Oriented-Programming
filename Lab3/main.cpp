#include <cctype>       // Provides toupper
#include <iostream>     // Provides cout and cin
#include <cstdlib>      // Provides EXIT_SUCCESS
#include "sequence1.h"  // With value_type defined as double

using namespace std;
using namespace coen79_lab3;

int main()
{

  sequence test1, test2, test3;
  test1.insert(2);
  test1.insert(4);
  test1.insert(6);
  cout << "size:" << test1.size() << endl;
  cout << "Mean:" << test1.mean() << endl;
  cout << "Std: " << test1.standardDeviation() << endl;

  test1 += test1;

  cout << "size:" << test1.size() << endl;
  cout << "Mean:" << test1.mean() << endl;
  cout << "Std: " << test1.standardDeviation() << endl;


  test2.insert(4);
  test2.insert(8);
  test2.insert(12);
  test2.insert(22);
  cout << "size: " << test2.size() << endl;
  cout << "Mean:" << test2.mean() << endl;
  cout << "Std: " << test2.standardDeviation() << endl;

  test3 = test1 + test2;

  cout << "size:" << test3.size() << endl;
  cout << "Mean:" << test3.mean() << endl;
  cout << "Std: " << test3.standardDeviation() << endl;


  double sum1 = summation(test1);
  double sum2 = summation(test2);
  double sum3 = summation(test3);
  cout << "sum1: " << sum1 << endl;
  cout << "sum2: " << sum2 << endl;
  cout << "sum3: " << sum3 << endl;



}
