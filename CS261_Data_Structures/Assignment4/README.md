# Assignment 4

In this assignment, you will implement a binary heap-based priority queue (PQ).  The requirements for the assignment are described below.

For this assignment, you are provided with some starter code that defines the structures you'll be working with and prototypes the functions you'll be writing and also provides some data structures upon which to build a PQ implementation.  It's important that you don't modify the function prototypes specified in `pq.h`. To help grade your assignment, we will use a set of tests that assume these functions exist and have the same prototypes that are defined in those files. If you change the prototypes, it will cause the tests to break, and your grade for the assignment will likely suffer.

Feel free to add any additional functions you might need to `pq.c`.

## Implement a heap-based priority queue

Your task for this assignment is to implement a [priority queue](https://en.wikipedia.org/wiki/Priority_queue) (PQ).  A PQ is a structure that orders data elements based on assigned priority values.  Specifically, elements can be inserted into a PQ in any order, but when removing an element from a PQ, the highest-priority element is always removed first.

You must build your PQ using a [binary heap](https://en.wikipedia.org/wiki/Binary_heap).  A binary heap is a data structure that takes the form of a binary tree.  There are two different kinds of binary heaps:
  * A minimizing binary heap is organized so that the element with the *lowest* key is always at the root of the tree.
  * A maximizing binary heap is organized so that the element with the *highest* key is always at the root of the tree.
In this assignment, you will specifically base your PQ implementation on a minimizing binary heap.

The interface for the PQ you'll implement (i.e. the structures and the prototypes of functions a user of the PQ interacts with) is already defined for you in the file `pq.h`.  Your job is to implement definitions for the functions that comprise this interface in `pq.c`.

**Note that you may not modify the interface definition with which you are provided.**  Specifically, do not modify any of the already-defined PQ function prototypes.  We will use a set of tests to verify your implementation, and if you change the PQ interface, it will break these tests, thereby (negatively) affecting your grade.  Beyond these things, though, feel free to add any additional functions or structures your PQ implementation needs.  In particular, you'll have to specify a definition of the main PQ structure, `struct pq`, in `pq.c`.

The PQ functions you'll need to implement are outlined briefly below.  All of these functions use the type `struct pq`, which represents the PQ itself and which you'll have to define in `pq.c`.  For more details, including information on function parameters and expected return values, see the documentation provided in `pq.c`.  Here are the functions you'll have to implement:

  * **`pq_create()`** - This function should allocate, initialize, and return a pointer to a new PQ structure.

  * **`pq_free()`** - This function should free all the memory held within a PQ structure created by `pq_create()` without any memory leaks.  Note that this function only needs to free the memory held by the PQ itself.  It does not need to free the individual elements stored in the PQ.  This is the responsibility of the calling function.

  * **`pq_isempty()`** - This function should return 1 if the PQ is empty and 0 otherwise.

  * **`pq_insert()`** - This function should insert a new value with specified priority into the PQ.  **This operation must have O(log n) runtime complexity.**

  * **`pq_first()`** - This function should return the first value (i.e. the highest-priority value) from a PQ *without* removing it.  **This operation must have O(1) runtime complexity.**

  * **`pq_first_priority()`** - This function should return the *priority value* associated with the first element in a PQ *without* removing that element.  **This operation must have O(1) runtime complexity.**

  * **`pq_remove_first()`** - This function should remove the first value (i.e. the highest-priority value) from a PQ and return that value.  **This operation must have O(log n) runtime complexity.**

Your priority queue must be implemented using a minimizing binary heap as the underlying data structure.  This means that within the priority queue you implement, *lower* priority values should correspond to elements with *higher* priority.  In other words, the first element in the priority queue should be the one with the *lowest* priority value among all elements in the collection.  For example, your priority queue should return an element with priority value 0 before it returns one with priority value 10.

In lecture, we'll discuss how you can implement a binary heap using an array.  You are provided with a dynamic array implementation in `dynarray.c` and `dynarray.h` that you can use to implement your heap, if you'd like.  In addition to this dynamic array implementation, you may implement any additional helper functions you need to make your priority queue work.