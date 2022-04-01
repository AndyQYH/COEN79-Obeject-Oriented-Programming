#include "node.h"
#include "sequence.h"
#include <iostream>
#include <cassert>
#include <cstdlib>

using namespace std;
using namespace coen79_lab6;

namespace coen79_lab6
{
  // CONSTRUCTORS and DESTRUCTOR
  sequence :: sequence()
  {
    this->init();
  }

  sequence :: sequence(const sequence& source)
  {
    this->init();

    *this = source;


    many_nodes = source.many_nodes;
  }

  sequence :: ~sequence()
  {
    list_clear(head_ptr);
    many_nodes = 0;
  }

  // MODIFICATION MEMBER FUNCTIONS
  void sequence :: start()
  {
    cursor = head_ptr;
    precursor = NULL;

  }

  void sequence :: end()
  {
    while(cursor != tail_ptr)
    {
      this->advance();
    }
  }

  void sequence :: advance()
  {
    assert(this->is_item() == true);

    precursor = cursor;
    cursor = cursor->link();

  }

  //add a new node before the cursor after the precursor
  //if no current, add to the front
  //adjust pointer links
  void sequence :: insert(const value_type& entry)
  {
    if(cursor == NULL && precursor == NULL)
    {
      list_head_insert(head_ptr, entry);
      cursor = head_ptr;
      precursor = NULL;
      tail_ptr = head_ptr;
    }
    else if(cursor == NULL && precursor != NULL)
    {
        list_head_insert(head_ptr, entry);
        tail_ptr = precursor;
        cursor = head_ptr;
        precursor = NULL;

    }
    else if(cursor != NULL && precursor == NULL)
    {
        list_head_insert(head_ptr, entry);
        cursor = head_ptr;
        precursor = NULL;

    }
    else
    {
      list_insert(precursor, entry);
      cursor = precursor->link();
    }

    many_nodes++;
  }

  //add new node with new value after the curreent item
  //add a new node with new value to the bakc of the list if no current item
  void sequence :: attach(const value_type& entry)
  {
    if(this->is_item() == false)
    {
      if(many_nodes == 0)
      {
        list_head_insert(head_ptr, entry);
        cursor = head_ptr;
        tail_ptr = head_ptr;
        precursor = NULL;
      }
      else
      {
        list_insert(tail_ptr, entry);
        precursor = tail_ptr;
        cursor = tail_ptr->link();
        tail_ptr = cursor;
      }


    }
    else
    {
      list_insert(cursor, entry);
      precursor = cursor;
      cursor = cursor->link();

      if(cursor->link() == NULL)
      {
        tail_ptr = cursor;
      }

      if(precursor == NULL)
      {
        head_ptr = cursor;
      }
    }

      many_nodes++;
  }


  //set a sequence equal to another one
  //with same pointers location, list values, and length
  void sequence :: operator =(const sequence& source)
  {
    if(this == &source)
    {
      return;
    }

    list_clear(head_ptr);
    this->init();
    if(!source.is_item())
    {
      list_copy(source.head_ptr, head_ptr, tail_ptr);
      cursor = NULL;
      precursor = NULL;
    }
    else if(source.cursor == source.head_ptr)
    {
      list_copy(source.head_ptr, head_ptr, tail_ptr);
      cursor = head_ptr;
      precursor = NULL;
    }
    else
    {
      list_piece(source.head_ptr, source.cursor, head_ptr, precursor);
      list_piece(source.cursor, NULL, cursor, tail_ptr);
      precursor->set_link(cursor);
    }
  }

  //remove the node that the cursor is pointed to
  //if no current, can not removed
  //remove at head if the cursor is at the front
  //remove after if cursor is elsewhere
  void sequence :: remove_current()
  {
    assert(this->is_item() == true);

    if(many_nodes == 1)
    {
      list_head_remove(head_ptr);
      this->init();
    }
    else
    {
      if(cursor == head_ptr)
      {
        list_head_remove(head_ptr);
        cursor = head_ptr;
      }
      else
      {
        list_remove(precursor);
        cursor = precursor->link();

      }
    }

    many_nodes--;

  }

  // CONSTANT MEMBER FUNCTIONS
  sequence :: size_type sequence :: size() const
  {
    return many_nodes;
  }

  //return true if cursor is not NULL
  bool sequence :: is_item() const
  {
    if(cursor != NULL)
    {
      return true;
    }

    return false;
  }

  //if cursor is pointed to a node on the list
  //return that node's value
  sequence :: value_type sequence :: current() const
  {
    assert(this->is_item() == true);

    return cursor->data();
  }
}
