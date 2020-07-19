#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "Measurement.h"

using namespace std;

double elapsedTime(clock_t startTime,clock_t endTime){
    return ((double)endTime - startTime)/CLOCKS_PER_SEC;
}

