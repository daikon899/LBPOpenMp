//
// Created by marcolarino on 04/05/21.
//

#include <iostream>
#include "execTimeTests.h"
#include "writeCsv.h"

using namespace std;

int main(int argc, char ** argv) {
    int numIterations = 40;
    int N = 50;
    int numThreads = 64;

    cout << "Testing time increasing image size \n";
    int *timeWrtSize = testWithIncreasingSize(numIterations, N);
    writeTestResults(timeWrtSize, numIterations, "size");
    cout << "--------------------------------------------------- \n";

    cout << "Testing time increasing the number of threads \n";
    int *timeWrtThreadNum = testWithIncreasingThreadsNum(numThreads, N);
    writeTestResults(timeWrtThreadNum, numThreads, "thread_num");

    return 0;
}