Implementation of a stack

The stack functions implemented are outlined briefly below.  All of these functions use a type called `struct stack`, which is defined in `stack.c` and represents the stack itself.  For more details, including information on function parameters and expected return values, see the documentation provided in `stack.c`.

  * **`stack_create()`** - This function should allocate, initialize, and return a pointer to a new stack structure.

  * **`stack_free()`** - This function should free the memory held within a stack structure created by `stack_create()`.  Note that this function only needs to free the memory held by the stack itself.  It does not need to free the individual elements stored in the stack. This is the responsibility of the calling function.

  * **`stack_isempty()`** - This function should return 1 if the stack is empty and 0 otherwise.

  * **`stack_push()`** - This function should insert a new element on top of the stack.  **This operation must have O(1) average runtime complexity.**

  * **`stack_top()`** - This function should return the value stored at the top of the stack without removing it.  **This operation must have O(1) average runtime complexity.**

  * **`stack_pop()`** - This function should pop a value from the stack and return the popped value.  **This operation must have O(1) average runtime complexity.**

Implementation of a queue

The queue functions implemented are outlined briefly below.  All of these functions use a type called `struct queue`, which is defined in `queue.c` and represents the queue itself.  For more details, including information on function parameters and expected return values, see the documentation provided in `queue.c`.

  * **`queue_create()`** - This function should allocate, initialize, and return a pointer to a new queue structure.

  * **`queue_free()`** - This function should free the memory held within a queue structure created by `queue_create()`.  Note that this function only needs to free the memory held by the queue itself.  It does not need to free the individual elements stored in the queue. This is the responsibility of the calling function.

  * **`queue_isempty()`** - This function should return 1 if the queue is empty and 0 otherwise.

  * **`queue_enqueue()`** - This function should insert a new element at the back of the queue.  **This operation must have O(1) average runtime complexity.**

  * **`queue_front()`** - This function should return the value stored at the front of the queue without removing it.  **This operation must have O(1) average runtime complexity.**

  * **`queue_dequeue()`** - This function should dequeue a value from the queue and return the dequeued value.  **This operation must have O(1) average runtime complexity.**