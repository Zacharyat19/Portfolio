# Assignment 2

This assignment is intended to have you start working with stacks and queues and to start building ADTs on top of other data structures.  There are a couple parts to the assignment, each described below.

For this assignment, you are provided with some starter code that defines the structures you'll be working with and prototypes the functions you'll be writing and also provides some data structures upon which to build a stack and queue implementation.  It's important that you don't modify the function prototypes specified in `queue.h` and `stack.h`.  To help grade your assignment, we will use a set of tests that assume these functions exist and have the same prototypes that are defined in those files. If you change the prototypes, it will cause the tests to break, and your grade for the assignment will likely suffer.

Feel free to add any additional functions you might need to `queue.c` and `stack.c`.  In addition, you may modify the dynamic array implementation provided in `dynarray.h`/`dynarray.c` or the linked list implementation provided in `list.h`/`list.c` as needed to help implement the queue and stack.

## 1. Implement a stack

In this assignment, you'll implement two new ADTs on top of the data structures you implemented in the previous assignment.  The first ADT you'll implement for this assignment is a [stack](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)).

A stack is a linear data type, that restricts the user to operate only on one end of the collection being stored.  This end of the collection is referred to as the "top".  New elements may only be inserted at the top of the stack, and only the element at the top of the stack (which is always the most recently added) may be removed.  This constraint means that elements in a stack are ordered in "last in, first out" (or LIFO) order.  In this way, the stack ADT behaves much like a physical stack, for example, a stack of books or of dishes, where we can only add and remove items to and from the top of the stack.

For this assignment, the interface for the stack (i.e. the structures and the prototypes of functions a user of the stack interacts with) is already defined for you in the file `stack.h`.  Your first task in this assignment is to implement definitions for the functions that comprise this interface in `stack.c`.

**Note that you may not modify the interface definition with which you are provided.**  Specifically, do not modify any of the already-defined stack function prototypes.  We will use a set of tests to verify your implementation, and if you change the stack interface, it will break these tests, which will (negatively) affect your grade.  Beyond the already-defined interface, though, feel free to add any additional functions or structures your stack implementation needs.

The stack functions you'll need to implement are outlined briefly below.  All of these functions use a type called `struct stack`, which is defined in `stack.c` and represents the stack itself.  For more details, including information on function parameters and expected return values, see the documentation provided in `stack.c`.

  * **`stack_create()`** - This function should allocate, initialize, and return a pointer to a new stack structure.

  * **`stack_free()`** - This function should free the memory held within a stack structure created by `stack_create()`.  Note that this function only needs to free the memory held by the stack itself.  It does not need to free the individual elements stored in the stack.  This is the responsibility of the calling function.

  * **`stack_isempty()`** - This function should return 1 if the stack is empty and 0 otherwise.

  * **`stack_push()`** - This function should insert a new element on top of the stack.  **This operation must have O(1) average runtime complexity.**

  * **`stack_top()`** - This function should return the value stored at the top of the stack without removing it.  **This operation must have O(1) average runtime complexity.**

  * **`stack_pop()`** - This function should pop a value from the stack and return the popped value.  **This operation must have O(1) average runtime complexity.**

Importantly, the stack you build **MUST** use a linked list as its underlying data storage.  You are provided with a linked list implementation in `list.h` and `list.c` that you may use for this purpose.  Feel free to modify this linked list implementation as needed to implement your stack, *with the constraint that you may only interact with the linked list implementation via its interface functions.*  In particular, you may not directly access or modify the fields of the linked list structure (`struct list`).  In other words, you may not change the fact that `list.h` only contains a forward declaration of `struct list`, and you may not redefine the list structure in `stack.h` or `stack.c`.

Also, note that, as with the data structures you implemented in assignment 1, values in the stack will be stored as void pointers.

## 2. Implement a queue

The second ADT you'll implement for this assignment is a [queue](https://en.wikipedia.org/wiki/Queue_(abstract_data_type)).  A queue is a two-ended, linear data structure where all elements must be inserted at one end of the queue (the "back") and can only be removed from the other end of the queue (the "front").  In this way, elements stored in a queue are ordered in "first in, first out" (FIFO) order.  In other words, each element removed from a queue will always be the one that was inserted before all the other elements stored in the queue.  Thus, the queue ADT works much like a line like you'd encounter at a grocery store or amusement park, where the first people to enter the line are the first ones who get to check out or ride a ride (much of the world outside the US actually calls a line like this a "queue").

For this assignment, the interface for the queue (i.e. the structures and the prototypes of functions a user of the queue interacts with) is already defined for you in the file `queue.h`.  Your first task in this assignment is to implement definitions for the functions that comprise this interface in `queue.c`.

**Note that you may not modify the interface definition with which you are provided.**  Specifically, do not modify any of the already-defined queue function prototypes.  We will use a set of tests to verify your implementation, and if you change the queue interface, it will break these tests, thereby (negatively) affecting your grade.  Beyond the already-defined interface, though, feel free to add any additional functions or structures your queue implementation needs.

The queue functions you'll need to implement are outlined briefly below.  All of these functions use a type called `struct queue`, which is defined in `queue.c` and represents the queue itself.  For more details, including information on function parameters and expected return values, see the documentation provided in `queue.c`.

  * **`queue_create()`** - This function should allocate, initialize, and return a pointer to a new queue structure.

  * **`queue_free()`** - This function should free the memory held within a queue structure created by `queue_create()`.  Note that this function only needs to free the memory held by the queue itself.  It does not need to free the individual elements stored in the queue.  This is the responsibility of the calling function.

  * **`queue_isempty()`** - This function should return 1 if the queue is empty and 0 otherwise.

  * **`queue_enqueue()`** - This function should insert a new element at the back of the queue.  **This operation must have O(1) average runtime complexity.**

  * **`queue_front()`** - This function should return the value stored at the front of the queue without removing it.  **This operation must have O(1) average runtime complexity.**

  * **`queue_dequeue()`** - This function should dequeue a value from the queue and return the dequeued value.  **This operation must have O(1) average runtime complexity.**

Importantly, the queue you build **MUST** use a dynamic array as its underlying data storage.  You are provided with a dynamic array implementation in `dynarray.h` and `dynarray.c` that you may use for this purpose.  Feel free to modify this dynamic array implementation as needed to implement your queue, *with the constraint that you may only interact with the dynamic array implementation via its interface functions.*  In particular, you may not directly access or modify the fields of the dynamic array structure (`struct dynarray`).  In other words, you may not change the fact that `dynarray.h` only contains a forward declaration of `struct dynarray`, and you may not redefine the dynamic array structure in `queue.h` or `queue.c`.

Also, note that, as with the data structures you implemented in assignment 1, values in the queue will be stored as void pointers.