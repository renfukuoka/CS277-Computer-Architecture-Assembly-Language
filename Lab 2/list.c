#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "list.h"

struct node
{
    long val;
    struct node *next;
    struct node *prev;
};

void panic(char *s)
{
    fprintf(stderr, "%s\n", s);
    exit(1);
}

struct list *new()
{
    struct list *lst = malloc(sizeof(struct node));
    if (lst == NULL)
    {
        panic("Out of memory!");
    }
    lst->size = 0;
    lst->head = NULL;
    lst->tail = NULL;
    return lst;
};

void destroy(struct list *l)
{
    assert(l != NULL);
    struct node *cur = l->head;
    while (cur != NULL)
    {
        struct node *next = cur->next;
        free(cur);
        cur = next;
    }
    free(l);
}

int size(struct list *l)
{
    assert(l != NULL);
    return l->size;
}

void add_tail(struct list *l, long val)
{
    assert(l != NULL);
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL)
    {
        panic("OUT OF MEMORY");
    }
    n->val = val;
    n->next = NULL;
    n->prev = l->tail;

    if (l->tail != NULL)
    {
        l->tail->next = n;
    }
    else
    {
        l->head = n;
    }
    l->tail = n;
    l->size++;
}

long remove_at(struct list *l, int index)
{
    assert(l != NULL && index >= 0 && index < l->size);
    struct node *cur = l->head;
    for (int i = 0; i < index; i++)
    {
    }
    return 0;
}

long get(struct list *l, int index)
{
    assert(l != NULL && index >= 0 && index < l->size);
    struct node *cur = l->head;
    for (int i = 0; i < index; i++)
    {
        cur = cur->next;
    }
    return cur->val;
}
