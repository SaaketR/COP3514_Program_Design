/*
Saaket Raman - U72042781

This program removes the k smallest integers in an array of integers. It asks the user to build an array and hence the number
of smallest integers the user would like to remove. It uses two functions, one that identifies the smallest integer and another
that removes the identified integer. 

*/

#include <stdio.h>

int *remove_smallest_numbers(int a[], int n, int k);

int find_smallest_index(int a[], int n);

int main(void)
{
    // Building the input array:
    int n;
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);
    int a[n];

    printf("Enter the elements of the set: ");
    int i;
    for (i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    // Removing the k smallest integers:
    int k;
    printf("Enter the number of smallest elements to be removed: ");
    scanf("%d", &k);
    
    a[n-k] = *remove_smallest_numbers(a, n, k);     // Updating the array for after the smallest integers are removed.

    // Printing the output array:
    for (i=0; i<n-k; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");

    return 0;
}

int *remove_smallest_numbers(int a[], int n, int k)
{
    int i, smallest_index;
    for (i=1; i<=k; i++)
    {
        smallest_index = find_smallest_index(a, n);

        // Shift all values on the right of smallest_index on index to the left and decrement the size of the array:
        int j;
        for (j=smallest_index; j<n-1; j++)
        {
            a[j] = a[j+1];
        }
        n--;
    }

    return a;
}

int find_smallest_index(int a[], int n)
{
    int smallest_index=0, i;
    for (i=1; i<n; i++)
    {
        if (a[i] < a[smallest_index])       // Searching linearly through the array to see if any element is smaller than the first element.
        {
            smallest_index = i;
        }
    }

    return smallest_index;
}