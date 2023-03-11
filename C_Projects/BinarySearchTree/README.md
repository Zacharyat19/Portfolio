Implementation of a binary search tree

The BST functions needed to implement are outlined briefly below.  All of these functions use a type called `struct bst`, which is defined in `bst.c` and represents the BST itself.  For more details, including information on function parameters and expected return values, see the documentation provided in `bst.c`.

  * **`bst_create()`** - This function should allocate, initialize, and return a pointer to a new BST structure.

  * **`bst_free()`** - This function should free the memory held within a BST structure created by `bst_create()`.  Note that this function only needs to free the memory held by the BST itself.  It does not need to free the individual elements stored in the BST.  This is the responsibility of the calling function.

  * **`bst_size()`** - This function should return the total number of elements stored in a given BST.

  * **`bst_insert()`** - This function should insert a new key/value pair into a given BST.  The BST should be ordered based on the specified key value.

  * **`bst_remove()`** - This function should remove the value with a specified key from a given BST.  If multiple values are stored in the tree with the same key, the first one encountered (i.e. the one closest to the root of the tree) should be removed.

  * **`bst_get()`** - This function should return the value associated with a specified key in a given BST.  If multiple values are stored in the tree with the same key, the first one encountered (i.e. the one closest to the root of the tree) should be returned.