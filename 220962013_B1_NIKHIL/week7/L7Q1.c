#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *a;
    int front, rear, size, n;
} Queue;

Queue* create(int n)
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->a = (int *)malloc(n * sizeof(int));
    q->front = q->size = 0; 
    q->rear = n - 1; 
    q->size = 0; q->n = n;
    return q; 
}

int isFull(Queue *q) { return q->size >= q->n; }

int isEmpty(Queue *q) { return q->size == 0; }

void insertcq(Queue *q, int x)
{
    if (isFull(q)) {printf("Overflow!!"); return;}
    q->rear = (q->rear + 1) % q->n;
    q->a[q->rear] = x;
    q->size++;
}

int deletecq(Queue *q)
{
    if (isEmpty(q)) {printf("Underflow!!"); return 999;}
    int x = q->a[q->front];
    q->front = (q->front + 1) % q->n;
    q->size--;
    return x;
}

int Front(Queue *q)
{
    if (isEmpty(q)) {return -1;}
    return q->a[q->front];
}

int Rear(Queue *q)
{
    if (isFull(q)) {return -1;}
    return q->a[q->rear];
}

void displaycq(Queue *q)
{
    if (isEmpty(q)) {printf("Queue is empty\n"); return;}
    printf("\nQueue: ");
    int i;
    for (i = q->front; i <= q->rear; i++)
        printf("%d ", q->a[i]);
    if (q->front > q->rear)
    {
        for (i = 0; i <= q->rear; i++)
            printf("%d ", q->a[i]);
    }
    printf("\nSize is %d\n", q->size);
}

int main()
{
    printf("Capacity of queue: "); int n;
    scanf("%d", &n);
    Queue *q = create(n);
    displaycq(q);
    insertcq(q, 1);
    insertcq(q, 2);
    insertcq(q, 3);
    displaycq(q);
    deletecq(q);
    deletecq(q);
    displaycq(q);
    insertcq(q, 4);
    displaycq(q);
    return 0;
}
