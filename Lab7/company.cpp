// FILE: company.cpp
// CLASS implemented: company (see company.h for documentation)


#include <cassert>
#include "company.h"
#include "node.h"

//#define USEDEBUG

#ifdef USEDEBUG
#define Debug( x ) std::cout << x
#else
#define Debug( x )
#endif


/*Invariant:
1.The name of the company is stored in string varaible company_name
2.The pointer head_ptr points to the start of the list of products of the company
3.The pointer tail_ptr points to the last product of the list_tail_insert
4.The list can be empty


*/
namespace coen79_lab7
{
    company::company() {
        this->company_name = "";
        this->head_ptr = NULL;
        this->tail_ptr = NULL;
    }

    company::company(const std::string& company_name) {
        assert(company_name.length() > 0);

        // COMPLETE THE IMPLEMENTATION...
        this->company_name = company_name;
        this->head_ptr = NULL;
        this->tail_ptr = NULL;
    }

    //uses the equal Operator (=) to make a copy of the compoany varaible src
    company::company(const company &src) {
        Debug("Company copy constructor..." << std::endl);

        // COMPLETE THE IMPLEMENTATION...
        *this = src;

    }

    //reassign head_ptr and tail_ptr to point to a list of elements that is a copy of src
    //return the varaible pointer that called this function after assignment
    company& company::operator= (const company &src) {
        Debug("Company assignemnt operator..." << std::endl);

        // COMPLETE THE IMPLEMENTATION...
        if(this ==  &src)
        {
          return *this;
        }

        list_clear(head_ptr);
        tail_ptr = NULL;
        head_ptr = NULL;

        this->company_name = src.get_name();
        list_copy(src.head_ptr, head_ptr, tail_ptr);


        return *this;
    }


    company::~company() {
        list_clear(head_ptr);
    }


    std::string company::get_name() const {
        return company_name;
    }

    const node *company::get_head() const {
        return head_ptr;
    }

    const node *company::get_tail() const {
        return tail_ptr;
    }

    node* company::get_head() {
        return head_ptr;
    }

    node* company::get_tail() {
        return tail_ptr;
    }

    void company::print_items() {
        list_print(head_ptr);
    }

    //If no product yet, initialize a new product list with the product_name and price
    //If already have a list, insert the product_name and price at the end
    //return true if an item is successfully inserted
    bool company::insert(const std::string& product_name, const float& price) {

        assert(product_name.length() > 0);

        if (list_contains_item(head_ptr, product_name)) {
            return false;
        }

        if (head_ptr == NULL) {
            // COMPLETE THE IMPLEMENTATION...
            list_init(head_ptr, tail_ptr, product_name, price);
        }
        else {
            // COMPLETE THE IMPLEMENTATION...
            list_tail_insert(tail_ptr, product_name, price);
        }

        return true;
    }

    //if there is at least one element and that the list contains the products
    //we erase the product_name
    bool company::erase(const std::string& product_name) {
        assert(product_name.length() > 0);

        // COMPLETE THE IMPLEMENTATION...
        if(head_ptr == NULL)
        {
          return false;
        }

        node *cursor = head_ptr;
        node *cursor2 = cursor->getLink();
        node* deleted = NULL;
        while(cursor->getLink() != NULL)
        {
          if(head_ptr->getName() == product_name)
          {
            list_head_remove(head_ptr);

            return true;
          }
          else
          {
              if(cursor2->getName() == product_name)
              {
                deleted = cursor2;
                cursor->setLink(deleted->getLink());

                delete deleted;

              }

              return true;
          }

          cursor = cursor->getLink();
          cursor2 = cursor->getLink();
        }

        return false;
    }


}
