#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
};

int main()
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    printf("%p\n", ptr);
    if (ptr == NULL)
    {
        fprintf(stderr, "Out of memory! \n");
        exit(1);
    }
    struct node *ptr2 = (struct node *)malloc(sizeof(struct node));
    printf("%p\n", ptr2);
    if (ptr2 == NULL)
    {
        fprintf(stderr, "Out of memory! \n");
        exit(2);
    }
    struct node *ptr3 = (struct node *)malloc(sizeof(struct node));
    printf("%p\n", ptr3);
    if (ptr3 == NULL)
    {
        fprintf(stderr, "Out of memory! \n");
        exit(3);
    }
    exit(0);
}