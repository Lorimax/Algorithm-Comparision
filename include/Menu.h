#ifndef MENU_H
#define MENU_H

#include<stdlib.h>
#include<string>
#include <windows.h>
#include <psapi.h>
#include <SortAlgorithm.h>

namespace Menu{

void basicMenuText();

void information();

void help();

void testMenu();

void PrintMemoryInfo( DWORD processID );

}

#endif // MENU_H
