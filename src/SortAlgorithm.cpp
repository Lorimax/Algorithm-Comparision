#include <SortAlgorithm.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string.h>
#include <stack>
#include <WordList.h>
#include <bits/stdc++.h>
#include <ListCell.h>
#include <list>

using namespace std;

//constructor
SortAlgorithm::SortAlgorithm(string _inputFileName, string _outputFileName){
    this->_inputFileName = _inputFileName; //assign the file names
    this->_outputFileName = _outputFileName;
    ptrList = nullptr; //no list specified
    //initialize the algorithms
    init();
}

//destructor
SortAlgorithm::~SortAlgorithm()
{
    if(_inputObject.is_open()) //check if input file is open
        _inputObject.close(); //close input file

    if(_outputObject.is_open()) //check if output file is open
        _outputObject.close(); //close output file

    delete ptrList;
}

WordList* SortAlgorithm::getPtrList(){
    return ptrList;
}

void SortAlgorithm::setPtrList(WordList* ptrList){
    this->ptrList = ptrList;
}


void SortAlgorithm::init(){
    if(!checkIfFileNamesSpecified())
        return;
    openInputFile();
    openOutputFile();
}

bool SortAlgorithm::checkIfFileNamesSpecified(){
    if(!_inputFileName.size()){ //check if input file name is specified
        writeNoInputFileErrorMessage();
        return false;
    }

    if(!_inputFileName.size()){ //check if output file name is specified
        writeNoOutputFileErrorMessage();
        return false;
    }
    return true;
}

void SortAlgorithm::writeNoInputFileErrorMessage(){
        cout << endl << "Init Error:" << endl;
        cout << "No input file specified." << endl;
}

void SortAlgorithm::writeNoOutputFileErrorMessage(){
        cout << endl << "Init Error:" << endl;
        cout << "No output file specified." << endl;
}

void SortAlgorithm::openInputFile(){
        if(!_inputObject.is_open())
            _inputObject.open(_inputFileName);
}

void SortAlgorithm::openOutputFile(){
    if(!_outputObject.is_open())
        _outputObject.open(_outputFileName, ios::out | ios::app);
}

//write data from input file in list
void SortAlgorithm::importData(){
    init();
    string line;
    ptrList = new WordList();
    while(getline(_inputObject, line)){ //import lines of text until file ends
        list<string> words = extractWords(line);
        this->addToWordsList(words, this->ptrList);
    }
    _inputObject.close();
}

list<string> SortAlgorithm::extractWords(string line){
    unsigned int currentPosition = 0;
    list<string> words;
    while(currentPosition != string::npos){
        string word = seperateWordBySpace(line, currentPosition);
        sortOutApostrophe(word);
        list<string> wordsToAdd = sortOutHyphen(word);
        words.insert(words.end(), wordsToAdd.begin(), wordsToAdd.end());
        }
    return words;
}

void SortAlgorithm::addToWordsList(list<string> wordsToAdd, WordList* ptrList){
    for(const auto& word : wordsToAdd){
        if(word != "")
            ptrList->addCell(word);
    }
}

string SortAlgorithm::seperateWordBySpace(string& line, unsigned int& currentPosition){
    currentPosition = line.find(' ');
    string word = line.substr(0, currentPosition);
    line = line.substr(currentPosition+1, line.size() - currentPosition);
    return word;
}

void SortAlgorithm::sortOutApostrophe(string& word){
    unsigned int currentWordPosition = word.find(39);
    word = word.substr(0, currentWordPosition);
}

list<string> SortAlgorithm::sortOutHyphen(string word){
    list<string> words;
    unsigned int currentWordPosition = 0;
    string wordResidual = word;
    while(currentWordPosition != string::npos){
        currentWordPosition = word.find('-');
        word = wordResidual.substr(0, currentWordPosition);
        wordResidual = wordResidual.substr(currentWordPosition+1, wordResidual.size() - currentWordPosition);
        words.insert(words.end(), word);
    }
    return words;
}

//write data in output file
void SortAlgorithm::exportData(){
    init();
    if(!(ptrList->isEmpty())){
        for(unsigned int index = 0; index < ptrList->listSize(); index++)
            _outputObject << (ptrList->getCell(index))->getWord() << "\n";
        _outputObject.close();
    }
}

void SortAlgorithm::recursiveSort( unsigned int firstIndex, unsigned int lastIndex){
    if(firstIndex < lastIndex){
        ListCell* pivotPtr = ptrList->getCell(lastIndex); //last element of the list is pivot element
        ListCell* cellPtr = nullptr;
        //sort by comparing to pivot element
        for(unsigned int i = firstIndex; i < pivotPtr->index; i++){
            cellPtr = ptrList->getCell(i);
            if( (cellPtr->compareCell(pivotPtr)) > 0){
                ptrList->moveTo(cellPtr, pivotPtr->index);
                i--;
            }
        }
    //recursively call the method on the sub-lists
    recursiveSort(pivotPtr->index + 1, lastIndex);
    recursiveSort(firstIndex, pivotPtr->index - 1);
    }
}

void SortAlgorithm::iterativeSort(unsigned int firstIndex, unsigned int lastIndex){
        stack<pair<unsigned int, unsigned int>> helpStack; //stack to store indices of sub lists

        //initialize with first and last index of list
        helpStack.push(make_pair(firstIndex, lastIndex));
        while(!helpStack.empty()){
            //define sub list
            firstIndex = helpStack.top().first;
            lastIndex = helpStack.top().second;
            helpStack.pop();
            ListCell* pivotPtr = ptrList->getCell(lastIndex); //last element of the list is pivot element
            sortSubList(firstIndex, lastIndex, pivotPtr);

            //store first and last index of upper half in stack
            if((pivotPtr->index - 1) > firstIndex)
                helpStack.push(make_pair(firstIndex, (pivotPtr->index) - 1));

            //store first and last index of lower half in stack
            if((pivotPtr->index + 1) < lastIndex)
                helpStack.push(make_pair((pivotPtr->index) + 1, lastIndex));
    }
}

void SortAlgorithm::sortSubList(unsigned int firstIndex, unsigned int lastIndex, ListCell* pivotPtr){
        ListCell* cellPtr = nullptr;
        for(unsigned int i = firstIndex; i < pivotPtr->index; i++){
            cellPtr = ptrList->getCell(i);
            if( (cellPtr->compareCell(pivotPtr)) > 0){
                ptrList->moveTo(cellPtr, pivotPtr->index);//maybe use pointer in the move to end function
                i--;
            }
        }
}

