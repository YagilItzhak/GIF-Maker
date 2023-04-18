#include <stdio.h>
#include "UI.h"
#include "LinkedList.h"
#include "View.h"
#include "ProjectCreator.h"
#include <conio.h>


#define MAX_INPUT 255

enum Option
{
	APPEND = 1,
	REMOVE,
	REPLACE,
	CHANGE_TIME,
	CHANGE_TIME_ALL,
	PLAY,
	SAVE

};


int main(void)
{
	FrameNode* top = (FrameNode*) malloc(sizeof(FrameNode));
	char* projectName[MAX_INPUT] = { 0 };
	FILE* project = NULL;
	int status = 0;
	char buffer[MAX_INPUT] = { 0 };
	initUI();
	status = askUserForStatus();
	printf("please enter the name of the project: ");
	myFgets(projectName, MAX_INPUT);
	if (status)
	{
		top = readProject(projectName);
	}
	project = createProject(projectName);
	printMenu();
	int userRequestForOption = getOptionFromMenu();
	while (userRequestForOption /*whie the user does not choose to exit*/)
	{
		switch (userRequestForOption)
		{
		case APPEND:
			//append item to the list
			top = addScanedFrame(top);
			break;
		case REMOVE:
			printf("please enter the name of the frame that you want to remove: ");
			myFgets(buffer, MAX_INPUT);
			top = removeFrame(top, buffer);
			break;
		case REPLACE:
			printf("please enter the name of the frame that you want to replace: ");
			myFgets(buffer, MAX_INPUT);
			printf("please enter its new index");
			scanf("%d", &userRequestForOption);
			top = changeFrameIndex(top, buffer, userRequestForOption);
			break;
		case CHANGE_TIME:
			printf("please eneter the name of the frame that you want to change its douration: ");
			myFgets(buffer, MAX_INPUT);
			changeDourationSpecific(top, buffer);
			break;
		case CHANGE_TIME_ALL:
			changeDourationAll(top);
			break;
		case PLAY:
			play(projectName, top);
			break;
		case SAVE:
			saveProject(project, top);
		default:
			// this is for conventions
			break;
		}
		
		printList(top);
		userRequestForOption = getOptionFromMenu();
	}
	freeList(top);
	puts("Type any key to exit");
	_getch();
	return 0;
}