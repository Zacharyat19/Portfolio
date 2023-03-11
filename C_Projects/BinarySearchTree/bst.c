/*
 * Name: Zach Taylor
 * Email: taylzach@oregonstate.edu
 */

#include <stdlib.h>
#include <stdio.h>

#include "bst.h"
#include "stack.h"

/*
 * This structure represents a single node in a BST.  In addition to containing
 * pointers to its two child nodes (i.e. `left` and `right`), it contains two
 * fields representing the data stored at this node.  The `key` field is an
 * integer value that should be used as an identifier for the data in this
 * node.  Nodes in the BST should be ordered based on this `key` field.  The
 * `value` field stores data associated with the key.
 *
 * You should not modify this structure.
 */
struct bst_node {
  int key;
  void* value;
  struct bst_node* left;
  struct bst_node* right;
};

/*
 * This structure represents an entire BST.  It specifically contains a
 * reference to the root node of the tree.
 *
 * You should not modify this structure.
 */
struct bst {
  struct bst_node* root;
};

/*
 * list of helper functions
 */
int count_nodes(struct bst_node* node, int* count);
struct bst_node* remove_node(struct bst_node* curr, int key);
struct bst_node* remove_left(struct bst_node* curr);
struct bst_node* left_most(struct bst_node* curr);
void free_node(struct bst_node* node);


/*
 * This function should allocate and initialize a new, empty, BST and return
 * a pointer to it.
 */
struct bst* bst_create() {
  struct bst* tree = malloc(sizeof(struct bst));
  tree->root = NULL;
  return tree;
}

/*
 * This function should free the memory associated with a BST.  While this
 * function should up all memory used in the BST itself, it should not free
 * any memory allocated to the pointer values stored in the BST.  This is the
 * responsibility of the caller.
 *
 * Params:
 *   bst - the BST to be destroyed.  May not be NULL.
 */
void bst_free(struct bst* bst) {
  free_node(bst->root);
  free(bst);
}

/*
 * This function should free the memory associated with a node
 *
 * Params:
 *   node - node to be freed.
 */
void free_node(struct bst_node* node) {
  if(node == NULL) {
    return;
  }
  free_node(node->left);
  free_node(node->right);
  free(node);
}

/*
 * This function should return the total number of elements stored in a given
 * BST.
 *
 * Params:
 *   bst - the BST whose elements are to be counted.  May not be NULL.
 */
int bst_size(struct bst* bst) {
  int count = 0;
  int* counter = &count;
  count_nodes(bst->root, counter);
  return count;
}

/*
 * This function counts the number of nodes through in-order succession.
 *
 * Params:
 *   node - the root node of the tree.
 *   count - a pointer to the size of the tree.
 */
int count_nodes(struct bst_node* node, int* count) {
  if(node != NULL) {
    count_nodes(node->left, count);
    *count += 1;
    count_nodes(node->right, count);
  }
}

/*
 * This function should insert a new key/value pair into the BST.  The key
 * should be used to order the key/value pair with respect to the other data
 * stored in the BST.  The value should be stored along with the key, once the
 * right location in the tree is found.
 *
 * Params:
 *   bst - the BST into which a new key/value pair is to be inserted.  May not
 *     be NULL.
 *   key - an integer value that should be used to order the key/value pair
 *     being inserted with respect to the other data in the BST.
 *   value - the value being inserted into the BST.  This should be stored in
 *     the BST alongside the key.  Note that this parameter has type void*,
 *     which means that a pointer of any type can be passed.
 */
void bst_insert(struct bst* bst, int key, void* value) {
  struct bst_node* p = NULL;
  struct bst_node* n = bst->root;

  while(n != NULL) {
    p = n;
    if(key < n->key) {
      n = n->left;
    } else {
      n = n->right;
    }
  }

  struct bst_node* new_node = malloc(sizeof(struct bst_node));
  new_node->key = key;
  new_node->value = value;
  new_node->left = NULL;
  new_node->right = NULL;
  
  if(p == NULL) {
    bst->root = new_node;
  } else {
    if(new_node->key < p->key) {
      p->left = new_node;
    } else {
      p->right = new_node;
    }
  }
}

/*
 * This function should remove a key/value pair with a specified key from a
 * given BST.  If multiple values with the same key exist in the tree, this
 * function should remove the first one it encounters (i.e. the one closest to
 * the root of the tree).
 *
 * Params:
 *   bst - the BST from which a key/value pair is to be removed.  May not
 *     be NULL.
 *   key - the key of the key/value pair to be removed from the BST.
 */
void bst_remove(struct bst* bst, int key) {
  if(bst_get(bst, key) != NULL) {
    bst->root = remove_node(bst->root, key);
  }
}

/*
 * This function should remove a node.
 *
 * Params:
 *   node - current node
 *   key - key to the node to be removed
 */
struct bst_node* remove_node(struct bst_node* curr, int key) {
  struct bst_node* node;
  struct bst_node* temp;

  if(curr->key == key) {
    if(curr->right == 0) {
      node = curr->left;
      free(curr);
      return node;
    } else {
      temp = left_most(curr->right);
      curr->key = temp->key;
      curr->value = temp->value;
      curr->right = remove_left(curr->right);
    }
  } else {
    if(key < curr->key) {
      curr->left = remove_node(curr->left, key);
    } else {
      curr->right = remove_node(curr->right, key);
    }
  }
  return curr;
}

/*
 * This function should remove the left most node
 *
 * Params:
 *   node - current node
 */
struct bst_node* remove_left(struct bst_node* curr) {
  struct bst_node* temp;
  
  if(curr->left != 0) {
    curr->left = remove_left(curr->left);
    return curr;
  }

  temp = curr->right;
  free(curr);
  return temp;
}

/*
 * This function should return the left most node
 *
 * Params:
 *   node - current node
 */
struct bst_node* left_most(struct bst_node* curr) {
  while(curr->left != NULL) {
    curr = curr->left;
  }
  return curr;
}

/*
 * This function should return the value associated with a specified key in a
 * given BST.  If multiple values with the same key exist in the tree, this
 * function should return the first one it encounters (i.e. the one closest to
 * the root of the tree).  If the BST does not contain the specified key, this
 * function should return NULL.
 *
 * Params:
 *   bst - the BST from which a key/value pair is to be removed.  May not
 *     be NULL.
 *   key - the key of the key/value pair whose value is to be returned.
 *
 * Return:
 *   Should return the value associated with the key `key` in `bst` or NULL,
 *   if the key `key` was not found in `bst`.
 */
void* bst_get(struct bst* bst, int key) {
  struct bst_node* n = bst->root;

  while(n != NULL) {
    if(n->key == key) {
      return n->value;
    } else if(key < n->key) {
      n = n->left;
    } else {
      n = n->right;
    }
  }
  return NULL;
}