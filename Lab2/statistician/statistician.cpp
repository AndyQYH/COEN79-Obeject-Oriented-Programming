// FILE: statistician.cpp
// CLASS IMPLEMENTED: statistician (see stats.h for documentation)

#include <cassert>   // Provides assert
#include <iostream>  // Provides istream class
#include "statistician.h" //header files containing implementation methods of statistician

using namespace std;

namespace coen79_lab2
{
    //create a parameterized CONSTRUCTOR
    statistician :: statistician(double init_total, double init_min, double init_max, double init_avg, int init_size)
    {
      total = init_total;
      min = init_min;
      max = init_max;
      avg = init_avg;
      size = init_size;
    }

    //add r to the total and compare r with max and min; average is also changed
    void statistician :: next(double r)
    {
        total += r;
        size++;
        if(size == 1)
        {
          min = r;
          max = r;
        }
        if(r > max)
        {
          max = r;
        }

        if(r < min)
        {
          min = r;
        }
          avg = total / ((double)size);


    }

    //clear every private variable
    void statistician :: reset()
    {
      total = 0;
      min = 0;
      max = 0;
      avg = 0;
      size = 0;
    }

    //returns the number of operations
    int statistician :: length() const
    {
      return size;
    }

    //returns the value of sum
    double statistician :: sum() const
    {
      return total;
    }

    //returns the value of avg
    double statistician :: mean() const
    {
      return avg;
    }

    //returns the value of min
    double statistician ::  minimum() const
    {
      return min;
    }

    //returns the value of max
    double statistician ::  maximum() const
    {
      return max;
    }

    //returns statistician with
    //combined sum, length of s1&s2, new min, new max, and new mean.
    statistician operator +(const statistician& s1, const statistician& s2)
    {
       double new_min, new_max, new_sum;
       int new_size;
       if(s1.minimum() < s2.minimum())
       {
         new_min = s1.minimum();
       }
       else
       {
         new_min = s2.minimum();
       }

       if(s1.maximum() > s2.maximum())
       {
         new_max = s1.maximum();
       }
       else
       {
         new_max = s2.maximum();
       }
       new_sum = s1.sum() + s2.sum();
       new_size = s1.length() + s2.length();

       return statistician (new_sum, new_min, new_max, new_sum / (double)new_size, new_size);
    }

     //returns a new statistician with
     //scaled sum, mean,length, with new max, and new min.
     statistician operator *(double scale, const statistician& s)
    {
        int new_max, new_min;
        if(scale < 0)
        {
          new_max = s.minimum() * scale;
          new_min = s.maximum() * scale;
        }
        else
        {
          new_max = scale * s.maximum();
          new_min = scale * s.minimum();
        }
        return statistician(scale * s.sum(), new_min, new_max, scale * s.mean(), s.length());
    }

    //returns true if every variable in s1 and s2 are completely the same or s1 & s2 both have length of 0
     bool operator ==(const statistician& s1, const statistician& s2)
    {
        return(s1.length() == 0 && s2.length() == 0) || (s1.length() == s2.length() && s1.minimum() == s2.minimum() && s1. maximum() == s2.maximum() && s1.sum() == s2.sum() && s1.mean() == s2.mean());
    }
}
