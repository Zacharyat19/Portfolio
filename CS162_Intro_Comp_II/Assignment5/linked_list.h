#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "node.h"

class Linked_List {
	private:
		unsigned int length;
		Node *head;
	public:
		Linked_List();
		~Linked_List();
		int get_length();
		bool is_prime(int);
		void print();
		void clear();
		void push_front(int);
		void push_back(int);
		void insert(int val, unsigned int index);
		void sort_ascending();
		void sort_descending();
		unsigned int count_prime();
		void merge_sort(Node **headref);
		void merge_sort_descending(Node **headref);
		void front_back_split(Node *source, Node **frontref, Node **backref);
		Node *sorted_merge(Node *a, Node *b);
		Node *sorted_merge_descending(Node *a, Node *b);
};
#endif