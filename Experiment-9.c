#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *prev, *next;
};
struct node *start = NULL;

int main()
{
    int choice, exit = 0;
    while (exit != 1)
    {
        printf("\n1. Insert at the beginning\n2. Insert at the end\n3. Insert at a given position\n4. Delete at the beginning\n5. Delete at the end\n6. Delete at a given position\n7. Search\n8. Print\n9. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertAtFront();
            break;
        case 2:
            insertAtEnd();
            break;
        case 3:
            insertAtPosition();
            break;
        case 4:
            deleteFirst();
            break;
        case 5:
            deleteEnd();
            break;
        case 6:
            deletePosition();
            break;
        case 7:
            search();
            break;
        case 8:
            traverse();
            break;
        case 9:
            exit++;
            break;
        default:
            printf("\nInvalid choice\n");
            continue;
        }
    }
    getch();
    return 0;
}

void traverse()
{
    struct node *temp;

    if (start == NULL)
        printf("\nList is empty\n");

    else
    {
        printf("\nThe numbers stored are:\n");
        temp = start;
        while (temp != NULL)
        {
            printf("%d\n", temp->info);
            temp = temp->next;
        }
    }
}

void insertAtFront()
{
    int data;
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the number to be inserted: ");
    scanf("%d", &data);
    temp->info = data;
    temp->prev = NULL;
    temp->next = start;
    start = temp;
}

void insertAtEnd()
{
    int data;
    struct node *temp, *trav;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->next = NULL;
    printf("\nEnter the number to be inserted: ");
    scanf("%d", &data);
    temp->info = data;
    temp->next = NULL;
    trav = start;

    if (start == NULL)
        start = temp;

    else
    {
        while (trav->next != NULL)
            trav = trav->next;
        temp->prev = trav;
        trav->next = temp;
    }
}

void insertAtPosition()
{
    int data, pos, i = 1;
    struct node *temp, *newnode;
    newnode = malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->prev = NULL;

    printf("\nEnter the position : ");
    scanf("%d", &pos);
    printf("Enter the number to be inserted: ");
    scanf("%d", &data);
    newnode->info = data;
    temp = start;

    if (start == NULL)
    {
        start = newnode;
        newnode->prev = NULL;
        newnode->next = NULL;
    }

    else if (pos == 1)
    {
        newnode->next = start;
        newnode->next->prev = newnode;
        newnode->prev = NULL;
        start = newnode;
    }

    else
    {
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next = newnode;
        temp->next->prev = newnode;
    }
}

void deleteFirst()
{
    struct node *temp;
    if (start == NULL)
        printf("\nList is empty\n");
    else
    {
        temp = start;
        start = start->next;
        if (start != NULL)
            start->prev = NULL;
        free(temp);
    }
}

void deleteEnd()
{
    struct node *temp, *prevnode;
    if (start == NULL)
        printf("\nList is empty\n");
    else
    {
        temp = start;
        while (temp->next != 0)
        {
            prevnode = temp;
            temp = temp->next;
        }
        free(temp);
        prevnode->next = 0;
    }
}

void deletePosition()
{
    int pos, i = 1;
    struct node *temp, *position;
    temp = start;

    if (start == NULL)
        printf("\nList is empty\n");

    else
    {
        printf("\nEnter the position : ");
        scanf("%d", &pos);

        if (pos == 1)
        {
            position = start;
            start = start->next;
            if (start != NULL)
                start->prev = NULL;
            free(position);
            return;
        }

        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        position = temp->next;
        if (position->next != NULL)
            position->next->prev = temp;

        temp->next = position->next;
        free(position);
    }
}

void search()
{
    struct node *ptr;
    int item, i = 0, flag;
    ptr = start;
    if (ptr == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        printf("\nEnter the number to be searched: ");
        scanf("%d", &item);
        while (ptr != NULL)
        {
            if (ptr->info == item)
            {
                printf("Number found at location %d\n", i + 1);
                flag = 0;
                break;
            }
            else
                flag = 1;
            i++;
            ptr = ptr->next;
        }
        if (flag == 1)
            printf("Number not found\n");
    }
}