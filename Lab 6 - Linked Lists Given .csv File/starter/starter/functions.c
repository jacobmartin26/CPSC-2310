/**************************
 * Jacob Martin
 * CPSC 2310 Fall 22
 * UserName: jmart52
 * Instructor: Dr. Yvon Feaster 
*************************/

#include "functions.h"

void add(node_t** node, node_t** head)
{
	//Temporary node to act as head
	node_t *temp = *head;

	//List is empty, node added to head
	if(*head == NULL)
	{
		*head = *node;
		(*head)->next = NULL;
	}
	//List not empty, node added to end
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = *node;
	}
}

node_t* readNodeInfo(FILE* input)
{
	char tempMonth[20];
	char tempDay[20];
	char tempYear[20];

	//New node that will be added to list
	node_t* newNode = (node_t*)malloc(sizeof(node_t));

	//Read in data from file into the list using scansets
	fscanf(input, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
		newNode->lastName, newNode->firstName, tempMonth, tempDay,
		tempYear, newNode->song, newNode->pastime, newNode->chose);

	//Convert month # to integer
	newNode->bday.day = atoi(tempDay);
	newNode->bday.month = atoi(tempMonth);
	newNode->bday.year = atoi(tempYear);

	//Return the node to be added
	return newNode;
}

node_t* createList(FILE* fp, node_t** node)
{
	//Read from file until the end of it is reached
	while(!feof(fp))
	{
		node_t *tempNode = readNodeInfo(fp);

		//Adds the node if it contains data
		if(tempNode != NULL)
		{
			add(&tempNode, node);
		}
	}

	//Returns node to head in driver
	return *node;
}

void printList(FILE* fp, node_t* node)
{
	//List is empty, exit program
	if(node == NULL)
	{
		fprintf(stderr,"List is empty, exiting program\n");
		exit(0);
	}

	//Array to convert month integer to month string
	const char * months[13] = {" ", "January", "February", "March", 
				   "April", "May", "June", "July", 
				   "August", "September", "October", 
				   "November", "December"};

	//Print top border
	printBorder(fp);

	//Print start of info
	fprintf(fp, "\nList Info:\n");

	//Node that contains the data
	node_t *currNode = node;


	while (currNode != NULL)
	{
		//Print all of the data to file 2
		fprintf(fp,"Name: %s %s\nDate of Birth: %s %d, %d\n",
			currNode->firstName, currNode->lastName,
			months[currNode->bday.month], currNode->bday.day,
			currNode->bday.year);

		fprintf(fp, "Favorite Song: %s\n", currNode->song);

		fprintf(fp, "Favorite Pastime: %s\nWhy I Chose CS: %s\n\n", 
			currNode->pastime, currNode->chose);

		//Move to next node in the list
		currNode = currNode->next;
	}

	//Print bottom border
	printBorder(fp);
}

void printBorder(FILE* fp)
{
	//Prints 80 asterisks
	for (int i = 0; i < 80; i++)
	{
		fprintf(fp, "*");
	}
}

void deleteList(node_t** node)
{
	//Node to act as head
	node_t *temp = *node;
	
	//Loops until all of list is free
	while(*node)
	{
		//Traverses list and frees each part of it
		*node = (*node)->next;
		
		free(temp);

		temp = *node;
	}
}
