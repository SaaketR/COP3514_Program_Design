/*
Saaket Raman - Project 10

This program contains all the header lines thus used in the program student.c. 

*/

#ifndef student
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
struct student *remove_from_list(struct student *list);

#endif