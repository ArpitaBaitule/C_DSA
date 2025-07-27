// Linked Representation of Binary tree 

#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *n;                                 // creating a node pointer
    n = (struct node *)malloc(sizeof(struct node)); // alocating memory in heap
    n->data = data;                                    // setting the data
    n->left = NULL;                                 // setting the left and right children to null
    n->right = NULL;                                // setting the left and right children to null
    return n;                                       // return the created node
}
int main()
{

    // //Constructing the  root node
    // struct node *p;
    // p= (struct node*) malloc (sizeof(struct node));
    // p->data=2;
    // p->left=NULL;
    // p->right=NULL;

    // //Constructing the second node
    //  struct node *p1;
    // p1= (struct node*) malloc (sizeof(struct node));
    // p1->data=4;
    // p1->left=NULL;
    // p1->right=NULL;

    // //Constructing the third node
    //  struct node *p2;
    // p2= (struct node*) malloc (sizeof(struct node));
    // p2->data=6;
    // p2->left=NULL;
    // p2->right=NULL;

    // //Linking the root nodes with left and right node
    // p->left=p1;
    // p->right=p2;

    // Constructing the  root node---->using function
    struct node *p = createNode(2);
    struct node *p1 = createNode(2);
    struct node *p2 = createNode(2);

    // Linking the root nodes with left and right node
    p->left = p1;
    p->right = p2;

    return 0;
}