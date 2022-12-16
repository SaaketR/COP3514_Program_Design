/*
Saaket Raman - Project 3

This program evaluates if the elements of an array have the same parities as their respective indices. The program first asks
the user for the length of their required array and hence for the array itself. It then steps through the array to evaluate 
the parities. Parities are evaluated using the remainder when divided by 2 (modulo operator). If the parities of an element and 
its index do not match, a boolean variable, "parity_match", is evaluated as False (0). Thus, an output is printed.

*/
#include <stdio.h>

int main(void)
{
    // Building the input array:
    int num;
    printf("Enter the length of the array: ");
    scanf("%d", &num);
    int a[num];
    
    printf("Enter the elements of the array: ");
    int i;
    for (i = 0; i < num; i++){
        scanf("%d", &a[i]);
    }

    // Evaluating the parity match:
    int parity_match = 1;       // boolean to store if parities match or not; set to True (1) by default.

    for (i=0; i<num; i++){
        if (((a[i] % 2 == 0) && (i % 2 != 0)) || ((a[i] % 2 != 0) && (i % 2 == 0))){
            parity_match = 0;
            break;
        }
    }

    // Output depending on the parity match:
    switch (parity_match){
        case 0: printf("Parities of the elements do not match parities of indices. \n");
                break;
        case 1: printf("Parities of the elements match parities of indices. \n");
                break;
    }


    return 0;
    
}