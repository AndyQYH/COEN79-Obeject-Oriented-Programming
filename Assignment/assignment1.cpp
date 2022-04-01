#include <iostream>
#include "assignment1.h"

using namespace std;

namespace coen79_assignment1
{

    polar_coord :: polar_coord(double next_r, double next_angle)
    {
      r = next_r;
      angle = next_angle;
    }
    double polar_coord :: get_r() const
    {
      return r;
    }
    double polar_coord :: get_angle() const
    {
      return angle;
    }
    void polar_coord :: set_angle(double next_angle)
    {
      angle = next_angle;
    }

    point :: point(double initial_x, double initial_y)
    {
      x = initial_x;
      y = initial_y;
    }

    void point :: set_x(double& value)
    {
      x = value;
    }

    void point :: set_y(double& value)
    {
      y = value;
    }

    point point :: operator+ (double& in) const
    {
      return point(x + in, y + in);
    }
}
