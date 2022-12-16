/*
Saaket Raman - Project 10

This programs contains the main function from project9_roster.c and includes another file, student.h. Like in Project 9, this program
maintains a roster for a youth orchestra group and is able to add students to the roster, search for a student, print the entire roster, 
remove any student from the roster, and clear the entire roster. 

*/

#include <stdio.h>
#include "student.h"

int main(void)
{
  char code;

  struct student *student_list = NULL;  
  printf("Operation Code: a for adding to the list, s for searching"
	  ", p for printing the list; q for quit.\n");
  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'a': student_list = add(student_list);   // creating an updated version of the roster after calling the add() function
                break;
      case 's': search(student_list);
                break;
      case 'p': print_list(student_list);
                break;
      case 'r': student_list = remove_from_list(student_list);    // creating an updated version of the roster after calling the remove() function
                break;
      case 'q': clear_list(student_list);
		return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}