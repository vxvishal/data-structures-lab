#include <stdio.h>
#include <stdlib.h>

struct btnode
{
    int value;
    struct btnode *l;
    struct btnode *r;
} *root = NULL, *temp = NULL, *t2, *t1;

void delete1();
void insert();
void delete ();
void inorder(struct btnode *t);
void create();
void search(struct btnode *t);
void preorder(struct btnode *t);
void postorder(struct btnode *t);
void search1(struct btnode *t, int data);
int smallest(struct btnode *t);
int largest(struct btnode *t);
void searchnum();

int flag = 1;

void main()
{
    int ch, exit=0;
    while (exit!=1)
    {
        printf("\n******** Menu ********");
        printf("\n1. Insert\n2. Delete\n3. Inorder traversal\n4. Preorder traversal\n5. Postorder traversal\n6. Find largest value\n7. Find smallest value\n8. Search\n9. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            printf("\nThe inorder traversal is: ");
            inorder(root);
            printf("\n");
            break;
        case 4:
            printf("\nThe preorder traversal is: ");
            preorder(root);
            printf("\n");
            break;
        case 5:
            printf("\nThe postorder traversal is: ");
            postorder(root);
            printf("\n");
            break;
        case 6:
            printf("\nLargest value: %d\n", largest(root));
            break;
        case 7:
            printf("\nSmallest value: %d\n", smallest(root));
            break;
        case 8:
            searchnum();
            break;
        case 9:
            exit++;
            break;
        default:
            printf("\nWrong choice\n");
            break;
        }  
    }
    getch();
}

void insert()
{
    create();
    if (root == NULL)
        root = temp;
    else
        search(root);
}

void create()
{
    int data;
    printf("\nEnter the data to be inserted: ");
    scanf("%d", &data);
    temp = (struct btnode *)malloc(1 * sizeof(struct btnode));
    temp->value = data;
    temp->l = temp->r = NULL;
}

void search(struct btnode *t)
{
    if ((temp->value > t->value) && (t->r != NULL))
        search(t->r);
    else if ((temp->value > t->value) && (t->r == NULL))
        t->r = temp;
    else if ((temp->value < t->value) && (t->l != NULL))
        search(t->l);
    else if ((temp->value < t->value) && (t->l == NULL))
        t->l = temp;
}

void inorder(struct btnode *t)
{
    if (root == NULL)
    {
        printf("\nTree is empty\n");
        return;
    }
    if (t->l != NULL)
        inorder(t->l);
    printf("%d -> ", t->value);
    if (t->r != NULL)
        inorder(t->r);
}

void delete ()
{
    int data;

    if (root == NULL)
    {
        printf("\nTree is empty\n");
        return;
    }
    printf("\nEnter the data to be deleted: ");
    scanf("%d", &data);
    t1 = root;
    t2 = root;
    search1(root, data);
}

void preorder(struct btnode *t)
{
    if (root == NULL)
    {
        printf("\nTree is empty\n");
        return;
    }
    printf("%d -> ", t->value);
    if (t->l != NULL)
        preorder(t->l);
    if (t->r != NULL)
        preorder(t->r);
}

void postorder(struct btnode *t)
{
    if (root == NULL)
    {
        printf("\nTree is empty\n");
        return;
    }
    if (t->l != NULL)
        postorder(t->l);
    if (t->r != NULL)
        postorder(t->r);
    printf("%d -> ", t->value);
}

void search1(struct btnode *t, int data)
{
    if ((data > t->value))
    {
        t1 = t;
        search1(t->r, data);
    }
    else if ((data < t->value))
    {
        t1 = t;
        search1(t->l, data);
    }
    else if ((data == t->value))
        delete1(t);
}

void delete1(struct btnode *t)
{
    int k;
    if ((t->l == NULL) && (t->r == NULL))
    {
        if (t1->l == t)
            t1->l = NULL;
        else
            t1->r = NULL;
        t = NULL;
        free(t);
        return;
    }

    else if ((t->r == NULL))
    {
        if (t1 == t)
        {
            root = t->l;
            t1 = root;
        }
        else if (t1->l == t)
            t1->l = t->l;
        else
            t1->r = t->l;
        t = NULL;
        free(t);
        return;
    }

    else if (t->l == NULL)
    {
        if (t1 == t)
        {
            root = t->r;
            t1 = root;
        }
        else if (t1->r == t)
            t1->r = t->r;
        else
            t1->l = t->r;
        t == NULL;
        free(t);
        return;
    }

    else if ((t->l != NULL) && (t->r != NULL))
    {
        t2 = root;
        if (t->r != NULL)
        {
            k = smallest(t->r);
            flag = 1;
        }
        else
        {
            k = largest(t->l);
            flag = 2;
        }
        search1(root, k);
        t->value = k;
    }
}

void searchnum()
{
    struct btnode *ptr;
    int item, i = 0, flag;
    ptr = root;
    if (ptr == NULL)
        printf("\nTree is empty\n");
    else
    {
        printf("\nEnter the number to be searched: ");
        scanf("%d", &item);
        while (ptr != NULL)
        {
            if (ptr->value == item)
            {
                printf("Number found at location %d\n", i + 1);
                flag = 0;
                break;
            }
            else
                flag = 1;
            i++;
            ptr = ptr->r;
        }
        if (flag == 1)
            printf("Number not found\n");
    }
}

int smallest(struct btnode *t)
{
    t2 = t;
    if (t->l != NULL)
    {
        t2 = t;
        return (smallest(t->l));
    }
    else
        return (t->value);
}

int largest(struct btnode *t)
{
    if (t->r != NULL)
    {
        t2 = t;
        return (largest(t->r));
    }
    else
        return (t->value);
}