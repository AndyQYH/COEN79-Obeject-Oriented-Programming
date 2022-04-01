#include "keyed_bag.h"
#include <cassert>
#include <string.h>
#include <iostream>
using namespace std;

/*invariant:
1.the number of items in the bag is stored in the variable used.
2.a pair of parallel arrays are used, one for the keys of the item
 and one for the value of item. the item matching the key at keys[i] should
 be stored in data[i].
3.we do not really care about where each key is, but we do want to use each key
once only.


*/
namespace coen79_lab4
{
  keyed_bag :: keyed_bag()
  {
    used = 0;
  }

  void keyed_bag :: erase()
  {
    size_type index = 0;

    while(index < used)
    {
      --used;
      data[index] = data[used];
      keys[index] = data[used];
    }

  }

  bool keyed_bag :: erase(const key_type& key)
  {
    size_type index = 0;

    while(index < used)
    {
      if(keys[index].compare(key) == 0)
      {
        --used;
        data[index] = data[used];
        keys[index].assign(keys[used]);
        return true;
      }

        ++index;
    }
      return false;
  }

  void keyed_bag :: insert(const value_type& entry, const key_type& key)
  {
    assert(size() < CAPACITY);

    if(!has_key(key))
    {
      keys[used] = key;
      data[used] = entry;
      used++;
    }
    else
    {
      cout << "Duplicated Key, please try again" << endl;
    }
  }

  void keyed_bag :: operator +=(const keyed_bag& addend)
  {
    assert(size() + addend.size() <= keyed_bag :: CAPACITY);
    assert(hasDuplicateKey(addend) == false);

    copy(addend.data, addend.data + addend.size(), data + used);
    copy(addend.keys, addend.keys + addend.size(), keys + used);

    used += addend.used;
  }

  void keyed_bag :: printItems()
  {
    for(int i = 0; i < size(); i++)
    {
      cout << data[i] << ": ";
      cout << keys[i] << endl;
    }
  }
  //CONSTANT MEMBER FUNCTIONS
  bool keyed_bag :: has_key(const key_type& key) const
  {
    size_type index = 0;

    while(index < used)
    {
      if(keys[index].compare(key) == 0)
      {
         return true;
      }
      ++index;
    }

    return false;
  }

  keyed_bag :: value_type keyed_bag :: get(const key_type& key) const
  {
    assert(has_key(key) == true);

    size_type index = 0;

    while(index < used)
    {
      if(keys[index].compare(key) == 0)
      {
        return data[index];
      }
        ++index;
    }
  }

  keyed_bag :: size_type keyed_bag :: size() const
  {
    return used;
  }
  keyed_bag :: size_type keyed_bag :: count(const value_type& target) const
  {
    size_type index = 0;
    size_type count = 0;

    while(index < used)
    {
      if(data[index] == target)
      {
        count++;
      }
      index++;
    }

    return count;
  }

  bool keyed_bag :: hasDuplicateKey(const keyed_bag& otherBag) const
  {
    size_type index = 0;

    for(int i = 0; i < used; i++)
    {
      if(otherBag.has_key(keys[i]))
      {
        return true;
      }
    }

    return false;
  }

  //NONMEMBER FUNCTIONS
  keyed_bag operator +(const keyed_bag& b1, const keyed_bag& b2)
  {
    assert(b1.size() + b2.size() <= keyed_bag :: CAPACITY);

    keyed_bag combined;
    combined += b1;
    combined += b2;

    return combined;
  }
}
