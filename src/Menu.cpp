#include<Menu.h>
#include<iostream>
#include<stdlib.h>
#include<SortAlgorithm.h>
#include<ListCell.h>
#include<WordList.h>
#include <Measurement.h>
#include <time.h>
#include <Text.h>

using namespace std;

//the menu point informations
void information(){
    char userChoice;
    Text::informationMenuText();

    cin >> userChoice;

    switch(userChoice){
    case 'a':
    case 'A':
        Text::algorithmInformation();
        cin >> userChoice;
        break;

    case 'f':
    case 'F':
        Text::fileInformation();
        cin >> userChoice;
        break;
    case 'm':
    case 'M':
        //add info about measurement methods

        cout << "Press any key and then ENTER to continue and return to Menu." << endl;
        cin >> userChoice;
        break;
    default:
        break;
    }
}

//the menu point help
void help(){
    char userChoice;
    Text::helpText();

    cin >> userChoice;

};

//execute a new Test
void newTest(string inputFileName){
    clock_t start;
    clock_t eend;
    double time_result;
    unsigned static int testNumber = 1; //counter for the number of tests
    //create unique file name for the output file
    string outputFileName = "outputTest";
    outputFileName.append(to_string(testNumber));
    outputFileName.append(inputFileName);

    //create a handle for the sort algorithm and import data
    SortAlgorithm algorithmHandle(inputFileName, outputFileName);
    algorithmHandle.importData();

    //let user choose between recursive and iterative algorithm
    char userChoice;
    Text::chooseAlgorithm(inputFileName);
    cin >> userChoice;
    switch(userChoice){
        case 'R':
        case 'r':
            cout << endl;
            cout << "Test number " << testNumber << endl;
            cout << "Sorting " << inputFileName << " recursively...";

            //execute recursive algorithm
            start = clock();
            algorithmHandle.recursiveSort(0, algorithmHandle.getPtrList()->listSize() - 1);
            eend = clock();
            time_result = time_exec(start, eend);
            break;
        case 'I':
        case 'i':
            cout << endl;
            cout << "Test number " << testNumber << endl;
            cout << "Sorting " << inputFileName << " iteratively...";

            //execute iterative algorithm
            start = clock();
            algorithmHandle.iterativeSort(0, algorithmHandle.getPtrList()->listSize() -1);
            eend = clock();
            time_result = time_exec(start, eend);
            break;
        default:
            break;

    }

    algorithmHandle.exportData(); //export data, store sorted list in output file
    Text::presentResults(inputFileName, outputFileName, testNumber, time_result);
    testNumber++; //count up the number of tests
}

//specify parameters for a new Test
void testMenu(){
    Text::testDescription();
    bool returnToMenu = false;
    char userChoice;
    string inputFileName;
    while(!returnToMenu){
        Text::testMenuSpecifyInputFile();
        cin >> userChoice;
        switch(userChoice){
        case 'S':
        case 's':
            inputFileName = "smallFile.txt";
            newTest(inputFileName);
            break;
        case 'M':
        case 'm':
            inputFileName = "mediumFile.txt";
            newTest(inputFileName);
            break;
        case 'L':
        case 'l':
            inputFileName = "largeFile.txt";
            newTest(inputFileName);
            break;
        default:
            break;
        }


    bool testOtherFile = false;
    while(!testOtherFile){
        Text::testMenuTestAnotherFile();
        cin >> userChoice;
        switch(userChoice){
            case 'S':
            case 's':
                newTest(inputFileName);
                break;
            case 'R':
            case 'r':
                testOtherFile = true;
                returnToMenu = true;
                break;
            case 'O':
            case 'o':
                testOtherFile = true;
                break;
            default:
                break;
        }
    }
}
};



