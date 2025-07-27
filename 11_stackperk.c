#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr; // interger pointer which use to allocate dynamic memory
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow!! Cannot push %d to the stack", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow!! Cannot pop to the stack");
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct stack *sp, int i)
{
    int arrayInd =sp->top-i+1;
    if (arrayInd < 0)
    {
        printf("Not a valid position for the stack");
        return -1;
    }
    else
    {
        return sp->arr[arrayInd];
    }
}

int main()
{
    // pointer
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    // sp use to store address    // struct stack ka instance
    sp->size = 8;
    sp->top = -1; //-1 means there is no element
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    printf("The stack has been created sucessfully\n");

    // check if stack is empty
    printf("Before pushing ,full:%d\n", isFull(sp));
    printf("Before pushing ,empty:%d\n", isEmpty(sp));
    push(sp, 81);
    push(sp, 30);
    push(sp, 46);
    push(sp, 86);
    push(sp, 56);
    push(sp, 79);
    push(sp, 54);
    push(sp, 16);
    push(sp, 96); // stack overflow because the size of stack is 8
    printf("After pushing ,full:%d\n", isFull(sp));
    printf("After pushing ,empty:%d\n", isEmpty(sp));

    printf("Popped %d from  the stack\n", pop(sp));

    for (int j = 1; j < sp->top + 1; j++)
    {
        printf("\nThe value at position %d is %d", j, peek(sp,j));
    }

    return 0;
}
