#include "WordList.h"
#include <stdlib.h>
#include <string.h>
#include <ListCell.h>
#include <new>
#include <iostream>

using namespace std;

WordList::WordList()
{
    firstCell = nullptr; //list is empty, fist element is null
}

WordList::~WordList()
{
    //deallocate memory
    clearList();
}

bool WordList::isEmpty(){
    if(firstCell ==  nullptr)
        return true;
    return false;
}

//add a Cell at the end of the list
void WordList::addCell(string _word){
    ListCell* cellPointer = new ListCell(_word, nullptr); //the new cell
    if(isEmpty())
        firstCell = cellPointer; //if list is empty new cell is first element
    else{
        ListCell* lastElementPtr = getCell(listSize()-1);
        //add cell to the list
        lastElementPtr->setNext(cellPointer);
        cellPointer->index = (lastElementPtr->index) + 1;
    }
}

//delete elements in the list and deallocate memory
void WordList::clearList(){
    //two pointers  to go through the list
    ListCell* listPtrA = firstCell;
    ListCell* listPtrB;
    deleteElements(listPtrA, listPtrB);
    delete firstCell; //set pointer to first cell to 0;
    deleteLastElement(listPtrA);
}

void WordList::deleteElements(ListCell* listPtrA, ListCell* listPtrB){
    //go through the list and delete elements
    while(listPtrA->getNext()){
        listPtrB = listPtrA;
        listPtrA = listPtrA->getNext();
        listPtrB->setNext(nullptr);
        delete listPtrB;
    }
}

void WordList::deleteLastElement(ListCell* lastElementPtr){
        lastElementPtr->~ListCell();
        delete lastElementPtr;
}

//return number of elements in the list
unsigned int WordList::listSize(){
    if(isEmpty()) //check if list is empty
        return 0;
    ListCell* lastElementPtr = getLastCell();
    //return index+1 of last element which is the number of elements in the list
    return (lastElementPtr->index + 1);
}

ListCell* WordList::getLastCell(){
    ListCell* listPtr = firstCell;
    while(listPtr->getNext())
        listPtr = listPtr->getNext();
    return listPtr;
}

//return pointer to cell with index index
ListCell* WordList::getCell(unsigned int index){
    if(isEmpty()) //check if list is empty
        return nullptr;
    //go through the list and check if index match
    //because the list is a single linked list the listPtr always has to start with the first element
    ListCell* listPtr = firstCell;
    do{
        if(listPtr->index == index)
            return listPtr;
        listPtr = listPtr->getNext();
    }while(listPtr);

    writeElemtnNotFoundErrorMessage();
    return nullptr;
}

void WordList::writeElemtnNotFoundErrorMessage(){
    cout << endl << "Error in List::getCell():" << endl;
    cout << "No element with this index in the List!" << endl;
}

//move cell at position of pointer switchCellPtr to position index
void WordList::moveTo(ListCell* switchCellPtr, unsigned int index){
    if(firstCell == switchCellPtr){
        moveFirstElement(switchCellPtr, index);
    }
    else{
        moveElement(switchCellPtr, index);
    }
}

void WordList::moveFirstElement(ListCell* switchCellPtr, unsigned int index){
    firstCell = switchCellPtr->getNext(); //next cell of switch cell is new first cell
    switchCellPtr->setNext(getCell(index)->getNext()); //set next cell of index-cell as next cell of switch cell
    getCell(index)->setNext(switchCellPtr); //set next cell of index-cell to switch cell
    cleanUpIndexAfterFirstElementMoved(switchCellPtr, index);
}

void WordList::cleanUpIndexAfterFirstElementMoved(ListCell* switchCellPtr, unsigned int index){
    switchCellPtr->index = index;
    ListCell* cellPtr = firstCell;
    do{
        (cellPtr->index)--;
        cellPtr = cellPtr->getNext();
    }while(cellPtr != switchCellPtr);
}

void WordList::moveElement(ListCell* switchCellPtr, unsigned int index){
    ListCell* cellPtr = switchCellPtr->getNext();
    getCell(switchCellPtr->index - 1)->setNext(switchCellPtr->getNext()); //jump over switch cell by setting next cell
                                                                        //of previous cell to next cell of switch cell
    switchCellPtr->setNext(getCell(index)->getNext()); //set next cell of index-cell as next cell of switch cell
    getCell(index)->setNext(switchCellPtr); //set next cell of index-cell to switch cell
    switchCellPtr->index = index;
    cleanUpIndex(switchCellPtr, cellPtr);

}

void WordList::cleanUpIndex(ListCell* switchCellPtr, ListCell* cellPtr){
    while(cellPtr != switchCellPtr){
        (cellPtr->index)--;
        cellPtr = cellPtr->getNext();
    }
}
