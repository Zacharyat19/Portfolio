#include <iostream>

#include "linked_list.h"

/*************************************
 ** Function: Linked_List
 ** Description: Default constructor
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: Creates an object
 *************************************/
Linked_List::Linked_List() {
    this->length = 0;
    this->head = NULL;
}


/*************************************
 ** Function: Linked_List
 ** Description: Destructor
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: Deletes an object
 *************************************/
Linked_List::~Linked_List() {}


/**************************************
 ** Function: Getters
 ** Description: Return class variables
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: Returns length
 **************************************/
int Linked_List::get_length() {
    return this->length;
}


/***********************************************************
 ** Function: Print
 ** Description: Prints the linked list
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: Contents of the linked list are printed
 ***********************************************************/
void Linked_List::print() {
    Node *ptr = this->head;
    for(int i = 0; i < this->length; i++) {
        std::cout << ptr->val << " ";
        ptr = ptr->next;
    }
    std::cout << std::endl;
}


/************************************************************
 ** Function: Clear
 ** Description: Clears the linked list and sets head to NULL
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: Linked list is set to NULL
 ************************************************************/
void Linked_List::clear() {
    Node *current = this->head;
	Node *temp = NULL;
	while(current != NULL){
		temp = current->next;
		delete current;
		current = temp; 
	}
	this->head = NULL;
    this->length = 0;
}


/**********************************************************
 ** Function: Push_front
 ** Description: Adds a node to the front of the list
 ** Parameters: N
 ** Pre-Conditions: N is of type int
 ** Post-Conditions: Node is added to the front of the list
 **********************************************************/
void Linked_List::push_front(int n) {
    Node *temp = new Node;
    temp->val = n;
    temp->next = this->head;
    this->head = temp;
    this->length += 1;
}


/********************************************************
 ** Function: Push_back
 ** Description: Adds a node to the end of the list
 ** Parameters: N
 ** Pre-Conditions: N is of type int
 ** Post-Conditions: Node is added to the end of the list
 ********************************************************/
void Linked_List::push_back(int n) {
    Node *temp = new Node;
    temp->val = n;
    temp->next = NULL;

    Node *ptr = this->head;

    if(this->head == NULL) {
        this->head = temp;
        return;
    } else {
        while(ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
    this->length += 1;
}


/**********************************************
 ** Function: Insert
 ** Description: Adds a node at specified index
 ** Parameters: N, index
 ** Pre-Conditions: N and index are of type int
 ** Post-Conditions: Node is added at index 
 **********************************************/
void Linked_List::insert(int val, unsigned int index) {
    Node *temp = new Node;
    Node *current;
    temp->val = val;
    current = this->head;

    if(this->head != NULL) {
        if(index == 0) {
            delete temp;
            Linked_List::push_front(val);
        } else if(index < 0 || index > this->length) {
            delete temp;
            std::cout << "Index out of bounds" << std::endl;
        } else {
            for(int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            temp->next = current->next;
            current->next = temp;
            this->length++;
        }
    } else {
        this->head = temp;
        temp->next = NULL;
    }
}


/*************************************************
 ** Function: Sort_ascending
 ** Description: Calls the start of the merge sort
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: Calls merge sort
 *************************************************/
void Linked_List::sort_ascending() {
    Linked_List::merge_sort(&this->head);
}


/************************************************
 ** Function: Merge_sort
 ** Description: Breaks the list down and sorts
 ** Parameters: **HeadRef
 ** Pre-Conditions: HeadRef is points to the head
 ** Post-Conditions: Calls merge sort functions
 ************************************************/
void Linked_List::merge_sort(Node **headref) {
    Node *head = *headref; 
    Node *a; 
    Node *b; 
  
    if ((head == NULL) || (head->next == NULL)) { 
        return; 
    } 
  
    Linked_List::front_back_split(head, &a, &b); 
    Linked_List::merge_sort(&a); 
    Linked_List::merge_sort(&b); 
  
    *headref = Linked_List::sorted_merge(a, b);
}


/****************************************
 ** Function: Sorted_merge
 ** Description: Sorts the nodes
 ** Parameters: *A, *B
 ** Pre-Conditions: A and B are nodes
 ** Post-Conditions: Returns sorted nodes
 ****************************************/
Node *Linked_List::sorted_merge(Node *a, Node *b) {
    Node *result = NULL; 
  
    if (a == NULL) {
        return (b); 
    } else if (b == NULL) {
        return (a); 
    }
  
    if (a->val <= b->val) { 
        result = a; 
        result->next = Linked_List::sorted_merge(a->next, b); 
    } else { 
        result = b; 
        result->next = Linked_List::sorted_merge(a, b->next); 
    } 
    return result;
}


/*******************************************
 ** Function: Front_back_split
 ** Description: Breaks the list down
 ** Parameters: Source, FrontRef, BackRef
 ** Pre-Conditions: All parameters are nodes
 ** Post-Conditions: List is broken down
 *******************************************/
void Linked_List::front_back_split(Node *source, Node **frontref, Node **backref) {
    Node *fast; 
    Node *slow; 
    slow = source; 
    fast = source->next; 
  
    while (fast != NULL) { 
        fast = fast->next; 
        if (fast != NULL) { 
            slow = slow->next; 
            fast = fast->next; 
        } 
    } 
  
    *frontref = source; 
    *backref = slow->next; 
    slow->next = NULL;
}


/*************************************************
 ** Function: Sort_descending
 ** Description: Calls the start of the merge sort
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: Calls merge sort
 *************************************************/
void Linked_List::sort_descending() {
    Linked_List::merge_sort_descending(&this->head);
}


/************************************************
 ** Function: Merge_sort_descending
 ** Description: Breaks the list down and sorts
 ** Parameters: **HeadRef
 ** Pre-Conditions: HeadRef is points to the head
 ** Post-Conditions: Calls merge sort functions
 ************************************************/
void Linked_List::merge_sort_descending(Node **headref) {
    Node *head = *headref; 
    Node *a; 
    Node *b; 
  
    if ((head == NULL) || (head->next == NULL)) { 
        return; 
    } 
  
    Linked_List::front_back_split(head, &a, &b); 
    Linked_List::merge_sort_descending(&a); 
    Linked_List::merge_sort_descending(&b); 
  
    *headref = Linked_List::sorted_merge_descending(a, b);
}


/****************************************
 ** Function: Sorted_merge
 ** Description: Sorts the nodes
 ** Parameters: *A, *B
 ** Pre-Conditions: A and B are nodes
 ** Post-Conditions: Returns sorted nodes
 ****************************************/
Node *Linked_List::sorted_merge_descending(Node *a, Node *b) {
    Node *result = NULL; 
  
    if (a == NULL) {
        return (b); 
    } else if (b == NULL) {
        return (a); 
    }
  
    if (b->val >= a->val) { 
       result = b; 
       result->next = Linked_List::sorted_merge_descending(a, b->next);
    } else { 
        result = a; 
        result->next = Linked_List::sorted_merge_descending(a->next, b);  
    } 
    return result;
}


/*************************************************
 ** Function: Count_prime
 ** Description: Counts the number of prime nodes
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: Returns number of prime nodes
 *************************************************/
unsigned int Linked_List::count_prime() {
    int count = 0; 
    Node *ptr = this->head; 
  
    while (ptr != NULL) {  
        if (Linked_List::is_prime(ptr->val)) { 
            count++; 
        } 
        ptr = ptr->next; 
    } 
    return count;
}


/**********************************************
 ** Function: Is_prime
 ** Description: Determines if N is prime
 ** Parameters: N
 ** Pre-Conditions: N is of type int
 ** Post-Conditions: Returns true if N is prime
 **********************************************/
bool Linked_List::is_prime(int n) {
    if (n <= 1)  {
        return false;
    } 
    if (n <= 3) { 
        return true;
    } 
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    for (int i = 5; i * i <= n; i = i + 6) { 
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}