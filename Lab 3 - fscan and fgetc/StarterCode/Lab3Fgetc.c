/*************************
 * Jacob Martin
 *
 * CPSC 2311 F22 Section 04
 *
 * jmart52@clemson.edu
 *
 **************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Lab3Fgetc.h"

void start(FILE* in)
{
	char c;

	//Read through file until end of it
	while ((c = fgetc(in)) != EOF)
	{
		//Detects comment, calls for removal
		if (c == '/')
		{
			rcomment(in);
		}
		else
		{
			//No comment, prints
			putchar(c);
		}
	}
}

void rcomment(FILE* in)
{
	char temp;

	// * sfter a / so must be multiline comment
	if ((temp = fgetc(in)) == '*')
	{
		skipM_comment(in);
	}
	//No star, must be single line comment
	else if (temp == '/')
	{
		skipS_comment(in);
	}
}

void skipM_comment(FILE* in)
{
	char mTemp1;
	char mTemp2;

	//Reads until end of comment or end of file
	while ((mTemp1 = fgetc(in)) != EOF)
	{
		//Possible end of comment
		if (mTemp1 == '*')
		{
			//Checks to make sure end of comment
			mTemp2 = fgetc(in);
			if (mTemp2 == '/')
			{
				//End of comment so return
				return;
			}
		}
	}
}

void skipS_comment(FILE* in)
{
	char sTemp;

	//Reads until end of comment or end of file
	while ((sTemp = fgetc(in)) != '\n' && sTemp != EOF)
		;
	printf("\n");
}
