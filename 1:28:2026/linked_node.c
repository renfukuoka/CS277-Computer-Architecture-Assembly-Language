#include <stdio.h>

struct node
{
    int val;
    struct node *next;
};

int main()
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
}