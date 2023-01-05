/**************************
 * Jacob Martin
 * CPSC 2310 Fall 22
 * UserName: jmart52
 * Instructor: Dr. Yvon Feaster 
*************************/

#include "functions.h"

int main(int argc, char* argv[])
{
    //Check appropriate # of arguments passed
    assert(argc == 3);

    //Input and Output file pointers
    FILE* fp1 = fopen(argv[1], "r");
    FILE* fp2 = fopen(argv[2], "w");

    //Check that files opened correctly
    assert(fp1 != NULL);
    assert(fp2 != NULL);

    //Node to act as head of list malloc'd
    node_t* temp = (node_t*)malloc(sizeof(node_t));

    temp = NULL;
    
    //Node passed to function with file 1
    temp = createList(fp1, &temp);

    //Print list into file 2
    printList(fp2, temp);

    //Deletes list
    deleteList(&temp);

    //Close both files
    fclose(fp1);
    fclose(fp2);
}
