#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

void linkedlistTraversal(struct Node *N1)
{
    struct Node *ptr = N1;
    do
    {
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != N1);
}

void linkedlistTraversalReserve(struct Node *N4)
{
    struct Node *ptr = N4;
    do
    {
        printf("Element is %d\n", ptr->data);
        ptr = ptr->prev;
    } while (ptr != N4);
}

int main()
{
    struct Node *N1;
    struct Node *N2;
    struct Node *N3;
    struct Node *N4;

    N1 = (struct Node *)malloc(sizeof(struct Node));
    N2 = (struct Node *)malloc(sizeof(struct Node));
    N3 = (struct Node *)malloc(sizeof(struct Node));
    N4 = (struct Node *)malloc(sizeof(struct Node));

    N1->data = 7;
    N1->next = N2;
    N1->prev = NULL;


    N2->data = 11;
    N2->next = N3;
    N2->prev = N1;

    N3->data = 55;
    N3->next = N4;
    N3->prev = N2;

    N4->data = 66;
    N4->next = N1;
    N4->prev = N3;

printf("Circular Linked list : \n");
    linkedlistTraversal(N1);

    printf("Circular Linked list : \n");
    linkedlistTraversalReserve(N4);
return 0;
}