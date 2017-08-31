// enc.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

#pragma warning(disable : 4996)

#define LF 10
#define HT 9

int main(int argc, char *argv[])

{
	char character = NULL; // character
	int seed = 15; // encodein seed valid range 1 to 127
	int mode = 1; // 1 = encode, 0 = decode



	FILE *inFile;
	FILE *outFile;

	if (argc == 4) {
		switch (argv[1][0])
		{
			case 'e' : { mode = 1; break; }
			case 'd' : { mode = 0; break; }
			default: 
			{
				printf("Bad arguments.\n");
				printf("Usage: enc <e,d> <inFile> <outFile>\n");
				return 1; 
			}
		}
		inFile = fopen(argv[2], "r");
		outFile = fopen(argv[3], "w");
	}
	else if (argc > 4) {
		printf("Too many arguments supplied.\n");
		return 1;
	}
	else {
		printf("Not enough arguments.\n");
		printf("Usage: enc <e,d> <inFile> <outFile>\n");
		return 1;
	}

	if (mode == 1)
	{
		while (true)
		{
			character = fgetc(inFile);
			if (character == EOF) { break; }

			if (character == LF || character == HT) {
				character = character;
			}
			else {
				character = character + seed;
			}

			if (character > 126)
			{
				character = character - 126;
			}

			if (character == LF || character == HT) {
				character = character;
			}
			fputc(character, outFile);
		}

	}
	else
	{
		while (true)
		{
			character = fgetc(inFile);
			if (character == EOF) { break; }

			if (character == LF || character == HT) {
				character = character;
			}
			else {

				character = character - seed;
			}
			
			if (character < 0) {
				character = character + 2 * character;
			}

			if (character == LF || character == HT) {
				character = character;
			}
			fputc(character, outFile);
		}
		return 0;
	}
}


