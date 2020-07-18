#include <ListCell.h>
#include <stdlib.h>
#include <string>

using namespace std;

ListCell::ListCell(string _word, ListCell*_nextCell){
        this->_word = _word; //assign the word
        this->_nextCell = _nextCell; //assign the next cell
        extractWordToCompareFromWord();

    if(_wordToCompare == "")
        _wordToCompare = "zzzz";

    index = 0; //start with index 0
    }

void ListCell::extractWordToCompareFromWord(){
    _wordToCompare = _word;
    //here _wordToCompare is set to a string with only lowercase alphabetical letters
    for(register int letterIndex = 0; letterIndex<_wordToCompare.length(); letterIndex++){
        eraseNonAlphabeticalCharacters(letterIndex);
        turnUpperToLowerCase(letterIndex);
    }
}

void ListCell::eraseNonAlphabeticalCharacters(register int letterIndex){
    if((_wordToCompare.at(letterIndex) < 65) || (_wordToCompare.at(letterIndex) > 122) ||
    ((_wordToCompare.at(letterIndex) > 90) && (_wordToCompare.at(letterIndex) < 97))){
        _wordToCompare.erase(_wordToCompare.begin()+letterIndex);
        letterIndex--;
    }
}

void ListCell::turnUpperToLowerCase(register int letterIndex){
    if((_wordToCompare.at(letterIndex) >= 65) && (_wordToCompare.at(letterIndex) <= 90))
        _wordToCompare.at(letterIndex) += 32;
}

ListCell::~ListCell(){}

string ListCell::getWord(){
    return _word;
}

string ListCell::getWordToCompare(){
    return _wordToCompare;
}

//return the pointer to the next cell in the list
ListCell* ListCell::getNext(){
    if(!(this->_nextCell))
        return nullptr;

    return this->_nextCell;
}

//set the pointer to the next cell in the list
void ListCell::setNext(ListCell* _nextCell){
    if(!_nextCell)
        this->_nextCell = nullptr;
    else
        this->_nextCell = _nextCell;
}

//compare the cell to another cell
//returns >0 if the cell is alphabetically lower, meaning closer to z, than the cell
//it is compared to
//returns <0 if the cell is alphabetically higher
//returns 0 if they are equal
int ListCell::compareCell(ListCell* cellToCompare){
    return _wordToCompare.compare(cellToCompare->getWordToCompare());
}
