// FILE: node.cpp
//
//
//  COEN 79
//  --- Farokh Eskafi, COEN, SCU ---
//
//
// IMPLEMENTS: The functions of the node class and the
// linked list toolkit (see node1.h for documentation).
//
// INVARIANT for the node class:
//   The data of a node is stored in data_field
//   and the link to the next node is stored in link_field.

#include "node.h"
#include <cassert>    // Provides assert
#include <cstdlib>
#include <iostream>    // Provides NULL and size_t

using namespace std;

namespace coen79_lab6
{
    size_t list_length(const node* head_ptr)
    // Library facilities used: cstdlib
    {
	     const node *cursor;
	      size_t answer;

	       answer = 0;
	       for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
	       ++answer;

	        return answer;
    }

    void list_head_insert(node*& head_ptr, const node::value_type& entry)
    {
    	head_ptr = new node(entry, head_ptr);
    }

    void list_insert(node* previous_ptr, const node::value_type& entry)
    {
    	node *insert_ptr;

    	insert_ptr = new node(entry, previous_ptr->link( ));
    	previous_ptr->set_link(insert_ptr);
    }

    node* list_search(node* head_ptr, const node::value_type& target)
    // Library facilities used: cstdlib
    {
    	node *cursor;

    	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
    	    if (target == cursor->data( ))
        		return cursor;

    	return NULL;
    }

    const node* list_search(const node* head_ptr, const node::value_type& target)
    // Library facilities used: cstdlib
    {
    	const node *cursor;

    	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
    	    if (target == cursor->data( ))
        		return cursor;

    	return NULL;
    }

    node* list_locate(node* head_ptr, size_t position)
    // Library facilities used: cassert, cstdlib
    {
    	node *cursor;
    	size_t i;

    	assert (0 < position);
    	cursor = head_ptr;
    	for (i = 1; (i < position) && (cursor != NULL); i++)
    	    cursor = cursor->link( );

    	return cursor;
    }

    const node* list_locate(const node* head_ptr, size_t position)
    // Library facilities used: cassert, cstdlib
    {
    	const node *cursor;
    	size_t i;

    	assert (0 < position);
    	cursor = head_ptr;
    	for (i = 1; (i < position) && (cursor != NULL); i++)
    	    cursor = cursor->link( );

    	return cursor;
    }

    void list_head_remove(node*& head_ptr)
    {
    	node *remove_ptr;

    	remove_ptr = head_ptr;
    	head_ptr = head_ptr->link( );
    	delete remove_ptr;
    }

    void list_remove(node* previous_ptr)
    {
    	node *remove_ptr;

    	remove_ptr = previous_ptr->link( );
    	previous_ptr->set_link( remove_ptr->link( ) );
    	delete remove_ptr;
    }

    void list_clear(node*& head_ptr)
    // Library facilities used: cstdlib
    {
    	while (head_ptr != NULL)
    	    list_head_remove(head_ptr);
    }

    void list_copy(const node* source_ptr, node*& head_ptr, node*& tail_ptr)
    // Library facilities used: cstdlib
    {
    	head_ptr = NULL;
    	tail_ptr = NULL;

    	// Handle the case of the empty list.
    	if (source_ptr == NULL)
    	    return;

    	// Make the head node for the newly created list, and put data in it.
    	list_head_insert(head_ptr, source_ptr->data( ));
    	tail_ptr = head_ptr;

    	// Copy the rest of the nodes one at a time, adding at the tail of new list.
    	source_ptr = source_ptr->link( );
    	while (source_ptr != NULL)
    	{
    	    list_insert(tail_ptr, source_ptr->data( ));
    	    tail_ptr = tail_ptr->link( );
    	    source_ptr = source_ptr->link( );
    	}
    }

    //copy all the link field starting from start_ptr to the link before end_ptr
    //to the newly allocated node list starting with head_ptr to end_ptr
    void list_piece(node* start_ptr, node* end_ptr, node*& head_ptr, node*& tail_ptr)
    {
      head_ptr = NULL;
      tail_ptr = NULL;

      if(start_ptr == NULL || start_ptr == end_ptr)
      {
        return;
      }

      if(start_ptr != NULL && end_ptr == NULL)
      {
        list_copy(start_ptr,head_ptr,tail_ptr);
      }
      else
      {
        //start a new list
        list_head_insert(head_ptr, start_ptr->data());
        tail_ptr = head_ptr;

        //copy each piece into the new list
        start_ptr = start_ptr->link();
        while(start_ptr != NULL && start_ptr != end_ptr)
        {
          list_insert(tail_ptr, start_ptr->data());
          tail_ptr = tail_ptr->link();
          start_ptr = start_ptr->link();
        }
      }

    }

    //count the total number of occurences of a value in the list
    //start from head and end when there is not anything more
    //If there is a loop, when stop when we went through the loop node twice
    //return the number of occurences
    size_t list_occurrences(node* head_ptr, const node::value_type& target)
    {
      const node *cursor;
      size_t count = 0;
      size_t loop_node = 0;

    	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link())
      {
        if (target == cursor->data( ))
          count++;
        if(cursor == list_detect_loop(head_ptr))
          loop_node++;
        if(loop_node == 2)
          break;
      }

    	return count;
    }

    //insert value entry at the specified location
    //adjust pointer links accoeding to situations
    void list_insert_at(node*& head_ptr, const node::value_type& entry, size_t position)
    {
      assert(position > 0 && position <= list_length(head_ptr) + 1);

      if(position == 1)
      {
        list_head_insert(head_ptr, entry);
      }
      else
      {
        list_insert(list_locate(head_ptr, position - 1), entry);
      }


    }

    //remove the node at position if applicable
    //adjust pointer links accordingly
    //return the deleted data
    node::value_type list_remove_at(node*& head_ptr, size_t position)
    {
      assert(position > 0 && position <= list_length(head_ptr));

      node :: value_type deleted_data = list_locate(head_ptr, position)->data();

      if(position == 1)
      {
        list_head_remove(head_ptr);
      }
      else
      {
        list_remove(list_locate(head_ptr, position - 1));
      }

      return deleted_data;
    }

    //copy the list items from position start to finish
    //use list_piece and list_locate
    //return the new head pointer of the new list
    node* list_copy_segment(node* head_ptr, size_t start, size_t finish)
    {
      assert(start >= 1 && start <= finish && finish <= list_length(head_ptr));

      node *new_head;
      node *new_tail;

      list_piece(list_locate(head_ptr, start), list_locate(head_ptr, finish + 1), new_head, new_tail);

      return new_head;

    }

    //print the data contained in each node starting from head_ptr to the end of list
    void list_print (const node* head_ptr)
    {

      while(head_ptr != NULL)
      {
        cout << head_ptr->data();

        if(head_ptr->link() != NULL)
        {
          cout<<",";
          cout<<" ";
        }
        else
        {
          cout<<endl;
        }

        head_ptr = head_ptr->link();

      }

    }

    //remove all the nodes with duplicated values of the first node
    //that contain them
    void list_remove_dups(node* head_ptr)
    {
      node* cursor1;
      node* cursor2;
      node::value_type data1,data2;
      cursor1 = head_ptr;
      cursor2 = head_ptr;

      while(cursor1 != NULL)
      {
        data1 = cursor1->data();


        while(cursor2->link() != NULL)
        {
          data2 = cursor2->link()->data();
          if(data2 == data1)
          {
            list_remove(cursor2);
          }

        }

        cursor1 = cursor1->link();
      }

    }

    //check if the list has a loop_node
    //return the node where the loop starts
    node* list_detect_loop (node* head_ptr)
    {
      node *slow_p = head_ptr, *fast_p = head_ptr;

      while (slow_p && fast_p && fast_p->link())
      {
        slow_p = slow_p->link();
        fast_p = fast_p->link()->link();
        if(slow_p == fast_p)
        {
            break;
        }
      }

      if(slow_p == NULL || fast_p->link() == NULL)
      {
        return NULL;
      }

      slow_p = head_ptr;

      while(slow_p != fast_p)
      {
        slow_p = slow_p->link();
        fast_p = fast_p->link();
      }
      return fast_p;

    }

}
