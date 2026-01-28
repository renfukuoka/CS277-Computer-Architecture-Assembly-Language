#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "list.h"

struct node {
    long val;
    struct node *next;
    struct node *prev;
};

void panic(char *s) {
    fprintf(stderr, "%s\n", s);
    exit(1);
}

struct list *new() {
    return NULL;
}

void destroy(struct list *l) {
    assert(l != NULL);
}

int size(struct list *l) {
    assert(l != NULL);
    return 0;
}

void add_tail(struct list *l, long val) {
    assert(l != NULL);
}

long remove_at(struct list *l, int index) {
    assert(l != NULL && index >= 0 && index < l->size);
    return 0;
}

long get(struct list *l, int index) {
    assert(l != NULL && index >= 0 && index < l->size);
    return 0;
}
