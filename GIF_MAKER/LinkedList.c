#include "linkedList.h"


#define FIRST 1
#define FALSE 0
#define TRUE 1
#define MAX_LEN 255

/*
This function search for a frame with a given name inside a given list
input: the head of the list,
	   the name to search inside the list
output: the frame if exist else null
*/
FrameNode* getFreame(FrameNode* head, const char* name)
{
	if (head)
	{
		for (head; head->next; head = head->next)
		{
			if (!strcmp(head->frame->name, name))
			{
				return head;
			}
		}
		if (!strcmp(head->frame->name, name))
		{
			return head;
		}
	}
	return NULL;

}

/*
This function changes the douration in specific frame in the list
input: the head of the list,
	   the name of the frame
output: none
*/
void changeDourationSpecific(FrameNode* head, const char* name)
{
	size_t douration = 0;
	printf("Please enter frame duration (in miliseconds): ");
	scanf_s("%d", &douration);
	for (head; head->next; head = head->next)
	{
		if (!strcmp(head->frame->name, name))
		{
			head->frame->duration = douration;
			break;
		}
	}
	head->frame->duration = douration;
}

/*
This function changes the douration in all of the frames in the list
input: the head of list
output: none
*/
void changeDourationAll(FrameNode* head)
{
	size_t douration = 0;
	printf("Enter the duration for all frames (in miliseconds): ");
	scanf_s("%d", &douration);
	for (head; head->next; head = head->next)
	{
		head->frame->duration = douration;
	}
}
/*
This function copys frames info into another
input: destination, source
output: none
*/
void copyFrame(Frame* destination, Frame* source)
{
	destination->duration = source->duration;
	strcpy_s(destination->name, MAX_LEN, source->name);
	strcpy_s(destination->path, MAX_LEN, source->path);
}

/*
This function changes frame loction in the list
input: the list itself,
	   the name of the frame to change its loction,
	   its new index
output: the new list
*/
FrameNode* changeFrameIndex(FrameNode* head, const char* frameName, size_t newIndex)
{
	FrameNode* currFrameNode = head;
	FrameNode* temp = head;
	FrameNode* frameToMove = head;
	size_t index = 0;

	if (head)
	{
		// if the the frame is the first frame in the list -> get next
		if (!strcmp(frameName, head->frame->name) && head->next)
		{
			frameToMove = head;
			head = head->next;
		}
		// if there is only one frame in the list -> @return null
		else if (!strcmp(frameName, head->frame->name))
		{
			return NULL;
		}
		//get the frame
		while (currFrameNode->next && strcmp(currFrameNode->next->frame->name, frameName))
		{
			currFrameNode = currFrameNode->next;
		}
		frameToMove = currFrameNode->next;
		currFrameNode->next = frameToMove->next;

		// change curr frame
		currFrameNode = head;
		while (currFrameNode->next && index < newIndex)
		{
			index++;
			currFrameNode = currFrameNode->next;
		}
		// reast index
		temp = currFrameNode->next;
		currFrameNode->next = frameToMove;
		frameToMove->next = temp;
	}
	return head;
}

/*
This function removes frame from the list by its name
input: the list itself,
	   the name to search
output: the new head of the list
*/
FrameNode* removeFrame(FrameNode* head, const char* frameNameToRemove)
{
	FrameNode* currFrameNode = head;
	FrameNode* temp = head;

	if (head)
	{
		//if the remove frame is in the head -> return the next
		if (!strcmp(frameNameToRemove, head->frame->name) && head->next)
		{
			return head->next;
		}
		//if the list has only one item return NULL
		else if (!strcmp(frameNameToRemove, head->frame->name))
		{
			return NULL;
		}
		// search linearly for the node with that name
		while (currFrameNode->next && strcmp(currFrameNode->next->frame->name, frameNameToRemove))
		{
			currFrameNode = currFrameNode->next;
		}
		temp = currFrameNode->next;
		currFrameNode->next = temp->next;
		free(temp->frame);
		free(temp);
	}
	return head;
}

/*
This function creates a new frame
input: none
output: the frame that the function has created
*/
Frame* scanFrame(void)
{
	Frame* temp = (Frame*)malloc(sizeof(Frame));
	FILE* pFile = NULL;
	printf("Please enter frame path: ");
	temp->path = (char*)malloc(sizeof(char) * MAX_LEN);
	myFgets(temp->path, MAX_LEN - 1);
	printf("Please enter frame duration(in miliseconds): ");
	scanf_s("%d", &temp->duration);
	getchar();
	printf("Please enter a name for that frame: ");
	temp->name = (char*)malloc(sizeof(char) * MAX_LEN);
	myFgets(temp->name, MAX_LEN - 1);
	//if the file dosen't exist return NULL
	if (fopen_s(&pFile, temp->path, "r"))
	{
		return NULL;
	}
	return temp;
}

/*
This function creates a and returns it
input: the value of the node
output: the node
*/
FrameNode* createNode(Frame* frame)
{
	FrameNode* temp = (FrameNode*)malloc(sizeof(FrameNode));
	temp->frame = frame;
	temp->next = NULL;
	return temp;
}

/*
This function prints the list of the frames int the console
input: the list itself
output: none
*/
void printList(FrameNode* head)
{
	FrameNode* curr = head;
	puts("Name\tDuration\tPath");
	if (head && head->frame)
	{
		while (curr->next)
		{
			if (curr->frame)
			{
				printf("%s\t%d[ms]\t%s\n", curr->frame->name, curr->frame->duration, curr->frame->path);
				curr = curr->next;
			}
		}
		if (curr && curr->frame)
		{
			printf("%s\t%d[ms]\t%s\n", curr->frame->name, curr->frame->duration, curr->frame->path);
		}
	}
}


/*
This function scans and appends a new frame into the list
input: the list itself
output: the list with the new item
*/
FrameNode* addScanedFrame(FrameNode* list)
{
	Frame* newFrame = scanFrame();

	FrameNode* newFrameAddList = createNode(newFrame);
	FrameNode* head = list;

	if (list)
	{
		for (list; list->next; list = list->next);
		list->next = newFrameAddList;
	}
	else
	{
		head = newFrameAddList;
	}
	return head;
}

/*
This function appends frame into the list
input: the list, the new frame
output: the new list
*/
FrameNode* appendFrame(FrameNode* list, Frame* frame)
{
	FrameNode* newFrameAddList = createNode(frame);
	FrameNode* head = list;
	if (list)
	{
		for (list; list->next; list = list->next);
		list->next = newFrameAddList;
	}
	else
	{
		head = newFrameAddList;
	}
	getchar();
	return head;
}

void freeList(FrameNode* head)
{
	if (head)
	{
		while (head)
		{
			FrameNode* nextNode = head->next; // Store the next node before freeing current node
			if (head->frame)
			{
				free(head->frame->name);
				free(head->frame->path);
				free(head->frame);
			}
			free(head);
			head = nextNode; // Move to the next node
		}
	}
}
