#ifndef COEN79_ASS3
#define COEN79_ASS3

#include <iostream>

namespace coen79_assignment3
{
  class small
  {
  public:
    small() {size = 0;};
    void k() const;
    void h(int i);
    int Size();
    friend void f(small z);

  private:
    int size;
  };
}
#endif
