#ifndef TEXT_H
#define TEXT_H
#include <stdlib.h>
#include <string.h>
#include <iostream>

namespace Text{
    void basicMenuText();

    void helpText();

    void informationMenuText();

    void algorithmInformation();

    void fileInformation();

    void testDescription();

    void testMenuSpecifyInputFile();

    void testMenuTestAnotherFile();

    void chooseAlgorithm(std::string inputFileName);

    void presentResults(std::string inputFileName, std::string outputFileName, unsigned int testNumber, double time_result);

    void testIterativeAlgorithm(unsigned int testNumber, std::string inputFileName);

    void testRecursiveAlgorithm(unsigned int testNumber, std::string inputFileName);
}


#endif // TEXT_H
