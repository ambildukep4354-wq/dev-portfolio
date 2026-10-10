#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>

struct student
{
    int roll;
    char name[20];
    float mark;
    struct student *next;
};

struct student *Add_First(struct student *headptr);
struct student *Add_Last(struct student *headptr);
struct student *Add_Middle(struct student *headptr);

struct student *Del_First(struct student *headptr);
struct student *Del_Last(struct student *headptr);
struct student *Delete_Middle(struct student *headptr);

void Print_Node(struct student *headptr);

struct student *Rev_List(struct student *headptr);

#endif