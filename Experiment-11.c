#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *ptr;
} * front, *rear, *temp, *front1;

int frontelement();
void enq(int data);
void deq();
void empty();
void display();
void create();
void queuesize();

int count = 0;

void main()
{
    int no, ch, e, exit=0;
    create();
    while (exit!=1)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Front element\n4. Empty\n5. Queue size\n6. Display\n7. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the value: ");
            scanf("%d", &no);
            enq(no);
            break;
        case 2:
            deq();
            break;
        case 3:
            e = frontelement();
            if (e != 0)
                printf("\nFront element: %d\n", e);
            else
                printf("\nQueue is empty\n");
            break;
        case 4:
            empty();
            break;
        case 5:
            queuesize();
            break;
        case 6:
            display();
            break;
        case 7:
            exit++;
            break;
        default:
            printf("\nWrong choice\n");
            break;
        }
    }
    getch();
}

void create()
{
    front = rear = NULL;
}

void queuesize()
{
    printf("\nQueue size: %d\n", count);
}

void enq(int data)
{
    if (rear == NULL)
    {
        rear = (struct node *)malloc(1 * sizeof(struct node));
        rear->ptr = NULL;
        rear->info = data;
        front = rear;
    }
    else
    {
        temp = (struct node *)malloc(1 * sizeof(struct node));
        rear->ptr = temp;
        temp->info = data;
        temp->ptr = NULL;

        rear = temp;
    }
    count++;
}

void display()
{
    front1 = front;

    if ((front1 == NULL) && (rear == NULL))
    {
        printf("\nQueue is empty\n");
        return;
    }
    printf("\nThe data stored in the queue is:\n");
    while (front1 != rear)
    {
        printf("%d\n", front1->info);
        front1 = front1->ptr;
    }
    if (front1 == rear)
        printf("%d\n", front1->info);
}

void deq()
{
    front1 = front;

    if (front1 == NULL)
    {
        printf("\nQueue is empty\n");
        return;
    }
    else if (front1->ptr != NULL)
    {
        front1 = front1->ptr;
        printf("\nDequeued value: %d\n", front->info);
        free(front);
        front = front1;
    }
    else
    {
        printf("\nDequeued value: %d\n", front->info);
        free(front);
        front = NULL;
        rear = NULL;
    }
    count--;
}

int frontelement()
{
    if ((front != NULL) && (rear != NULL))
        return (front->info);
    else return 0;
}

void empty()
{
    if ((front == NULL) && (rear == NULL))
        printf("\nQueue is empty\n");
    else
        printf("\nQueue is not empty\n");
}