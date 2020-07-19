#ifndef LISTCELL_H
#define LISTCELL_H

#include<stdlib.h>
#include <string>

using namespace std;

class ListCell
{
private:
    string _wordToCompare; //the word in only lower case alphabetical letters for easier comparison
    string _word; //the word is saved in this variable
    ListCell *_nextCell; //pointer to the next list Cell

public:
    unsigned int index; //index to access the cell

    ListCell(string word, ListCell *nextCell);
    ~ListCell();

    string getWord();

    string getWordToCompare();

    ListCell* getNext();

    void setNext(ListCell* nextCell);

    //returns 0 if strings are equal
    //returns <0 if this cell is alphabetically higher (closer to A)
    //returns >0 if this cell is alphabetically lower
    int compareCell(ListCell* cellToCompare);

private:

    void turnUpperToLowerCase(register int letterIndex);

    void extractWordToCompareFromWord();

};

#endif // LISTCELL_H
