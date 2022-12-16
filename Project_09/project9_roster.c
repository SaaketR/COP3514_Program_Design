/*
Saaket Raman - Project 9

This program maintains a roster of students in a young orchestra arrangement using linked lists. The program will be able to add, search,
print, and clear the roster depending on what the user intends to do. The roster keeps record of every student's first name, last
name, email, instrument, and group.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define EMAIL_LEN 100
#define NAME_LEN 30
#define INSTRUMENT_LEN 30
#define GROUP_LEN 30

struct student{
	char first[NAME_LEN+1];
	char last[NAME_LEN+1];
	char email[EMAIL_LEN+1];
	char instrument[INSTRUMENT_LEN+1];
	char group[GROUP_LEN+1];
	struct student *next;
};

struct student *add(struct student *list);
void search(struct student *list);
void print_list(struct student *list);
void clear_list(struct student *list);
int read_line(char str[], int n);

struct student *remove_from_list(struct student *list);

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
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
      case 'a': student_list = add(student_list);
                break;
      case 's': search(student_list);
                break;
      case 'p': print_list(student_list);
                break;
      case 'r': student_list = remove_from_list(student_list);
                break;
      case 'q': clear_list(student_list);
		return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}

// Funciton to add new students to the list; first checks if the student already exists by email and last name, then adds students if student does not exist
struct student *add(struct student *list)
{
  // Creating new node; returns if space could not be allocated
  struct student *new_node;
  new_node = malloc(sizeof(struct student)+1);
  if (new_node == NULL){
      printf("Roster is full - can not add more students\n");
      return list;
  }

  // Prompting the user to enter the last name and first name of the new student
  printf("Enter the Last Name: ");
  read_line(new_node->last, NAME_LEN+1);
  printf("Enter the First Name: ");
  read_line(new_node->first, NAME_LEN+1);
  printf("Enter the Email: ");
  read_line(new_node->email, EMAIL_LEN);
  printf("Enter the Instrument: ");
  read_line(new_node->instrument, INSTRUMENT_LEN);
  printf("Enter the Group: ");
  read_line(new_node->group, GROUP_LEN);

  // Finding if the student already exists in the student; returns if student exists
  struct student *c, *p;
  c = list;
  p = NULL;
  while (c != NULL){
    if (strcmp(c->last, new_node->last)==0 && strcmp(c->email, new_node->email)==0){
      printf("Student already exists in the roster.\n");
      free (new_node);
      return list;
    }
    p = c;
    c = c->next;
  }

  if (p == NULL){     // empty list
    list = new_node;
    new_node->next = NULL;
  }
  else {
    p->next = new_node;
    new_node->next = NULL;
  }

  return list;

  /*
  if (p==NULL){   // adding to the beginning of the list
    new_node->next = c;
    return new_node;
  }
  else {
    p->next = new_node;
    new_node->next = c;
    return list;
  }
  */

}

// Searching a particular student in the list by first name and last name
void search(struct student *list)
{
  char last[NAME_LEN+1], first[NAME_LEN+1];
  printf("Enter Last Name: ");
  read_line(last, NAME_LEN);
  printf("Enter First Name: ");
  read_line(first, NAME_LEN);

  printf("======================================================================================================================================================\n");
  struct student *p;
  p = list;
  while (p != NULL){
    if (strcmp(p->last, last)==0 && strcmp(p->first, first)==0){    // condition for when student is found, print details
      printf("%-30s%-30s%-30s%-30s%-30s\n", "LAST NAME", "FIRST NAME", "EMAIL", "INSTRUMENT", "GROUP");
      printf("%-30s%-30s%-30s%-30s%-30s\n", p->last, p->first, p->email, p->instrument, p->group);
      break;
    }
    p = p->next;
  }
  if (p==NULL){   // p is now NULL value since the student is not found
    printf("Student not found.\n");
  }
  printf("======================================================================================================================================================\n");
}

// Printing the roster (with witdth of 30 characters and left alignment)
void print_list(struct student *list)
{
  printf("======================================================================================================================================================\n");
  printf("%-30s%-30s%-30s%-30s%-30s\n", "LAST NAME", "FIRST NAME", "EMAIL", "INSTRUMENT", "GROUP");
  
  struct student *curr;
  curr = list;
  while (curr != NULL){   // looping through the list to access details and print the details
    printf("%-30s%-30s%-30s%-30s%-30s\n", curr->last, curr->first, curr->email, curr->instrument, curr->group);
    curr = curr->next;
  }
  printf("======================================================================================================================================================\n");
}

// Clearing the list (deallocating memory) for when the user exists the program
void clear_list(struct student *list)
{
  struct student *temp;
  //temp = list;
  //printf("FIRST: %s\n", temp->last);
  while (list != NULL){   // directly looping through the list
      temp = list;
      list = list->next;
      if (temp != NULL){
          //printf("%s cleared\n", temp->last);
          free(temp);       // deallocating memory at the current position of the list, and then incremeneting to the next
      }
  }
}

// Function to read the user-inputted line.
int read_line(char str[], int n)
{
  int ch, i = 0;

  while (isspace(ch = getchar()))
    ;
  str[i++] = ch;
  while ((ch = getchar()) != '\n') {
    if (i < n)
      str[i++] = ch;
    
   }
   str[i] = '\0';
   return i;
}

// function to remove student from the list using first name, last name, and email

struct student *remove_from_list(struct student *list)
{
  // obtaining the required student's first name, last name, and email
  char last_name[NAME_LEN+1], first_name[NAME_LEN+1], email_id[EMAIL_LEN+1];
  printf("Enter Last Name: ");
  read_line(last_name, NAME_LEN);
  printf("Enter First Name: ");
  read_line(first_name, NAME_LEN);
  printf("Enter Email: ");
  read_line(email_id, EMAIL_LEN);
  
  struct student *cur, *prev;    // creating a structure for the current element and another for the previous element in the linked list
  struct student *newlist;
  newlist = list;
  prev = NULL;
  cur = newlist;
  while ((cur != NULL)){
    if (strcmp(cur->first, first_name)==0 && strcmp(cur->last, last_name)==0 && strcmp(cur->email, email_id)==0){
      break;
    }
    prev = cur;
    cur = cur->next;
  }

  if (cur == NULL){
    printf("Student does not exist\n");
    return newlist;
  }

  if (prev == NULL){
    newlist = newlist->next;
  }
  else {
    prev->next = cur->next;
  }
  
  printf("Removed student: %s %s %s", last_name, first_name, email_id);
  free(cur);
  return newlist;


  /*
  prev = NULL;
  curr = list;
  while ((curr != NULL) && (strcmp(curr->last,last_name) != 0 || strcmp(curr->first, first_name) != 0 || strcmp(curr->email, email_id) != 0)){
    prev = curr;
    curr = curr->next;
  }
  

  if (cur == NULL){
    printf("Student not found.\n");
    return list;
  }

  if (prev == NULL){
    list = list->next;
  }
  else{
    prev->next = cur->next;
  }
  
  printf("Removed student: %s %s %s", last_name, first_name, email_id);
  free(cur);
  return list;
  */
}
