/*
 * Name: Zach Taylor
 * Email: taylzach@oregonstate.edu
 */

#include <stdlib.h>
#include <stdio.h>

#include "pq.h"
#include "dynarray.h"

/*
 * This is the structure that represents a priority queue.
 */
struct pq {
  struct dynarray* array;
};

//helper functions and struct
struct node {
  void** val;
  int key;
};
void swap(struct pq* pq, int pos);


/*
 * This function should allocate and initialize an empty priority queue and
 * return a pointer to it.
 */
struct pq* pq_create() {
  struct pq* queue = malloc(sizeof(struct pq));
  queue->array = dynarray_create();
  return queue;
}


/*
 * This function should free the memory allocated to a given priority queue.
 * Note that this function SHOULD NOT free the individual elements stored in
 * the priority queue.  That is the responsibility of the caller.
 *
 * Params:
 *   pq - the priority queue to be destroyed.  May not be NULL.
 */
void pq_free(struct pq* pq) {
  dynarray_free(pq->array);
  free(pq);
}


/*
 * This function should return 1 if the specified priority queue is empty and
 * 0 otherwise.
 *
 * Params:
 *   pq - the priority queue whose emptiness is to be checked.  May not be
 *     NULL.
 *
 * Return:
 *   Should return 1 if pq is empty and 0 otherwise.
 */
int pq_isempty(struct pq* pq) {
  if(dynarray_size(pq->array) == 0) {
    return 1;
  } else {
    return 0;
  }
}


/*
 * This function should insert a given element into a priority queue with a
 * specified priority value.  Note that in this implementation, LOWER priority
 * values are assigned to elements with HIGHER priority.  In other words, the
 * element in the priority queue with the LOWEST priority value should be the
 * FIRST one returned.
 *
 * Params:
 *   pq - the priority queue into which to insert an element.  May not be
 *     NULL.
 *   value - the value to be inserted into pq.
 *   priority - the priority value to be assigned to the newly-inserted
 *     element.  Note that in this implementation, LOWER priority values
 *     should correspond to elements with HIGHER priority.  In other words,
 *     the element in the priority queue with the LOWEST priority value should
 *     be the FIRST one returned.
 */
void pq_insert(struct pq* pq, void* value, int priority) {
  struct node* node = malloc(sizeof(struct node));
  node->val = value;
  node->key = priority;
  dynarray_insert(pq->array, node);

  int i = (dynarray_size(pq->array) - 1);
  if(i == 0) {
    return;
  } else {
    int p = ((i - 1) / 2);
    struct node* parent = dynarray_get(pq->array, p);
    struct node* child = dynarray_get(pq->array, i);

    while(i > 0 && parent->key > child->key) {
      dynarray_set(pq->array, p, child);
      dynarray_set(pq->array, i, parent);
      i = p;
      p = ((i - 1) / 2);
      if(i > 0) {
        parent = dynarray_get(pq->array, p);
      } else {
        parent = NULL;
      }
    }
  }
}


/*
 * This function should return the value of the first item in a priority
 * queue, i.e. the item with LOWEST priority value.
 *
 * Params:
 *   pq - the priority queue from which to fetch a value.  May not be NULL or
 *     empty.
 *
 * Return:
 *   Should return the value of the first item in pq, i.e. the item with
 *   LOWEST priority value.
 */
void* pq_first(struct pq* pq) {
  struct node* temp = dynarray_get(pq->array, 0);
  return temp->val;
}


/*
 * This function should return the priority value of the first item in a
 * priority queue, i.e. the item with LOWEST priority value.
 *
 * Params:
 *   pq - the priority queue from which to fetch a priority value.  May not be
 *     NULL or empty.
 *
 * Return:
 *   Should return the priority value of the first item in pq, i.e. the item
 *   with LOWEST priority value.
 */
int pq_first_priority(struct pq* pq) {
  struct node* temp = dynarray_get(pq->array, 0);
  return temp->key;
}

/*
 * This function should return the value of the first item in a priority
 * queue, i.e. the item with LOWEST priority value, and then remove that item
 * from the queue.
 *
 * Params:
 *   pq - the priority queue from which to remove a value.  May not be NULL or
 *     empty.
 *
 * Return:
 *   Should return the value of the first item in pq, i.e. the item with
 *   LOWEST priority value.
 */
void* pq_remove_first(struct pq* pq) {
  int i = (dynarray_size(pq->array) - 1);
  struct node* root = dynarray_get(pq->array, i);
  struct node* temp = dynarray_get(pq->array, 0);
  dynarray_set(pq->array, 0, root);
  dynarray_remove(pq->array, i);
  swap(pq, 0);
  void* val = temp->val;
  free(temp);
  return val;
}

void swap(struct pq* pq, int pos) {
  int left_idx = (pos *2) + 1;
  int right_idx = (pos * 2) + 2;
  int smallIdx;

  if(right_idx < (dynarray_size(pq->array) - 1)) {
    struct node* left = dynarray_get(pq->array, left_idx);
    struct node* right = dynarray_get(pq->array, right_idx);

    if(left->key < right->key) {
      smallIdx = left_idx;
    } else {
      smallIdx = right_idx;
    }

    struct node* parent = dynarray_get(pq->array, pos);
    struct node* child = dynarray_get(pq->array, smallIdx);

    if(child->key < parent->key) {
      dynarray_set(pq->array, pos, child);
      dynarray_set(pq->array, smallIdx, parent);
      swap(pq, smallIdx);
    }
  } else if(left_idx < (dynarray_size(pq->array) - 1)) {
    smallIdx = left_idx;
    struct node* parent = dynarray_get(pq->array, pos);
    struct node* child = dynarray_get(pq->array, smallIdx);

    if(child->key < parent->key) {
      dynarray_set(pq->array, pos, child);
      dynarray_set(pq->array, smallIdx, parent);
      swap(pq, smallIdx);
    }
  }
}