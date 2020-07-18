#ifndef SORTALGORITHM_H
#define SORTALGORITHM_H

#include <stdlib.h>
#include <cstddef>
#include <fstream>
#include <string>
#include <WordList.h>
#include <list>

using namespace std;

class SortAlgorithm
{
private:
        ifstream _inputObject;
        ofstream _outputObject;

        string _inputFileName;
        string _outputFileName;

        WordList* ptrList;

public:

        WordList* getPtrList();
        void setPtrList(WordList* ptrList);

        SortAlgorithm(string _inputFileName, string _outputFileName);
        SortAlgorithm();
        virtual ~SortAlgorithm();

        int getInputFileSize();

        void changeInputFile(string newName);
        void changeOutputFile(string newName);

        void init();

        void importData();
        void exportData();

        void recursiveSort(unsigned int firstIndex, unsigned int lastIndex);

        void iterativeSort(unsigned int firstIndex, unsigned int lastIndex);

    private:
        bool checkIfFileNamesSpecified();

        void writeNoInputFileErrorMessage();

        void writeNoOutputFileErrorMessage();

        void openInputFile();

        void openOutputFile();

        void addToWordsList(list<string> wordsToAdd, WordList* ptrList);

        string findWordBySpace(string line, unsigned int currentPosition);

        void sortOutApostrophe(string word);

        list<string> sortOutHyphen(string word);

        list<string> extractWords(string line);

        void sortSubList(unsigned int firstIndex, unsigned int lastIndex, ListCell* pivotPtr);
};

#endif // SORTALGORITHM_H
