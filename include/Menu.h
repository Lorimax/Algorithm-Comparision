#ifndef MENU_H
#define MENU_H

#include<stdlib.h>
#include<string>
#include <windows.h>
#include <psapi.h>

using namespace std;

void basicMenuText();

void information();

void help();

void newTest(string inputFileName);

void testMenu();

void PrintMemoryInfo( DWORD processID );

#endif // MENU_H
