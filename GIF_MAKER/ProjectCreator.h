#pragma once

#ifndef PROJECT_CREATEOR
#define PROJECT_CREATEOR
#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FrameNode* readProject(const char* name);
FILE* createProject(const char* name);
void saveProject(FILE* project, FrameNode* head);
void closeProject(FILE* project);
#endif



