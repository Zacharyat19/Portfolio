/*
 * This file contains the definition of the interface for a linked list.
 */

#ifndef __LIST_H
#define __LIST_H

/*
 * Structure used to represent a singly-linked list.
 */
struct list;

/*
 * Linked list interface function prototypes.  Refer to list.c for
 * documentation about each of these functions.
 */
struct list* list_create();
void list_free(struct list* list);
void list_insert(struct list* list, void* val);
int list_isempty(struct list* list);
void* list_head(struct list* list);
void list_remove_head(struct list* list);

#endif
