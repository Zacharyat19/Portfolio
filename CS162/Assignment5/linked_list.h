#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "node.h"

class Linked_List {
	private:
		unsigned int length;
		Node* head;
	public:
		Linked_List();
		~Linked_List();
		int get_length();
		void print();
		void clear();
		void push_front(int);
		void push_back(int);
		void insert(int val, unsigned int index);
		void sort_ascending();
		void sort_descending();
		unsigned int count_prime();
		bool is_prime(int);
};
#endif