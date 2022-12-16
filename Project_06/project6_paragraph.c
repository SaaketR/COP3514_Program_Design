/*
Saaket Raman - Project 6

This program takes the name of an input and output file. it then reads the input file to remove newline characters and 
store the file contents with whitespace characters instead into the output file.

*/

#include <stdio.h>

#define MAX_CHAR_NAME 100
#define MAX_CHAR_LINE 10000

void convert(char *s1, char *s2);       // s1 = line from input file ; s2 = string containing content in s1 without \n

int main()
{
    // Writing the input and output file names
    char input[MAX_CHAR_NAME+1];
    char output[MAX_CHAR_NAME+5] = "new_";

    char *p = &input[0], *q = &output[4];

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

    // Importing the input file and creating the output file
    FILE *in_file;
    in_file = fopen(input, "r");
    if (in_file == NULL){
        printf("Can not open %s\n", input);
        return 1;
    }
    
    FILE *out_file;
    out_file = fopen(output, "w");

    // Calling convert() function and writing on to the output file
    char in_line[MAX_CHAR_LINE+1];
    while (fgets(in_line, MAX_CHAR_LINE+1, in_file) != NULL){
        char out_line[MAX_CHAR_LINE+1] = {0};
        convert(in_line, out_line);
        fputs(out_line, out_file);
    }

    // Closing the input/output files and printing the output file
    fclose(in_file);
    fclose(out_file);
    
    printf("Output file name: %s\n", output);

    return 0;

}

void convert(char *s1, char *s2)        // s1 points to &in_line, s2 points to &out_line
{
    while (*s1 != '\n'){
        *s2 = *s1;
        s1++;
        s2++;
    }
    *s2 = ' ';
}