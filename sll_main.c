#include "header.h"

int main()
{
    struct student *headptr = NULL;
    int choice;

    while(1)
    {
        printf("\n========== SINGLY LINKED LIST ==========\n");
        printf("1. Add First\n");
        printf("2. Add Last\n");
        printf("3. Add Middle / Position\n");
        printf("4. Delete First\n");
        printf("5. Delete Last\n");
        printf("6. Delete Middle / Position\n");
        printf("7. Print List\n");
        printf("8. Reverse List\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");

        if(scanf("%d", &choice) != 1)
        {
            printf("Invalid input\n");
            break;
        }

        switch(choice)
        {
            case 1:
                headptr = Add_First(headptr);
                break;

            case 2:
                headptr = Add_Last(headptr);
                break;

            case 3:
                headptr = Add_Middle(headptr);
                break;

            case 4:
                headptr = Del_First(headptr);
                break;

            case 5:
                headptr = Del_Last(headptr);
                break;

            case 6:
                headptr = Delete_Middle(headptr);
                break;

            case 7:
                Print_Node(headptr);
                break;

            case 8:
                headptr = Rev_List(headptr);
                printf("List reversed successfully\n");
                break;

            case 0:
            {
                struct student *temp;

                while(headptr != NULL)
                {
                    temp = headptr;
                    headptr = headptr->next;
                    free(temp);
                }

                printf("Program terminated\n");
                return 0;
            }

            default:
                printf("Invalid choice\n");
        }
    }

    /* Free allocated nodes before exiting after invalid menu input */
    while(headptr != NULL)
    {
        struct student *temp = headptr;
        headptr = headptr->next;
        free(temp);
    }

    return 0;
}