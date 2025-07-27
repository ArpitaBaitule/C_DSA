#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct circularQueue
{
    int size, f, r;
    int *arr;
};

int isFull(struct circularQueue *q)
{
    if (((q->r+1)%q->size) == q->f)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct circularQueue *q)
{
    if (q->f == q->r)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct circularQueue *q, int val)
{
    if (isFull(q))
    {
        printf("The Queue is Full");
    }
    else
    {
       
        q->r = (q->r+1) %q->size ;
        q->arr[q->r] = val;
         printf("The EnQueue element :%d\n",val);
    }
}

int dequeue(struct circularQueue *q)
{
    int a =-1;
    if (isEmpty(q))
    {
        printf("The Queue is Empty");
    }
    else
    {
        q->f = (q->f +1) %q->size;
        a= q->arr[q->f];
    }
    return a;
}
int main()
{
    struct circularQueue q;
    q.size = 4;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    // Enqueue elements
    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 14);
    enqueue(&q, 18);

    printf("Dequeuing element %d\n",dequeue(&q));
    printf("Dequeuing element %d\n",dequeue(&q));
    printf("Dequeuing element %d\n",dequeue(&q));
    printf("Dequeuing element %d\n",dequeue(&q));

    
    if (isEmpty(&q))
    {
        printf("Queue is Empty");
    }
    if (isFull(&q))
    {
        printf("Queue is Full");
    }

    return 0;
}