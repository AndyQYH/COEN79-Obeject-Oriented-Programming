#include "poly.h"
#include <cassert>
#include <climits>
#include <iostream>
#include <math.h>


using namespace std;
/*invariant:
  1.the largest degree with non-zero coefficient is restored in
  the variable called exponent.
  2.the array data stores the coefficients of the polynomial;
  the coefficient of degree i is stored in the ith index of data from data[0]
  to data[maximum_degree + 1].



*/
namespace coen79_lab4
{
  //HELPER FUNCTION
  void polynomial :: update_current_degree()
  {
    //check  for the largest degree with non-zero coefficient
    for(int i = MAXIMUM_DEGREE; i >= 0; i--)
    {
      if(coefficient(i) != 0)
      {
        exponent = i;
        return;//save some runtime
      }
    }
  }

  //CONSTRUCTOR
  polynomial :: polynomial(double c, unsigned int exp)
  {
    assert(exp <= MAXIMUM_DEGREE);
    exponent = exp;
    clear();
    data[exponent] = c;

  }

  //MODIFICATION MEMBER FUNCTIONS
  void polynomial :: assign_coef(double c, unsigned int exp)
  {
    assert(exp <= MAXIMUM_DEGREE);

    if(exp > exponent)
    {
      exponent = exp;
    }

    data[exp] = c;

  }
  void polynomial :: add_to_coef(double amount, unsigned int exp)
  {
    assert(exp <= MAXIMUM_DEGREE);
    data[exp] = data[exp] + amount;

    update_current_degree();
  }

  void polynomial :: clear()
  {
    for(int i = 0; i <= MAXIMUM_DEGREE; i++)
    {
	     data[i] = 0;
    }

    exponent = 0;
  }

  //CONSTANT MEMBER FUNCTIONS
  polynomial polynomial :: antiderivative() const
  {
    polynomial antiderivative;

    for(int i = 1; i <= degree(); i++)
    {
      antiderivative.assign_coef(coefficient(i) / (i + 1),i + 1);
    }

    antiderivative.update_current_degree();
    return antiderivative;

  }

  double polynomial :: coefficient(unsigned int exp) const
  {
    if(exp <= MAXIMUM_DEGREE)
    {
      return data[exp];
    }
    else
    {
      return 0;
    }
  }

  double polynomial :: definite_integral(double x0, double x1) const
  {
    return antiderivative()(x1) - antiderivative()(x0);
  }

  unsigned int polynomial :: degree() const
  {
    return exponent;
  }

  polynomial polynomial :: derivative() const
  {
    polynomial derivative;

    for(int i = 0; i < degree(); i++)
    {
      derivative.assign_coef(coefficient(i + 1) * (i + 1),i);
    }

    derivative.update_current_degree();
    return derivative;

  }

  double polynomial :: eval(double x) const
  {
    double sum = 0;
    for(int i = 0; i <= degree(); i++)
    {
      if(coefficient(i) != 0)
      {
        sum = sum + pow(x, double(i)) * coefficient(i);
      }
    }

    return sum;
  }

  bool polynomial :: is_zero() const
  {
    //If f(0) evaluates to bigger than 0, it means constant term is not zero
    //vice versa
    if(eval(0) > 0)
    {
      return false;
    }

      return true;
  }

  unsigned int polynomial :: next_term(unsigned int e) const
  {
    for(int i = e + 1; i <= degree(); i++)
    {
      if(coefficient(i) != 0 )
      {
        return i;
      }
    }


    return 0;
  }

  unsigned int polynomial :: previous_term(unsigned int e) const
  {
    for(int i = e - 1; i >= 0; i--)
    {
      if(coefficient(i) != 0)
      {
        return i;
      }
    }

    return UINT_MAX;
  }

  //MEMBER OPERATORS
  double polynomial :: operator() (double x) const
  {
    return eval(x);
  }

  // NON-MEMBER BINARY OPERATORS
  polynomial operator +(const polynomial& p1, const polynomial& p2)
  {
    polynomial combined;

    int max_degree = max(p1.degree(), p2.degree());

    for(int i = 0; i <= max_degree; i++)
    {
      combined.assign_coef(p1.coefficient(i) + p2.coefficient(i), i);
    }

    combined.update_current_degree();
    return combined;
  }

  polynomial operator -(const polynomial& p1, const polynomial& p2)
  {
    polynomial combined;

    int max_degree = max(p1.degree(), p2.degree());

    for(int i = 0; i <= max_degree; i++)
    {
      combined.assign_coef(p1.coefficient(i) - p2.coefficient(i), i);
    }

    combined.update_current_degree();
    return combined;
  }

  polynomial operator *(const polynomial& p1, const polynomial& p2)
  {
    assert(p1.degree() + p2.degree() <= polynomial :: MAXIMUM_DEGREE);

    polynomial combined;

    for(int i = 0; i <= p1.degree(); i++)
    {
      for(int j = 0; j <= p2.degree(); j++)
      {
        combined.add_to_coef(p1.coefficient(i) * p2.coefficient(j),i + j);
      }
    }

    combined.update_current_degree();
    return combined;
  }


  // NON-MEMBER OUTPUT FUNCTIONS
  ostream& operator << (std::ostream& out, const polynomial& p)
  {
    int i =  p.degree();

    while(i >= 0)
    {
      if(i == p.degree())//when it is the first term
      {
	       out << p.coefficient(i);
      }

      //when degree is positive and coefficient is not 0
      if(p.coefficient(i) > 0 && i != p.degree())
      {
         out << " + " << p.coefficient(i);
      }

      //when degree is negative and coefficient is not 0
      if(p.coefficient(i) < 0 && i != p.degree())
      {
         out << " - " << (-1 * p.coefficient(i));
      }

      //when degree is 1 and coefficient is not 0
      if(p.coefficient(i) != 0 && i > 1)
      {
         out << "X^" << abs(i);
      }

      //when degree is 0 and coefficient is not 0
      if(p.coefficient(i) != 0 && i == 1)
      {
         out << "X";
      }

      i--;
    }

    out << endl;
    return out;
  }

}
