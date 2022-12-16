/*
Saaket Raman - Project 10

This prgram contains all the functions used in maintaining the student roster in the program project10_roster.c. This program includes the 
headers for the readline() function and the functions specific to maintaining the roster (adding, searching, printing, removing, and clearing).

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readline.h"
#include "student.h"

// Funciton to add new students to the list; first checks if the student already exists by email and last name, then adds students if student does not exist
struct student *add(struct student *list)
{
  // Creating new node; returns if space could not be allocated
  struct student *new_node;
  new_node = malloc(sizeof(struct student));
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
  struct student *p;
  p = list;
  while (p != NULL){
    if (strcmp(p->last, new_node->last)==0 && strcmp(p->email, new_node->email)==0){
      printf("Student already exists in the roster.\n");
      free (new_node);
      return list;
    }
    p = p->next;
  }

  // Student deos not exist, now adding new node to the end of the list
  struct student *curr;
  curr = list;

  if (curr == NULL){    // condition for when the list is empty
    return new_node;
  }

  while (curr != NULL){         // looping through the list to reach the end (where next is a null pointer); does not increment position if it has reached the end
    if (curr->next == NULL){
      break;
    }
    curr = curr->next;
  }
  curr->next = new_node;      // loop has reached the end of the list, now making the list point to the next node
  
  return list;

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
  struct student *curr;
  while (list != NULL){   // directly looping through the list
      curr = list;
      if (curr != NULL){
          free(curr);       // deallocating memory at the current position of the list, and then incremeneting to the next
      }
      list = list->next;
  }
}

// function to remove student from the list using first name, last name, and email

struct student *remove_from_list(struct student *list)
{
  // obtaining the required student's details
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
    if (strcmp(cur->first, first_name)==0 && strcmp(cur->last, last_name)==0 && strcmp(cur->email, email_id)==0){   // condition for match
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
  
  printf("%s %s %s %s %s has been removed.\n", cur->last, cur->first, cur->email, cur->instrument, cur->group);
  free(cur);
  return newlist;
}
