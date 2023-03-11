Implementation of a dynamic array

The dynamic array functions implemented are outlined briefly below.  All of these functions use a type called `struct dynarray`, which is defined in `dynarray.c` and represents the dynamic array itself.  For more details, including information on function parameters and expected return values, see the documentation provided in `dynarray.c`.

  * **`dynarray_create()`** - This function should allocate, initialize, and return a pointer to a new dynamic array structure.

  * **`dynarray_free()`** - This function should free the memory held within a dynamic array structure created by `dynarray_create()`.

  * **`dynarray_size()`** - This function should return the number of elements stored in a dynamic array (*not* the capacity of the array).

  * **`dynarray_insert()`** - This function should insert a new element *at the end* of a dynamic array.  In other words, if the array currently contains `n` elements (in indices `0` through `n-1`), then the new element (the `n+1`'th element) should always be inserted at index `n`. If there is not enough space in the dynamic array to store the element being inserted, this function should double the size of the array.

  * **`dynarray_remove()`** - This function should remove the element at a specified index from a dynamic array.  After the element is removed, there will be a "hole" where the element used to be.  All elements after the removed one (i.e. with higher indices) should be moved forward one spot to fill that hole.  In other words, if the element at index `i` is removed, then the element at index `i+1` should be moved forward to index i, the element at index `i+2` should be moved forward to index `i+1`, the element at index `i+3` should be moved forward to index `i+2`, and so forth.

  * **`dynarray_get()`** - This function should return the element value stored at a specified index in a dynamic array.

  * **`dynarray_set()`** - This function should update (i.e. overwrite) the value of an element at a specified index in a dynamic array.

Implementation of a singly-linked list

The linked list functions implemented are outlined briefly below.  The functions here will make use of two different structures:
  * **`struct link`** - This structure represents a single link in the linked list.  It has one field in which to store the data element associated with the link and one field that will point to the next link in the list.
  * **`struct list`** - This structure represents an entire list and contains a single field to represent the head of the list.
As with the dynamic array, see `list.c`  information on function parameters, expected return values, etc. for the linked list interface.

  * **`list_create()`** - This function should allocate, initialize, and return a pointer to a new linked list structure.

  * **`list_free()`** - This function should free the memory held within a linked list structure created by `list_create()`, including any memory allocated to the individual links themselves.

  * **`list_insert()`** - This function should insert a new value *at the beginning* (i.e. as the head) of a linked list.  Importantly, this function will need to allocate a new `struct link` in which to store the new value and add that link at the head of the list. The current head should become the next element after the new one.

  * **`list_remove()`** - This function should remove the *first instance* of a specified value from a linked list.  If multiple instances of the specified value exist in the list, only the first (i.e. the one closest to the head) should be removed.  If the specified value doesn't exist in the list, this function doesn't need to do anything.  This function will be passed a *function pointer* that can be used to determine whether the value to be removed matches any of the values stored in the list.

  * **`list_position()`** - This function should return the list position (i.e. the 0-based "index") of the first instance of a specified value within a linked list.  If multiple instances of the specified value exist in the list, the "index" of the first one (i.e. the one closest to the head) should be returned.  If no instances of the specified value exist in the list, this function should return the special value -1.  This function will be passed a *function pointer* that you can use to determine whether the value to be located matches any of the values stored in the list.

  * **`list_reverse()`** - This function should reverse a linked list *in place*, that is within the memory of the existing list, without allocating new memory.