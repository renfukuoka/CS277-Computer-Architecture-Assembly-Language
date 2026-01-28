#pragma once

// Forward declaration; definition hidden in list.c.
struct node;

struct list {
    int size;
    struct node *head;
    struct node *tail;
};

/**
 * Create a new empty list.
 * @return a new empty list.
 */
struct list *new();

/**
 * Destroy an existing list.
 * @param l  a pointer to a list
 */
void destroy(struct list *l);

/**
 * Return the number of elements in the given list.
 * @param l  a pointer to a list
 * @return the number of element in the list
 */
int size(struct list *l);

/**
 * Add a value at the end of the given list.
 * @param l  a pointer to a list
 */
void add_tail(struct list *l, long val);

/**
 * Remove an element at a particular index in the given list and
 * return its value.
 *
 * The first index is 0, the second is 1, etc.  The index is assumed
 * to be sane.
 *
 * @param l a pointer to a list
 * @param the value of the element being removed
 */
long remove_at(struct list *l, int index);

/**
 * Return the value stored at a particular index in the given list.
 *
 * The first index is 0, the second is 1, etc.  The index is assumed
 * to be sane.
 *
 * @param l  a pointer to a list
 * @return the value stored at the index position in the list
 */
long get(struct list *l, int index);
