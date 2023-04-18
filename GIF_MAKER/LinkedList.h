#ifndef LINKEDLISTH
#define LINKEDLISTH
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "UI.h"
typedef struct Frame
{
	char* name;
	unsigned int duration;
	char* path;
} Frame;
typedef struct FrameNode
{
	Frame* frame;
	struct FrameNode* next;
} FrameNode;

void freeList(FrameNode* head);
FrameNode* getFreame(FrameNode* head, const char* name);
void changeDourationSpecific(FrameNode* head, const char* name);
void changeDourationAll(FrameNode* head);
Frame* scanFrame(void);
void printList(FrameNode* movie);
FrameNode* createNode(Frame* frame);
FrameNode* appendFrame(FrameNode* list, Frame* frame);
FrameNode* addScanedFrame(FrameNode* list);
FrameNode* removeFrame(FrameNode* movie, const char* frameNameToRemove);
FrameNode* changeFrameIndex(FrameNode* head, const char* frameName, size_t newIndex);
#endif