#include <iostream>
#include "assignment3.h"

using namespace std;

namespace coen79_assignment3
{
  int small :: Size()
  {
    return size;
  }

  void small:: k() const
  {
    small x, y;
    x = y; // LEGAL/ILLEGAL?
    x.size = y.size; // LEGAL/ILLEGAL?
    x.size = 3; // LEGAL/ILLEGAL?
  };

  void small:: h(int i)
  {

  };

  void f(small z)
  {
    small x, y;
    x = y; // LEGAL/ILLEGAL?
    x.size = y.size; // LEGAL/ILLEGAL?
    x.size = 3; // LEGAL/ILLEGAL?
    x.h(42); // LEGAL/ILLEGAL?
  };


}
