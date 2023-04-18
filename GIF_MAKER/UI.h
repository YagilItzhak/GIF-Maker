#pragma once
#ifndef UI
#define UI
#include <stdio.h>

int getOptionFromMenu(void);
void printWelcome(void);
void printMenu(void);
char isNotValidOptionNumber(int optionNumber);
void initUI(void);
int askUserForStatus(void);
void printError(const char* massege);
void myFgets(char* buffer, size_t maxLen);
#endif