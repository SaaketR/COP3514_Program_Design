/*
Saaket Raman - Project 4

This program evaluates if two user-inputted sets are mutually disjoint and also computes their symmetric difference.
    i. Two sets, A and B, are mutually disjoint if no elements in A exist in B (and vice versa).
    ii. The symmetric difference of two sets is a set containing elements in A absent in B, and elements in B absent in A.

*/


#include <stdio.h>
#define N 10

int are_mutually_disjoint(int *set_a, int *set_b, int n)
{
    int mutually_disjoint = 1;
    int i;
    for (i = 0; i < N; i++){
        if ((*set_a == 1) && (*set_b == 1)){
            mutually_disjoint = 0;
        }
        set_a++;
        set_b++;
    }
    return mutually_disjoint;
}

void find_symmetric_difference(int *set_a, int *set_b, int n, int *symmetric_difference)
{
    int i;
    for (i = 0; i < N; i++){
        if (((*set_a == 1) && (*set_b == 0)) || ((*set_a == 0) && (*set_b == 1))){
            *symmetric_difference = 1;
        }
        set_a++;
        set_b++;
        symmetric_difference++;
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

    // Performing Mutually Disjoint Operation:

    int mutually_disjoint;
    mutually_disjoint = are_mutually_disjoint(set_a, set_b, N);     // Obtains value of 0 or 1

    // Performing Symmteric Difference Operation:

    int sym_difference[N] = {};
    find_symmetric_difference(set_a, set_b, N, &sym_difference);
    

    // Printing the result for the two operations:

    if (mutually_disjoint == 0){
        printf("The two sets are not mutually disjoint.\n");
    }
    else {
        printf("The two sets are mutually disjoint.\n");
    }

    printf("The symmetric difference is ");

    for (i = 0; i < N; i++){
        if (sym_difference[i] == 1){
            printf("%d ", i);
        }
    }

    printf("\n");

    return 0;
}
