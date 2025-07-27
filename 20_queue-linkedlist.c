#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node *f = NULL; // global variable
struct Node *r = NULL; // global variable

struct Node
{
    int data;
    struct Node *next;
};

void linkedlistTraversal(struct Node *ptr)
{
    printf("Printing the element of linkedlist\n");
    while (ptr != NULL)
    {
        printf(" Element :%d\n", ptr->data);
        ptr = ptr->next;
    }
}

void enqueue(int val) // no need to pass f ,r because it is globally declared
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        printf("The Queue is Full");
    }
    else
    {

        n->data = val;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}

int dequeue()
{
    int a = -1;
    struct Node *ptr=f;
    if (f == NULL)
    {
        printf("The Queue is Empty\n");
    }
    else
    {
        f = f->next;
        a = ptr->data;
        free(ptr);
    }
    return a;
}

int main()
{
    printf("Dequeing element %d\n",dequeue());
    linkedlistTraversal(f);

    enqueue(2);
    enqueue(20);
    enqueue(12);
    enqueue(10);
     printf("Dequeing element :%d\n",dequeue());
    linkedlistTraversal(f);
     printf("Dequeing element :%d\n",dequeue());
    linkedlistTraversal(f);
    return 0;
}