// CS 3305
// Assignment 2
// Name: Spencer Sopha
// Buff ID: 1093171

#include <iostream>
#include <cassert>
#include "dnode.h"

// Insert new node at the beginning of the doubly linked list,
// where the beginning (or first) node is the left-most node;
// also handles the case when the linked list is empty
void dlist_head_insert(dnode*& head_ptr, const dnode::value_type& entry) 
{
	dnode* new_node = new dnode(entry, head_ptr, NULL);
	if (head_ptr != NULL)
	{
		head_ptr->set_back(new_node);
	}
	head_ptr = new_node;
}

// Insert new node after the node pointed to by previous_ptr;
// also handles the case when the new node is the last node;
// asserts linked list is not empty
void dlist_insert(dnode* previous_ptr, const dnode::value_type& entry)
{
	assert(previous_ptr != NULL);

	dnode* next_ptr = previous_ptr->fore();
	dnode* new_node = new dnode(entry, next_ptr, previous_ptr);

	if (next_ptr != NULL)
	{
		next_ptr->set_back(new_node);
	}
	previous_ptr->set_fore(new_node);
}

// Removes the first node; asserts linked list is not empty
void dlist_head_remove(dnode*& head_ptr)
{
	assert(head_ptr != NULL);

	dnode* remove_ptr = head_ptr;
	head_ptr = head_ptr->fore();
	
	if (head_ptr != NULL)
	{
		head_ptr->set_back(NULL);
	}
	delete remove_ptr;
}

// Removes node after the node pointed to by previous_ptr;
// asserts linked list is not empty
void dlist_remove(dnode* previous_ptr)
{
	assert(previous_ptr != NULL);
	assert(previous_ptr->fore() != NULL);

	dnode* remove_ptr = previous_ptr->fore();
	dnode* next_ptr = remove_ptr->fore();

	previous_ptr->set_fore(next_ptr);
	if (next_ptr != NULL)
	{
		next_ptr->set_back(previous_ptr);
	}
	delete remove_ptr;
}

// Returns pointer to the node with data_field value equal to target;
// Returns NULL if the linked list is empty or if the target does not exist
dnode* dlist_search(dnode* head_ptr, const dnode::value_type& target)
{
	dnode* cursor;
	for (cursor = head_ptr; cursor != NULL; cursor = cursor->fore())
	{
		if (cursor->data() == target)
		{
			return cursor;
		}
	}
	return NULL;
}

// prints the data_field value of double linked list traversed from left
// to right
void print_fore(const dnode* head_ptr)
{
	const dnode *cursor;
	for (cursor = head_ptr; cursor != NULL; cursor = cursor->fore())
		std::cout << cursor->data() << " ";
	std::cout << std::endl;
}

// prints the data_field value of double linked list traversed from right
// to left
void print_back(const dnode* head_ptr)
{
    const dnode *cursor = head_ptr;
    while (cursor->fore() != NULL)
       cursor = cursor->fore();
    for (;cursor != NULL; cursor = cursor->back())
        std::cout << cursor->data() << " ";
    std::cout << std::endl; 
}

