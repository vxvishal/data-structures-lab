#include <stdio.h>

#define SIZE 10

void push(int);
void pop();
void display();

int stack[SIZE], top = -1;

int main()
{
    int value, choice, exit=0;
    while (exit!=1)
    {
        printf("\n***** Menu *****\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit++;
            getch();
            break;
        default:
            printf("\nWrong selection. Try again.\n");
        }
    }
    return 0;
}
void push(int value)
{
    if (top == SIZE - 1)
        printf("\nStack is full");
    else
    {
        top++;
        stack[top] = value;
        printf("\nValue inserted");
    }
}
void pop()
{
    if (top == -1)
        printf("\nStack is empty");
    else
    {
        printf("\nDeleted : %d", stack[top]);
        top--;
    }
}
void display()
{
    if (top == -1)
        printf("\nStack is empty");
    else
    {
        int i;
        printf("\nStack elements are:\n");
        for (i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}