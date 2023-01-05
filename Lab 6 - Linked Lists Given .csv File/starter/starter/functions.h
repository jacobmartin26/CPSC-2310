/**************************
 * Jacob Martin
 * CPSC 2310 Fall 22
 * UserName: jmart52
 * Instructor: Dr. Yvon Feaster 
*************************/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//implement BDay struct here
typedef struct BDay
{
	int month;
	int day;
	int year;
}BDay_t;


//implement node_t struct here
//use typedef on this struct!
typedef struct Node
{
	struct Node* next;
	BDay_t bday;
	char chose[500];
	char song[100];
	char pastime[100];
	char firstName[20];
	char lastName[20];
}node_t;

/* Parameters: node - The node to be added to the list
 *             head - The head of the list
 *
 * Return: Does not return anything
 * 
 * Description: This function is used to add the node
 * 				to the end of the linked list
 */
void add(node_t** node, node_t** head);

/* Parameters: input - The file that contains the data
					   that is read into the linked list
 *
 * Return: returns "newNode", which contains data from
 * 		   input file, to createList
 * 
 * Description: This function reads the data from input file.
 *              Memory is allocated for this newly created node
 * 				and a scanset is used to read in the data.
 */
node_t* readNodeInfo(FILE* input);

/* Parameters: Takes in a file pointer that contains data
			   to be read, and the address of the 
			   head of the list.
 *
 * Return: Returns a pointer to the head of the list
 * 
 * Description: Called in main and begins list creation.
 * 				Loops through each record in the file
 * 				and adds the record to the list.
 */
node_t* createList(FILE*, node_t**);

/* Parameters: Takes in a file pointer to be written in
 *			   and the address of the head of the list
 *
 * Return: Does not return anything
 * 
 * Description: This function prints the data from the list
 * 				to the output file. Exits if list is empty.
 * 				Months are formatted to words, and a border
 * 				is printed before and after data printing.
 */
void printList(FILE*, node_t*);

/* Parameters: Takes in a file pointre to be written into
 *
 * Return: Does not return anything
 * 
 * Description: Simply prints 80 asterisks to the file
 */
void printBorder(FILE*);

/* Parameters: Takes in address of head of the list
 *
 * Return: Does not return anything
 * 
 * Description: Frees the memory from the list
 * 				and gives it back to the system
 */
void deleteList(node_t**);

#endif
