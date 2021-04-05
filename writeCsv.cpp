#include "writeCsv.h"
#include <iostream>
#include <fstream>

using namespace std;

void writeCsv(int* histogram){
    ofstream fileIterations("../output/histogram.csv", ifstream::out);
    for (int i = 0; i < 256; i++ ){
        fileIterations << histogram[i] << "\n";
    }
    fileIterations.close();
}