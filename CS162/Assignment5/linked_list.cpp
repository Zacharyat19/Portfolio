#include <iostream>

#include "linked_list.h"

Linked_List::Linked_List() {
    this->length = 0;
    this->head = NULL;
}

Linked_List::~Linked_List() {
    if(this->head != NULL) {
        delete this->head;
        this->head = NULL;
    }
}

int Linked_List::get_length() {
    return this->length;
}

void Linked_List::print() {
    Node *ptr = this->head;
    for(int i = 0; i < this->length; i++) {
        std::cout << ptr->val << " ";
        ptr = ptr->next;
    }
}

void Linked_List::clear() {

}

void Linked_List::push_front(int n) {
    if(this->head == NULL) {
        this->head = new Node;
        head->val = n;
        this->length += 1;
    } else {
        Node *temp = new Node;
        temp->val = n;
        temp->next = this->head;
        this->head = temp;
        this->length += 1;
    }
}

void Linked_List::push_back(int n) {
    Node *temp = new Node;
    temp->val = n;
    temp->next = NULL;

    Node *ptr = this->head;

    if(this->head == NULL) {
        this->head = temp;
        return;
    }

    while(ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = temp;
}

void Linked_List::insert(int val, unsigned int index) {

}

void Linked_List::sort_ascending() {

}

void Linked_List::sort_descending() {

}

unsigned int Linked_List::count_prime() {

}

bool Linked_List::is_prime(int n) {
    
}