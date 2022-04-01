#ifndef ASS1_H     // Prevent duplicate definition
#define ASS1_H
#include <iostream>

namespace coen79_assignment1
{
  class polar_coord
  {
  private:
      double r, angle;

  public:
    polar_coord(double next_r = 0, double next_angle = 0);
    double get_r() const;
    double get_angle() const;
    void set_angle(double next_angle);
  };

  class point
  {
  private:
    double x,y;

  public:
    point(double initial_x = 0.0, double initial_y = 0.0);
    void set_x(double& value);
    void set_y(double& value);

    point operator+ (double& in) const;
  };

}

#endif
