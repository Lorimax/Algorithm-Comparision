#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <Menu.h>
#include<Text.h>


using namespace std;

int main()
{

cout << "TEST PROGRAM FOR RECURSIVE AND ITERATIVE ALGORITHMS" << endl;
cout << "===================================================" << endl;

bool exitProgram = false;

while(!exitProgram){
    char userChoice;

    Text::basicMenuText();

    cin >> userChoice;

    switch(userChoice){
    case 'T':
    case 't':
        testMenu();
        break;
    case 'I':
    case 'i':
        information();
        break;
    case 'H':
    case 'h':
        help();
        break;
    case 'E':
    case 'e':
        exitProgram = true;
        break;
    default:
        break;
    }



}




    return 0;
}
