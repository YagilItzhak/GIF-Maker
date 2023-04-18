#include "ProjectCreator.h"



#define MAX_LEN 255


/*
This function creates project and returns it
input: the name of the project
output: the project itself
*/
FILE* createProject(const char* name)
{
	return fopen(name, "w");
}

/*
This function saves a project
input: the project value,
	   a linked list that contains the value to save inside the project
output: none
*/
void saveProject(FILE* project, FrameNode* head)
{
	if (project && head)
	{
		char buffer[MAX_LEN] = { 0 };
		for (head; head; head = head->next)
		{
			if (head->frame)
			{
				//fprintf(project, "%255s,%255s,%u\n", head->frame->name, head->frame->path, head->frame->duration);
				fputs(head->frame->name, project);
				fputs("\n", project);
				fputs(head->frame->path, project);
				fputs("\n", project);
				_itoa(head->frame->duration, buffer, 10);
				fputs(buffer, project);
			}
		}
	}
}

/*
This function read project info and returns it as a linked list
input: the name of the project
output: a linked list that contains the the info of the project if project exist else null
*/

FrameNode* readProject(const char* name)
{
	FrameNode* head = NULL;
	Frame* buffer = NULL;
	char durationBuffer[MAX_LEN] = { 0 };
	char flag = 1;
	FILE* project = fopen(name, "r");
	do
	{
		buffer = (Frame*)malloc(sizeof(Frame));
		buffer->name = (char*)malloc(MAX_LEN);
		buffer->path = (char*)malloc(MAX_LEN);
		fgets(buffer->name, MAX_LEN, project);
		fgets(buffer->path, MAX_LEN, project);
		fgets(durationBuffer, MAX_LEN, project);
		buffer->duration = atoi(durationBuffer);
		if (buffer->name && buffer->path && durationBuffer)
		{
			flag = 0;
		}
		else
		{
			head = appendFrame(head, buffer);
		}
	} while (flag);
	return head;
}

/*
This function closes a project
input: project to close
output: none
*/
void closeProject(FILE* project)
{
	fclose(project);
}