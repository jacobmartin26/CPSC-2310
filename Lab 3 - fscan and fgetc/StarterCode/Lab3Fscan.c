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
#include "Lab3Fscan.h"

void start(FILE* in)
{
	char c;

	//Reads until end of file
	while (fscanf(in, "%c", &c) != EOF)
	{
		//Detects comment start, calls for removal
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

	//Scans next character
	fscanf(in, "%c", &temp);

	//Must be multiline comment
	if (temp == '*')
	{
		skipM_comment(in);
	}
	//Must be single line comment
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
	while (fscanf(in, "%c", &mTemp1) != EOF)
	{
		//Possible end of comment
		if (mTemp1 == '*')
		{
			//Read further to make sure
			fscanf(in, "%c", &mTemp2);
			if (mTemp2 == '/')
			{
				//End of comment, return
				return;
			}
		}
	}
}

void skipS_comment(FILE* in)
{
	char sTemp;

	//Read until end of comment or end of file
	while (fscanf(in, "%c", &sTemp) != EOF && sTemp != '\n')
		;
	printf("\n");
}
