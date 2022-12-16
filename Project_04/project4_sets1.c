/*
Saaket Raman - Project 4

This program finds the set difference of two user-inputted sets (A and B). The set difference, A-B, will return the elements
in A that are not present in B. The sets are represented in arrays of 0s and 1s, where a 0 at index i represents the absence
of a number and a 1 represents the presence of the number i at index i.
*/

#include <stdio.h>
#define N 10

void find_set_difference(int *set_a, int *set_b, int n, int *set_difference)
{
    int i;
    for (i = 0; i < N; i++){
        if ((*set_a==1) && (*set_b==0)){
            *set_difference = 1;
        } 
        set_a++;
        set_b++;
        set_difference++;
    }
}

int main()
{
    int i, num_elements, curr_element;
    
    // Building Set A:

    int set_a[N] = {};

    printf("Enter the number of elements of A: ");
    scanf("%d", &num_elements);

    printf("Enter the numbers in set A: ");
    for (i = 0; i < num_elements; i++){
        scanf("%d", &curr_element);
        set_a[curr_element] = 1;
    }

    // Building Set B:

    int set_b[N] = {};

    printf("Enter the number of elements of B: ");
    scanf("%d", &num_elements);

    printf("Enter the numbers in set B: ");
    for (i = 0; i < num_elements; i++){
        scanf("%d", &curr_element);
        set_b[curr_element] = 1;
    }

    // Performing the Set Difference Operation:

    int set_difference[N] = {};
    find_set_difference(set_a, set_b, N, &set_difference);

    // Printing the set difference:

    printf("The difference of set A and set B is: ");

    for (i = 0; i < N; i++){
        if (set_difference[i] == 1){
            printf("%d ", i);
        }
    }

    printf("\n");

    return 0;
}
