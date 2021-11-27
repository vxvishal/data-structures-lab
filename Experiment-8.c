#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};
struct node *start = NULL;

int main()
{
    int choice, exit=0;
    while (exit!=1)
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
        printf("\nThe stored numbers are:\n");
        temp = start;
        while (temp != NULL)
        {
            printf("%d\n", temp->info);
            temp = temp->link;
        }
    }
}

void insertAtFront()
{
    int data;
    struct node *temp;
    temp = malloc(sizeof(struct node));
    printf("\nEnter the number to be inserted: ");
    scanf("%d", &data);
    temp->info = data;

    temp->link = start;
    start = temp;
}

void insertAtEnd()
{
    int data;
    struct node *temp, *head;
    temp = malloc(sizeof(struct node));

    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);

    temp->link = 0;
    temp->info = data;
    head = start;
    while (head->link != NULL)
    {
        head = head->link;
    }
    head->link = temp;
}

void insertAtPosition()
{
    struct node *temp, *newnode;
    int pos, data, i = 1;
    newnode = malloc(sizeof(struct node));

    printf("\nEnter position and data: ");
    scanf("%d %d", &pos, &data);

    temp = start;
    newnode->info = data;
    newnode->link = 0;
    while (i < pos - 1)
    {
        temp = temp->link;
        i++;
    }
    newnode->link = temp->link;
    temp->link = newnode;
}

void deleteFirst()
{
    struct node *temp;
    if (start == NULL)
        printf("\nList is empty\n");
    else
    {
        temp = start;
        start = start->link;
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
        while (temp->link != 0)
        {
            prevnode = temp;
            temp = temp->link;
        }
        free(temp);
        prevnode->link = 0;
    }
}

void deletePosition()
{
    struct node *temp, *position;
    int i = 1, pos;

    if (start == NULL)
        printf("\nList is empty\n");

    else
    {
        printf("\nEnter the position: ");

        scanf("%d", &pos);
        position = malloc(sizeof(struct node));
        temp = start;

        while (i < pos - 1)
        {
            temp = temp->link;
            i++;
        }

        position = temp->link;
        temp->link = position->link;

        free(position);
    }
}

void search()  
{  
    struct node *ptr;  
    int item,i=0,flag;  
    ptr = start;   
    if(ptr == NULL)  
        printf("\nList is empty\n");  
    else  
    {   
        printf("\nEnter the number to be searched: ");   
        scanf("%d",&item);  
        while (ptr!=NULL)  
        {  
            if(ptr->info == item)  
            {  
                printf("Number found at location %d\n",i+1);  
                flag=0;  
                break;
            }   
            else  
                flag=1;   
            i++;  
            ptr = ptr -> link;  
        }  
        if(flag==1)  
            printf("Number not found\n");  
    }            
}  
