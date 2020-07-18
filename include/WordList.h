#ifndef WORDLIST_H
#define WORDLIST_H

#include <stdlib.h>
#include <string.h>
#include <ListCell.h>
#include <iostream>

using namespace std;

class WordList
{
private:
    ListCell* firstCell;

public:

    WordList();
    ~WordList();

    void addCell(string _word); //adds to the end of the list

    unsigned int listSize(); //returns number of cells

    bool isEmpty(); //check if the list is empty
                    // this is faster than checking if listSize() is 0

    void clearList(); //delete all entries in the list

    ListCell* getCell(unsigned int index); //return a pointer to cell with index index

    void moveTo(ListCell* switchCellPtr , unsigned int index);

private:
    void moveFirstElement(ListCell* switchCellPtr, unsigned int index);

    void cleanUpIndexAfterFirstElementMoved(ListCell* switchCellPtr, unsigned int index);

    void moveElement(ListCell* switchCellPtr, unsigned int index);

    void cleanUpIndex(ListCell* switchCellPtr, ListCell* cellPtr);

    void writeElemtnNotFoundErrorMessage();

    ListCell* getLastCell();

    void deleteElements(ListCell* listPtrA, ListCell* listPtrB);

    void deleteLastElement(ListCell* lastElementPtr);

};

#endif // LIST_H
