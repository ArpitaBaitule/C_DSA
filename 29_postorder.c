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

void postOrder(struct node* root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}
int main()
{
    struct node *p = createNode(2);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(12);
    struct node *p3 = createNode(6);
    struct node *p4 = createNode(4);
    // Tree:
    //              2
    //            /  \
    //           1    12
    //          / \
    //         6   4
    //

    // Linking the root nodes with left and right node
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    postOrder(p);

    return 0;
}