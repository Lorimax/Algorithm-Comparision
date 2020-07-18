#include <Text.h>
#include<iostream>
#include<stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

namespace Text{

    void basicMenuText(){
        using namespace std;
        cout << endl;
        cout << endl;
        cout << "Menu" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << endl;
        cout << "Start new Test: T" << endl;
        cout << endl;
        cout << "More Information: I" << endl;
        cout << endl;
        cout << "Help: H" << endl;
        cout << endl;
        cout << "Exit Program: E" << endl;
        cout << endl;
    }

    void helpText(){
        using namespace std;
            cout << endl;
            cout << endl;
            cout << "With this Program it is possible to compare an iterative algorithm to a recursive one." << endl;
            cout << "The algorithms used are an iterative and a recursive version of QuickSort that sort the words" << endl;
            cout << "of texts in ASCII format alphabetically and stores the sorted words in a specified output file." << endl;
            cout << endl;
            cout << "The program gets its input data, meaning the words to sort, from pre-made input files." << endl;
            cout << "The input files are the files smallFile.txt, mediumFile.txt and largeFile.txt which should be" << endl;
            cout << "stored in the same location as the main.cpp file!" << endl;
            cout << "The user can choose between those files in the Test set-up menu." << endl;
            cout << endl;
            cout << "More detailed information about the used algorithms and the input files can be found under 'More information'." << endl;
            cout << endl;
            cout << "The output files are created and named automatically and can be found in the same location as the" << endl;
            cout << "same location as the input files" << endl;
            cout << endl;
            cout << "Press any key and then ENTER to continue and return to Menu." << endl;
    }


    void informationMenuText(){
        using namespace std;
            cout << endl;
            cout << endl;
            cout << "Learn about the used algorithms: A" << endl;
            cout << endl;
            cout << "Learn about the files: F" << endl;
            cout << endl;
            cout << "Learn about the methods of measurement: M" << endl;
            cout << endl;
    }

    void algorithmInformation(){
        using namespace std;
        cout << endl;
        cout << endl;
        cout << "With this Program it is possible to compare an iterative algorithm to a recursive one." << endl;
        cout << "The algorithms used are an iterative and a recursive version of QuickSort that sort the words" << endl;
        cout << "of texts in ASCII format alphabetically and store the sorted words in an output file." << endl;
        cout << endl;
        cout << "The program takes input from .txt files with text in ASCII format. It filters out " << endl;
        cout << "all the words by searching for spaces or '-'. The words are then internally stored in a single" << endl;
        cout << "linked list. Every word gets assigned an index and a 'cleaned up' version of itself, which is" << endl;
        cout << "the word in all lower case letters, without any numbers or non-alphabetic characters that still" << endl;
        cout << "might be in the word. This cleaned-up version is what is used to compare the words alphabetically." << endl;
        cout << endl;
        cout << "The recursive QuickSort algorithm is a pretty standard QuickSort which always takes the last element" << endl;
        cout << "of the list or sub-list as pivot element. This would cause worst-case behaviour with already sorted lists " << endl;
        cout << "but makes it possible to use a simplified method to move elements in the list because an element can only" << endl;
        cout << "either stay at is position or be moved to the very end of the list. Since texts are only very rarely already" << endl;
        cout << "sorted alphabetically the probability of the worst-case behaviour to actually occur is sufficiently low to " << endl;
        cout << "justify the use of the last element as pivot element." << endl;
        cout << "Like any other recursive algorithm this QuickSort algorithm calls itself over and over thus using space on the" << endl;
        cout << "stack until the list is sorted. This limits is ability to be applied to very large texts." << endl;
        cout << endl;
        cout << "The iterative QuickSort algorithm also uses the last element of the list or sub-list as pivot element." << endl;
        cout << "It uses a stack of pairs of unsigned integer numbers to store the start and end indices of the list and all" << endl;
        cout << "the sub-lists, that yet have to be sorted. The algorithm sorts until the stack is empty meaning until no more" << endl;
        cout << "sub-lists have to be sorted." << endl;
        cout << "Press any key and then ENTER to continue and return to Menu." << endl;
    }

    void fileInformation(){
        using namespace std;
        cout << endl;
        cout << endl;
        cout << "All files are simple .txt files that contain only texts of standard ASCII characters. The files should be stored" << endl;
        cout << "in the same location as the main.cpp file of the program." << endl;
        cout << endl;
        cout << "smallFile.txt" << endl;
        cout << "Size: 20,435 bytes" << endl;
        cout << "Number of words: 3,509" << endl;
        cout << endl;
        cout << "mediumFile.txt" << endl;
        cout << "Size: 44,985 bytes" << endl;
        cout << "Number of words: 7,793" << endl;
        cout << endl;
        cout << "largeFile.txt" << endl;
        cout << "Size: 67,547 bytes" << endl;
        cout << "Number of words: 11,642" << endl;
        cout << endl;
        cout << "Press any key and then ENTER to continue and return to Menu." << endl;
    }

    void testDescription(){
        using namespace std;
        cout << endl;
        cout << endl;
        cout << "With this Program it is possible to compare an iterative algorithm to a recursive one." << endl;
        cout << "The algorithms used are an iterative and a recursive version of QuickSort that sort the words" << endl;
        cout << "of texts in ASCII format alphabetically and stores the sorted words in a specified output file." << endl;
    }

    void testMenuSpecifyInputFile(){
        using namespace std;
        cout << endl;
        cout << "Please specify input file" << endl;
        cout << endl;
        cout << "small input file: S" << endl;
        cout << "medium input file: M" << endl;
        cout << "large input file: L" << endl;
    }

    void testMenuTestAnotherFile(){
        using namespace std;
        cout << endl;
        cout << "Test the same file again: S" << endl;
        cout << "Test another file: O" << endl;
        cout << "Return to Menu: R" << endl;
    }

    void chooseAlgorithm(std::string inputFileName){
        using namespace std;
        cout << endl;
        cout << inputFileName << " selected." << endl;
        cout << endl;
        cout << "Recursive algorithm: R" << endl;
        cout << "Iterative algorithm: I" << endl;
    }

    void presentResults(std::string inputFileName, std::string outputFileName, unsigned int testNumber, double time_result){
        using namespace std;
        cout << endl;
        cout << inputFileName << " sorted." << endl;
        cout << "The sorted text can be found in " << outputFileName << endl;
        cout << endl;
        cout << endl;
        cout << "Test number " << testNumber << " results" << endl;
        cout << "----------------------------------------------" << endl;
        cout << "Execution time: " << time_result << " seconds" << endl;
        cout << endl;
    }
}
