#include "UI.h"
#include "rlutil.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

/*
This function prints a welcome massage to the user
input: none
output: none
*/
void printWelcome(void)
{
	setColor(BLUE);
	puts("               .__                                  __                   .__  _____.____    .__               ");
		puts("__  _  __ ____ |  |   ____  ____   _____   ____   _/  |_  ____      ____ |__|/ ____\\    |   |__| ____   ____  ");
		puts("\\\\ \\/ \\/ // __ \\|  | _/ ___\\/  _ \\ /     \\_/ __ \\  \\   __\\/  _ \\    / ___\\|  \\   __\\|    |   |  |/  _ \\ /    \\ ");
		puts(" \\     /\\  ___/|  |_\\  \\__(  <_> )  Y Y  \\  ___/   |  | (  <_> )  / /_/  >  ||  |  |    |___|  (  <_> )   |  \\");
		puts("  \\/\\_/  \\___  >____/\\___  >____/|__|_|  /\\___  >  |__|  \\____/   \\___  /|__||__|  |_______ \\__|\\____/|___|  /");
		puts("             \\/          \\/            \\/     \\/                 /_____/                   \\/              \\/ ");
	resetColor();
}



/*
This function asks the user for a number of option and returns it
input: none
output: the option that the user order
*/
int getOptionFromMenu(void)
{
	printf("Enter option number: ");
	int userRequest = 0;
	scanf("%d", &userRequest);
	getchar();
	userRequest--;
	if ((size_t) userRequest < 0 || (size_t) userRequest > 7)
	{
		printError("Invalid order");
		userRequest = 0;
	}
	return userRequest ;
}

/*
This function returns if a given option number is valid
input: option number
output: if it valid
*/
char isNotValidOptionNumber(int optionNumber)
{
	return optionNumber < 1 && optionNumber > 6;
}

void printMenu(void)
{
	setColor(WHITE);
	puts("<1>\tExit");
	puts("<2>\tAppend new frame");
	puts("<3>\tRemove existing frame");
	puts("<4>\tReset time to a frame");
	puts("<5>\tReset time to all");
	puts("<6>\tChange frame possition");
	puts("<7>\tPlay");
	puts("<8>\tSave");
	resetColor();
}

/*
This function init the program UI
input: none
output: none
*/
void initUI(void)
{
	resetColor();
	setConsoleTitle("gifLion");
	printWelcome();
	setColor(WHITE);
	puts("<1>\topen an existing project");
	puts("<2>\tcreate a new project");
	resetColor();
}

/*
This function returns if to open an existing project or a new one
input: none
output: if to open an existing project or a new one
*/

int askUserForStatus(void)
{
	int userRequest = 0;
	scanf("%d", &userRequest);
	getchar();
	if (userRequest > 2 || userRequest < 1)
	{
		printError("Unvalid order\nType any thing to exit");
		_getch();
		exit(EXIT_FAILURE);
	}
	return userRequest - 1;
}

/*
This function prints errors
input: the error massege
output: none
*/
void printError(const char* massege)
{
	setColor(RED);
	fputs(massege, stderr);
	resetColor();
}

/*
This is magshimim well known myFgets
input: str, len of str
output: none
*/
void myFgets(char* buffer, size_t maxLen)
{
	fgets(buffer, maxLen, stdin);
	buffer[strlen(buffer) - 1] = 0;
}