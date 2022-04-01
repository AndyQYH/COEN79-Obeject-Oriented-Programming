// FILE: database.cpp
// CLASS implemented: database (see database.h for documentation)

// INVARIANT for the database ADT:
//   1. The items in the database are stored in a dynamic array, where each entry of the array includes
//      a company name, a pointer to the head of the linked list of products, and a
//      a pointer to the tail of the linked list of products
//   2. The number of slots in the array of companies is stored in member varibale aloc_slots
//   3. The number of used slots of the array of companies is stored in member varibale used_slots


#ifndef DATABASE_CPP
#define DATABASE_CPP

#include "database.h"


//#define USEDEBUG

#ifdef USEDEBUG
#define Debug( x ) std::cout << x
#else
#define Debug( x )
#endif

/*Invariant:
1.Company variables are stored in the company array company_array from index 0 to used_slots - 1
2.Number of company is stored in used_slots
3.Number of slots allocated in the array is stored in aloc_slots
4.We do not really care where the companies are stored in the array
*/
namespace coen79_lab7
{

    database::database(const size_type& initial_capacity) {
        used_slots = 0;
        aloc_slots = initial_capacity;
        company_array = new company[aloc_slots];
    }


    database::database(const database &src) {
        Debug("Copy constructor..." << std::endl);

        // COMPLETE THE IMPLEMENTATION...
        *this = src;
    }

    //we want to reassign the company_array pointer to a newly copied array of rhs
    //we set all member varaible to the same as the values of rhs
    //return this pointer after changes
    database& database::operator= (const database &rhs) {
        Debug("Assignment operator..." << std::endl);

        // COMPLETE THE IMPLEMENTATION...
        if(this == &rhs)
        {
          return *this;
        }


        std::cout << "copying elements of database..." ;
        company* new_array = new company[rhs.aloc_slots];
        std::copy(rhs.company_array, rhs.company_array + rhs.used_slots, new_array);
        delete[] company_array;
        company_array = new_array;

        used_slots = rhs.used_slots;
        aloc_slots = rhs.aloc_slots;
        return *this;

    }


    database::~database() {
        // COMPLETE THE IMPLEMENTATION...

        delete[] company_array;
    }

    //allocate memory when necessary for larger new_capacity
    void database::reserve(size_type new_capacity) {
        Debug("Reserve..." << std::endl);

        if (new_capacity == aloc_slots)
            return; // The allocated memory is already the right size.

        if (new_capacity < used_slots)
            new_capacity = used_slots; // Canít allocate less than we are using.

        // COMPLETE THE IMPLEMENTATION...
        company *larger_array = new company[new_capacity];
        std::copy(company_array, company_array + used_slots, larger_array);
        delete[] company_array;
        company_array = larger_array;
        aloc_slots = new_capacity;


    }

    //insert a new company with name entry
    //allocate new space if there is no more slot avaiable
    //return true is insertion is successful
    bool database::insert_company(const std::string &entry) {

        Debug("Insert company..." << std::endl);

        assert(entry.length() > 0);
        size_type pos = search_company(entry);
        // If you find a company that is false, because there are duplicates
        if (pos != COMPANY_NOT_FOUND) {
            return false;
        }


        // COMPLETE THE IMPLEMENTATION...
        if(used_slots < aloc_slots)
        {
          company_array[used_slots] = company(entry);
          used_slots++;
          return true;
        }
        else
        {
          this->reserve(aloc_slots + 1);
          company_array[used_slots] = company(entry);
          used_slots++;

          return true;
        }

          return false;
    }

    //if the company_name company is presented, we insert the item produc_name and product price price
    //into the list of that company_name
    //return true if insertion is successful
    bool database::insert_item(const std::string &company, const std::string &product_name, const float &price) {
        Debug("Insert item..." << std::endl);

        assert(company.length() > 0 && product_name.length() > 0);

        // COMPLETE THE IMPLEMENTATION...
        size_type pos = search_company(company);

        // If you find a company that is false, because there are duplicates
        if (pos != COMPANY_NOT_FOUND) {
           company_array[pos].insert(product_name,price);
           return true;
        }
        return false;
    }

    //If the array has more than one company adn that the company is found in the new_array
    //We remove that company from the company_array
    //return true of removal is successful
    bool database::erase_company(const std::string &company) {

        size_type company_index = search_company(company);

        // COMPLETE THE IMPLEMENTATION...

        // If you find a company that is false, because it does not exist
        if (company_index == COMPANY_NOT_FOUND) {
            return false;
        }

        if(used_slots == aloc_slots && company_index == used_slots - 1)
        {
          used_slots--;
        }
        else
        {
          for(int i = company_index; i < used_slots - 1; i++)
          {
            company_array[i] = company_array[i + 1];
          }
          used_slots--;
        }
          return true;
    }

    //If the company CName exists in the array and that the item Cname exists under that company_name
    //We remove item cName from the product list under the company_name
    //return true if removal is successful
    bool database::erase_item(const std::string& cName, const std::string& pName) {

        assert(cName.length() > 0 && pName.length() > 0);

        size_type company_index = search_company(cName);

        // COMPLETE THE IMPLEMENTATION...

        // If you find a company that is false, because it does not exist
        if (company_index == COMPANY_NOT_FOUND) {
            return false;
        }

          return company_array[company_index].erase(pName);
    }


    //Traverse through the company new_array
    //return the index where the company is found if it exists
    //return COMPANY_NOT_FOUND if company is not in the array
    database::size_type database::search_company(const std::string& company) {
        assert(company.length() > 0);

        // COMPLETE THE IMPLEMENTATION...
        for(int i = 0; i < used_slots; i++)
        {
          if(company_array[i].get_name() == company)
          {
            return i;
          }
        }
        return COMPANY_NOT_FOUND;
    }


    bool database::print_items_by_company(const std::string& cName) {
        assert(cName.length() > 0);

        size_type c_index = search_company(cName);

        if (c_index == COMPANY_NOT_FOUND) {
            return false;
        }

        std::cout << "Printing the products of " << cName << ":"<< std::endl;
        company_array[c_index].print_items();
        std::cout << std::endl;

        return true;
    }


    void database::print_companies() {

        std::cout << "Company List" << std::endl;
        for (int i = 0; i < used_slots; i++) {
            std::cout << "- " << company_array[i].get_name() << std::endl;
        }
    }
}

#endif
