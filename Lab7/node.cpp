
#ifndef ITEM_CPP
#define ITEM_CPP

#include "node.h"

/*Invariant:
1. Name of the product is stored in the string variable name
2. Price of the product is stored in the float varaible price
3. Next product's link is stored in the node pointer link
4. Order of the product does matter

*/
namespace coen79_lab7
{
    node::node(const std::string &itemName, const float &newPrice, node *nextNode) {
        name = itemName;
        price = newPrice;
        link = nextNode;
    }

    void node::setName(const std::string &newName) {
        name = newName;
    }

    void node::setPrice(const float &newPrice) {
        price = newPrice;
    }

    void node::setLink(node *new_next) {
        link = new_next;
    }

    node* node::getLink() {
        return link;
    }

    const node* node::getLink() const {
        return link;
    }

    std::string node::getName() const{
        return name;
    }

    float node::getPrice() const {
        return price;
    }


    void list_init(node*& head, node*& tail, const std::string& newName, const float& newPrice) {
        head = new node(newName, newPrice, NULL);
        tail = head;
    }

    //insert a new product node at the end of the product list_tail_insert
    //set tail pointer to the new node
    void list_tail_insert(node*& tail, const std::string &newName, const float &newPrice) {

        // COMPLETE THE IMPLEMENTATION...
        node* new_node = new node(newName, newPrice, NULL);
        tail->setLink(new_node);
        tail = new_node;
    }

    //remove the product list until the head pointer points to nothing
    void list_clear(node*& head) {
        // COMPLETE THE IMPLEMENTATION...


        while(head != NULL)
        {
          list_head_remove(head);
        }

    }


    void list_copy(const node *old_head, node* &new_head, node* &new_tail) {
        new_head = NULL;
        new_tail = new_head;

        const node *cur = old_head;
        while (cur != NULL) {
            if (new_head == NULL) {
                new_head = new node(cur->getName(), cur->getPrice());
                new_tail = new_head;
            }
            else {
                new_tail->setLink(new node(cur->getName(), cur->getPrice()));
                new_tail = new_tail->getLink();
            }
            cur=cur->getLink();
        }
    }

    //remove the node where the head pointer is pointed to
    void list_head_remove(node*& head) {
        // COMPLETE THE IMPLEMENTATION...

        node *remove_ptr;

      	remove_ptr = head;
      	head = head->getLink();
      	delete remove_ptr;
    }


    void list_print(node *head) {
        node *cur = head;
        while (cur != NULL) {
            std::cout << "- " << cur->getName() << ", where the price is $" << cur->getPrice() << std::endl;
            cur = cur->getLink();
        }
    }


    bool list_contains_item(node *head_ptr, const std::string& newName) {
        return (list_search(head_ptr, newName) != NULL);
    }


    node* list_search(node* head_ptr, const std::string& target)
    {
        node *cursor;

        for (cursor = head_ptr; cursor != NULL; cursor = cursor->getLink( ))
            if (target == cursor->getName( ))
                return cursor;
        return NULL;
    }


    const node* list_search(const node* head_ptr, const std::string & target)
    {
        const node *cursor;

        for (cursor = head_ptr; cursor != NULL; cursor = cursor->getLink( ))
            if (target == cursor->getName( ))
                return cursor;
        return NULL;
    }

}

#endif
