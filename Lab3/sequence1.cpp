#include "sequence1.h"
#include <iostream>
#include <cassert>
#include <algorithm>
#include <math.h>

using namespace std;
/*Invariant:
The number of items in  the sequence is stored in the variable called used;
outside programs can call the size() function to get the value of get_user_command
Everytime a change is made to the sequence, a iterator, called index, keeps track of
what the current position is on the sequence.
The items are not randomly stored; instead they are sorted in the first N (N= used) slots
The item automatically shifts to the right location after change.
*/
namespace coen79_lab3
{
  //CONSTRUCTOR
  sequence :: sequence()
  {
    used = 0;
    index = 0;
  }

  //MODIFICATION MEMBER FUNCTIONS
  void sequence :: start()
  {
    index = 0;
  }
  void sequence :: last()
  {
    assert(used > 0);
    index = used - 1;
  }
  void sequence :: end()
  {
    index = CAPACITY - 1;
  }
  void sequence :: advance()
  {
    assert(is_item() == true);
    if(index != CAPACITY - 1)
    {
      index++;
    }
  }
  void sequence :: retreat()
  {
    if(index != 0)
    {
      index--;
    }
  }
  void sequence :: insert(const value_type& entry)
  {
    assert(size() < CAPACITY);
    if(is_item() == false)
    {
      insert_front(entry);
      cout << "Insert at front" << endl;
    }
    else
    {
      cout << "Insert at current" << endl;
      for(int i = size(); i > index; i--)
      {
        data[i] = data[i - 1];
      }
      data[index] = entry;
      used++;
    }

      cout << "Size:" << used << endl;
      cout << "Index:" << index << endl;
  }

  void sequence :: attach(const value_type& entry)
  {
    assert(size() < CAPACITY);
    if(is_item() == false)
    {
      cout << "Attach back" << endl;
      attach_back(entry);
    }
    else
    {

      cout << "Attach normal" << endl;
      index++;

      for(int i = size(); i > index; i--)
      {
        data[i] = data[i - 1];
      }

      data[index] = entry;
      used++;
    }

      cout<<"index:" << index << endl;
      cout<<"size:" << used << endl;
  }

  void sequence :: remove_current()
  {
    assert(is_item() == true);
    for(int i = index; i < size(); i ++)
    {
      data[i] = data[i + 1];
    }

    used--;
  }

  void sequence :: insert_front(const value_type& entry)
  {
    assert(size() < CAPACITY);

    if(size() == 0)
    {
      index = 0;
      data[0] = entry;
    }
    else
    {
      index = 0;

      for(int i = size(); i > 0; i--)
      {
        data[i] = data[i - 1];
      }
      data[index] = entry;

    }

    used++;
  }

  void sequence :: attach_back(const value_type& entry)
  {
    assert(size() < CAPACITY);
    if(size() == 0)
    {
      index = 0;
      data[index] = entry;
    }
    else
    {
      index = size();
      data[index] = entry;
    }

    used++;
  }

  void sequence :: remove_front()
  {
    assert(is_item() == true);
    index = 0;
    for(int i = index; i < size() - 1; i++)
    {
      data[i] = data[i + 1];
    }

    used--;
  }
  
  void sequence :: operator +=(const sequence& rhs)
  {
    assert(size() + rhs.size() <= CAPACITY);

    copy(rhs.data, rhs.data + rhs.size(), data + used);

    used += rhs.used;
  }

  //CONSTANT MEMBER FUNCTIONS
  sequence :: size_type sequence :: size() const
  {
    return used;
  }

  bool sequence :: is_item( ) const
  {
    return (index < used);
  }

  sequence :: value_type sequence :: current() const
  {
    assert(is_item() == true);
    return data[index];
  }

  sequence :: value_type sequence :: operator[](int index) const
  {
    assert(index < used);
    return data[index];
  }

  double sequence :: mean() const
  {
    double sum = 0.0;
    for(int i = 0; i < size(); i++)
    {
      sum += data[i];
    }

    return sum / size();
  }

  double sequence :: standardDeviation() const
  {
    double square_mean_diff = 0.0;
    for(int i = 0; i < size(); i++)
    {
      square_mean_diff += pow(data[i] - mean(), 2.0);
    }
    return sqrt(square_mean_diff / size());
  }

  //Non-Member Functions
  sequence operator +(const sequence& lhs, const sequence& rhs)
  {
    assert(lhs.size() + rhs.size() <= CAPACITY);
    sequence combined;
    combined += lhs;
    combined += rhs;
    return combined;
  }

  sequence :: value_type summation(const sequence &s)
  {
    double sum = 0;
    for(int i = 0; i < s.size(); i++)
    {
      sum+=s[i];
    }

     return sum;
  }

}
