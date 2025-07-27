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
    n->data = data;                                 // setting the data
    n->left = NULL;                                 // setting the left and right children to null
    n->right = NULL;                                // setting the left and right children to null
    return n;                                       // return the created node
}

void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int isBST(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}

struct node *search(struct node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (key == root->data)
    {
        return root;
    }
    else if (key < root->data)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}

struct node *inOrderPredecesor(struct node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
struct node *deleteNode(struct node *root, int value)
{
    struct node *inPre;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }

    // Search for the node to be delete
    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    // when the node is found
    else
    {
        inPre = inOrderPredecesor(root);
        root->data = inPre->data;
        root->left = deleteNode(root->left, inPre->data);
    }
    return root;
}

int main()
{
    struct node *p = createNode(12);
    struct node *p1 = createNode(6);
    struct node *p2 = createNode(17);
    struct node *p3 = createNode(4);
    struct node *p4 = createNode(10);
    // Tree:
    //             12
    //            /  \
    //           6    17
    //          / \
    //         4   10
    //

    // Linking the root nodes with left and right node
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    inOrder(p);
    deleteNode(p, 6);
    printf("\n");
    printf("Data is :%d\n",p->data);
    inOrder(p);

    return 0;
}