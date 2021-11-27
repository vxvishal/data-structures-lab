#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *ptr;
} * top, *top1, *temp;

int topelement();
void push(int data);
void pop();
void empty();
void display();
void destroy();
void stack_count();
void create();

int count = 0;

void main()
{
    int no, ch, e, exit=0;
    create();

    while (exit!=1)
    {
        printf("\n1. Push\n2. Pop\n3. Top\n4. Empty\n5. Stack count\n6. Destroy stack\n7. Display\n8. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nEnter the data: ");
            scanf("%d", &no);
            push(no);
            break;
        case 2:
            pop();
            break;
        case 3:
            if (top == NULL)
                printf("\nNo elements in stack\n");
            else
            {
                e = topelement();
                printf("\nTop element: %d\n", e);
            }
            break;
        case 4:
            empty();
            break;
        case 5:
            stack_count();
            break;
        case 6:
            destroy();
            break;
        case 7:
            display();
            break;
        case 8:
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
    top = NULL;
}

void stack_count()
{
    printf("\nTotal elements in the stack : %d\n", count);
}

void push(int data)
{
    if (top == NULL)
    {
        top = (struct node *)malloc(1 * sizeof(struct node));
        top->ptr = NULL;
        top->info = data;
    }
    else
    {
        temp = (struct node *)malloc(1 * sizeof(struct node));
        temp->ptr = top;
        temp->info = data;
        top = temp;
    }
    count++;
}

void display()
{
    top1 = top;
    if (top1 == NULL)
    {
        printf("\nStack is empty\n");
        return;
    }
    printf("\nThe data in the stack are: \n");
    while (top1 != NULL)
    {
        printf("%d\n", top1->info);
        top1 = top1->ptr;
    }
}

void pop()
{
    top1 = top;

    if (top1 == NULL)
    {
        printf("\nStack is empty\n");
        return;
    }
    else
        top1 = top1->ptr;
    printf("\nPopped value: %d\n", top->info);
    free(top);
    top = top1;
    count--;
}

int topelement()
{
    return (top->info);
}
void empty()
{
    if (top == NULL)
        printf("\nStack is empty\n");
    else
        printf("\nStack is not empty with %d elements\n", count);
}

void destroy()
{
    top1 = top;
    while (top1 != NULL)
    {
        top1 = top->ptr;
        free(top);
        top = top1;
        top1 = top1->ptr;
    }
    free(top1);
    top = NULL;
    printf("\nAll stack elements destroyed\n");
}
