// linkedlist.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

class list 
{

private:

	class node
	{
	public:
		//data members
		double data_;
		node*  next_;
		//Constructor
		node(double data) :data_(data) {};
	};

	node* root_node_;

public:
	
	//Constructor
	list(void) {};

	//Destructor
	~list()
	{
		node* current = root_node_;
		while (current != nullptr)
		{
			node* tmp(current);
			current = current->next_;
			delete(tmp);
		}
		root_node_ = nullptr;
	};

	//Add data as a node
	void add(double data)
	{
		node* tmp = new node(data);

		if (root_node_ == nullptr)
		{
			root_node_ = tmp;
		}
		else
		{
			node* current = root_node_;
			while ( current->next_ != nullptr )
			{
				current = current->next_;
			}
			//We've reached the tail
			current->next_ = tmp;
		}
	};

	//Remove node with given data 
	void remove(double data)
	{
		if (root_node_ == nullptr)
		{
			std::cout << "Nothing to remove - list if empty" << std::endl;
		}
		else
		{
			node* current  = root_node_;
			node* previous = nullptr;
			while ( current != nullptr && current->data_ != data )
			{
				previous  = current;
				current   = current->next_;
			}
			
			// If node to be deleted is the root,then reset the root
			if (root_node_ == previous)
			{
				delete(root_node_);
				//If list is more than one node long, reset root
				root_node_ = nullptr;
			}
			else 
			{
				//If deletion occures in the middle
				if (current != nullptr)
				{
					previous->next_ = current->next_;
				}
				else //deletion occurs in the end
				{
					std::cout << "Value to remove not found" << std::endl;
				}
				//Delete current node
				delete(current);
			}
		}
	}

	//print
	void print(void) const
	{
		if (root_node_ == nullptr)
		{
			std::cout << "Nothing to PRINT - list if empty" << std::endl;
		}
		else
		{
			node* current = root_node_;
			while (current != nullptr)
			{
				std::cout << current->data_ << '\t';
				current = current->next_;
			}
			std::cout << std::endl;
		}
	}

};

int main()
{
	list mylist;
	//Add 
	mylist.add(1);
	mylist.add(2);
	mylist.add(3);
	mylist.add(4);
	mylist.add(5);
	mylist.print();
	
	//Remove
	mylist.remove(40);
	mylist.print();

	//Add
	mylist.add(9);
	mylist.print();

    return 0;
}

