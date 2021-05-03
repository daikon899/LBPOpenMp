#include <iostream>
#include <fstream>
#include <filesystem>
#include "writeCsv.h"

using namespace std;

void writeCsv(int* histogram){
    if (!filesystem::is_directory("../output") || !filesystem::exists("../output"))
        filesystem::create_directory("../output");
    ofstream fileIterations("../output/histogram.csv", ifstream::out);
    for (int i = 0; i < 256; i++ ){
        fileIterations << histogram[i] << "\n";
    }
    fileIterations.close();
}
