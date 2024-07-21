#include<stdio.h>

struct poly {
    int coeff;
    int expo;
};

int readPoly(struct poly []);
int addPoly(struct poly [], struct poly [], int, int, struct poly []);
void displayPoly(struct poly [], int);

int main()
{
    struct poly p1[10], p2[10], p3[10]; // Arrays to store polynomials
    int t1, t2, t3; // Number of terms in polynomials

    t1 = readPoly(p1);
    printf("\nFirst polynomial: ");
    displayPoly(p1, t1);

    t2 = readPoly(p2);
    printf("\nSecond polynomial: ");
    displayPoly(p2, t2);

    t3 = addPoly(p1, p2, t1, t2, p3);
    printf("\n\nResultant polynomial after addition: ");
    displayPoly(p3, t3);

    printf("\n");

    return 0;
}

int readPoly(struct poly p[10])
{
    int t, i;
    
    printf("\nEnter the total number of terms in the polynomial: ");
    scanf("%d", &t);
    
    printf("Enter the COEFFICIENT and EXPONENT in DESCENDING ORDER\n");
    for(i = 0; i < t; i++)
    {
        printf("Enter the Coefficient(%d): ", i+1);
        scanf("%d", &p[i].coeff);
        printf("Enter the exponent(%d): ", i+1);
        scanf("%d", &p[i].expo);
    }
    
    return t;
}

int addPoly(struct poly p1[10], struct poly p2[10], int t1, int t2, struct poly p3[10])
{
    int i = 0, j = 0, k = 0;
    
    while (i < t1 && j < t2)
    {
        if (p1[i].expo == p2[j].expo)
        {
            p3[k].coeff = p1[i].coeff + p2[j].coeff;
            p3[k].expo = p1[i].expo;
            i++;
            j++;
            k++;
        }
        else if (p1[i].expo > p2[j].expo)
        {
            p3[k].coeff = p1[i].coeff;
            p3[k].expo = p1[i].expo;
            i++;
            k++;
        }
        else
        {
            p3[k].coeff = p2[j].coeff;
            p3[k].expo = p2[j].expo;
            j++;
            k++;
        }
    }
    
    while (i < t1)
    {
        p3[k].coeff = p1[i].coeff;
        p3[k].expo = p1[i].expo;
        i++;
        k++;
    }
    
    while (j < t2)
    {
        p3[k].coeff = p2[j].coeff;
        p3[k].expo = p2[j].expo;
        j++;
        k++;
    }
    
    return k; 
}

void displayPoly(struct poly p[10], int term)
{
    int i;
    
    for (i = 0; i < term - 1; i++)
    {
        printf("%dx^%d + ", p[i].coeff, p[i].expo);
    }
    printf("%dx^%d", p[i].coeff, p[i].expo);
}
