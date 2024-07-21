#include<stdio.h>
#include<stdlib.h> // include for exit() function

#define MAX 20 // Changed from 10 to 20 as b[20] was declared

void create();
void insert();
void deletion();
void search();
void display();

int b[MAX], n, pos, e, i;

void main()
{
    //clrscr(); // clrscr() is non-standard and not needed in most modern compilers

    int ch;
    char g='y';

    do
    {
        printf("\nMain Menu");
        printf("\n1. Create\n2. Delete\n3. Search\n4. Insert\n5. Display\n6. Exit\n");
        printf("\nEnter your Choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                create();
                break;
            case 2:
                deletion();
                break;
            case 3:
                search();
                break;
            case 4:
                insert();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0); // Properly exit the program
            default:
                printf("Enter the correct choice:\n");
        }

        printf("\nDo you want to continue (y/n): ");
        scanf(" %c", &g); // space before %c to consume newline

    } while(g == 'y' || g == 'Y');

    //getch(); // getch() is non-standard and not needed
}

void create()
{
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
    {
        printf("Element %d: ", i+1);
        scanf("%d", &b[i]);
    }
}

void deletion()
{
    printf("\nEnter the position you want to delete (0 to %d): ", n-1);
    scanf("%d", &pos);

    if(pos < 0 || pos >= n)
    {
        printf("\nInvalid Location!\n");
    }
    else
    {
        for(i = pos; i < n - 1; i++)
        {
            b[i] = b[i+1];
        }
        n--;

        printf("\nThe elements after deletion:\n");
        display();
    }
}

void search()
{
    printf("\nEnter the element to be searched: ");
    scanf("%d", &e);

    for(i = 0; i < n; i++)
    {
        if(b[i] == e)
        {
            printf("Value %d is found at position %d.\n", e, i);
            return; // exit function after finding the element
        }
    }
    
    printf("Value %d is not in the list.\n", e);
}

void insert()
{
    printf("\nEnter the position you need to insert (0 to %d): ", n);
    scanf("%d", &pos);

    if(pos < 0 || pos > n)
    {
        printf("\nInvalid Location!\n");
    }
    else
    {
        printf("Enter the element to insert: ");
        scanf("%d", &e);

        for(i = n - 1; i >= pos; i--)
        {
            b[i+1] = b[i];
        }
        b[pos] = e;
        n++;

        printf("\nThe list after insertion:\n");
        display();
    }
}

void display()
{
    if(n == 0)
    {
        printf("\nThe list is empty.\n");
    }
    else
    {
        printf("\nThe elements of the list are:\n");
        for(i = 0; i < n; i++)
        {
            printf("%d ", b[i]);
        }
        printf("\n");
    }
}
