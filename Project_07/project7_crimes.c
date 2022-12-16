/*
Saaket Raman - Project 7

This project reads in state-based violent crime data and arranges the data in descending order. The sorted data is then printed
on to an output file (named "sorted_" preceding the input file name). The sorting algorithm used is selection sort.
*/

#include <stdio.h>
#define MAX_STATES 100
#define MAX_STATE_CHAR 150
#define MAX_FILE_NAME 30

// Defining the structure for the state data
struct state_struct{
    char name[MAX_STATE_CHAR];
    int population;
    double rate_assault;
    double rate_murder;
    double rate_rape;
    double rate_violent_robbery;
    double total_assault;
};

void sort_states(struct state_struct list[], int n);    // sorting algorithm

int main()
{
    // Naming input and output files:
    char input[MAX_FILE_NAME], output[MAX_FILE_NAME+7] = "sorted_";
    char *p = &input[0], *q = &output[7];
    printf("Enter the file name: ");
    int ch;
    while ((ch = getchar()) != '\n'){
        *p = ch;
        *q = ch;
        p++;
        q++;
    }
    *p = '\0';
    *q = '\0';

    // Opening input file and creating the output file
    FILE *in_file;
    in_file = fopen(input, "r");
    if (in_file == NULL){       // condition for if a file with the input name does not exist
        printf("Can not open %s\n", input);
        return 1;
    }
    
    FILE *out_file;
    out_file = fopen(output, "w");

    // Reading data from input file and storing into the structure state
    struct state_struct states[MAX_STATES];     // creating a new structure "states"
    int state_index = 0;
    while (!feof(in_file) && !ferror(in_file)){
        fscanf(in_file, "%[^,], %d, %lf, %lf, %lf, %lf\n", 
            &states[state_index].name, &states[state_index].population, &states[state_index].rate_assault, 
            &states[state_index].rate_murder, &states[state_index].rate_rape, &states[state_index].rate_violent_robbery);
        
        // Finding total assualt rates
        double total = states[state_index].rate_assault
                + states[state_index].rate_murder
                + states[state_index].rate_rape
                + states[state_index].rate_violent_robbery;
        states[state_index].total_assault = total;
        
        state_index++;
    }

    // Sorting
    sort_states(states, state_index);
    
    // Printing sorted data onto the output file
    int j=0;
    while (j < state_index){
        fprintf(out_file, "%s,%d,%.1lf,%.1lf,%.1lf, %.1lf\n", 
            states[j].name, states[j].population, states[j].rate_assault, 
            states[j].rate_murder, states[j].rate_rape, states[j].rate_violent_robbery);
        j++;
    }
    
    fclose(in_file);
    fclose(out_file);

    printf("Output file: %s\n", output);
    return 0;

}

// Sorting the state data

void sort_states(struct state_struct list[], int n)
{
    int i = 0;
    while (i < n-1){
        int j = i+1;
        while (j < n){
            if (list[j].total_assault > list[i]. total_assault){
                struct state_struct temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
            j++;
        }
        i++;
    }
}