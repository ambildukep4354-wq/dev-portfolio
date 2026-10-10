#include "header.h"


// Add First

struct student *Add_First(struct student *headptr)
{
    struct student *newnode = calloc(1, sizeof(struct student));

    if(newnode == NULL)
    {
        printf("Memory Allocation Fail\n");
        return headptr;
    }

    printf("Enter roll name marks\n");
    scanf("%d %19s %f", &newnode->roll,
                         newnode->name,
                         &newnode->mark);

    newnode->next = headptr;
    headptr = newnode;

    return headptr;
}


// Add Last

struct student *Add_Last(struct student *headptr)
{
    struct student *newnode = calloc(1, sizeof(struct student));
    struct student *temp = headptr;

    if(newnode == NULL)
    {
        printf("Memory Allocation Fail\n");
        return headptr;
    }

    printf("Enter roll name marks\n");
    scanf("%d %19s %f", &newnode->roll,
                         newnode->name,
                         &newnode->mark);

    newnode->next = NULL;

    if(headptr == NULL)
    {
        headptr = newnode;
    }
    else
    {
        for(temp = headptr; temp->next != NULL; temp = temp->next)
        {
        }

        temp->next = newnode;
    }

    return headptr;
}


// Add Middle (position starts from 1)

struct student *Add_Middle(struct student *headptr)
{
    struct student *newnode;
    struct student *temp = headptr;
    int pos, i;

    printf("Enter position\n");
    scanf("%d", &pos);

    if(pos < 1)
    {
        printf("Invalid position\n");
        return headptr;
    }

    if(pos == 1)
    {
        return Add_First(headptr);
    }

    newnode = calloc(1, sizeof(struct student));

    if(newnode == NULL)
    {
        printf("Memory Allocation Fail\n");
        return headptr;
    }

    printf("Enter roll name marks\n");
    scanf("%d %19s %f", &newnode->roll,
                         newnode->name,
                         &newnode->mark);

    for(i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Invalid position\n");
        free(newnode);
        return headptr;
    }

    newnode->next = temp->next;
    temp->next = newnode;

    return headptr;
}


// Delete First

struct student *Del_First(struct student *headptr)
{
    struct student *temp = headptr;

    if(headptr == NULL)
    {
        printf("No data available for deletion\n");
        return headptr;
    }

    headptr = temp->next;
    free(temp);

    return headptr;
}


// Delete Last

struct student *Del_Last(struct student *headptr)
{
    struct student *temp = headptr;

    if(headptr == NULL)
    {
        printf("No data available for deletion\n");
        return NULL;
    }

    if(headptr->next == NULL)
    {
        free(headptr);
        return NULL;
    }

    for(temp = headptr; temp->next->next != NULL; temp = temp->next)
    {
    }

    free(temp->next);
    temp->next = NULL;

    return headptr;
}


// Delete Middle (position starts from 1)

struct student *Delete_Middle(struct student *headptr)
{
    struct student *temp = headptr;
    struct student *delnode;
    int pos, i;

    if(headptr == NULL)
    {
        printf("No data available for deletion\n");
        return headptr;
    }

    printf("Enter position to delete\n");
    scanf("%d", &pos);

    if(pos < 1)
    {
        printf("Invalid position\n");
        return headptr;
    }

    if(pos == 1)
    {
        return Del_First(headptr);
    }

    for(i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if(temp == NULL || temp->next == NULL)
    {
        printf("Invalid position\n");
        return headptr;
    }

    delnode = temp->next;
    temp->next = delnode->next;
    free(delnode);

    return headptr;
}


// Print Nodes

void Print_Node(struct student *headptr)
{
    if(headptr == NULL)
    {
        printf("No data available for printing\n");
        return;
    }

    for(; headptr != NULL; headptr = headptr->next)
    {
        printf("Roll:[%d] Name:[%s] Marks:[%.2f]\n",
                headptr->roll,
                headptr->name,
                headptr->mark);
    }
}


// Reverse List

struct student *Rev_List(struct student *headptr)
{
    struct student *prev = NULL;
    struct student *current = headptr;
    struct student *next = NULL;

    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    headptr = prev;

    return headptr;
}