// enc.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

#pragma warning(disable : 4996)

int main()

{
	int character = NULL; // character
	int seed = 1; // encodein seed valid range 1 to 26
	int mode = 0;  // 1 = encode, 0 = decode
	// int f = 0; // for decode indicatred found valid character, no additional processing required in the next test

	FILE *inFile;
	FILE *outFile;

	inFile = fopen("inFile.txt", "r");
	outFile = fopen("outFile.txt", "w");

	if (mode == 1)
	{
		while (true)
		{
			character = fgetc(inFile);
			if (character == EOF) { break; }
			character = character + seed;

			if (character > 127)
			{
				character = 0 + (character - 127);
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

			character = character - seed;
			if (character < 0)
			{
				character = character + 2 * character;
			}

			fputc(character, outFile);
		}
		return 0;
	}
}


