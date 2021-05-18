//
// Created by marcolarino on 03/05/21.
//

#include <opencv2/opencv.hpp>
#include <chrono>
#include "execTimeTests.h"
#include "LocalBinaryPattern.h"


using namespace cv;
using namespace std;
using namespace std::chrono;

int* testWithIncreasingSize(int numTests, int N) {
    int *time =  (int*) malloc(sizeof(int) * numTests);
    String imgName = "img.jpg";
    Mat inputImg = imread("../input/" + imgName, 0);
    int rowBorder = inputImg.rows / 2;
    int colBorder = inputImg.cols / 2;

    for (int i = 0; i < numTests; i++) {
        //creating at each iteration a larger image (with double size)
        if(i != 0)
            copyMakeBorder(inputImg, inputImg, rowBorder, rowBorder, colBorder, colBorder, BORDER_CONSTANT, 0);

        // evaluating the mean time for each iteration
        int partialSum = 0;
        Mat imgOut;
        for (int j = 0; j < N; j++) {
            auto start = chrono::high_resolution_clock::now();
            imgOut = localBinaryPattern(inputImg, 4);
            auto end = chrono::high_resolution_clock::now();
            auto ms_int = duration_cast<chrono::milliseconds>(end - start);

            partialSum += ms_int.count();
        }

        time[i] = partialSum / N;
        cout << "iteration with a " << imgOut.cols << " X " << imgOut.rows << " image ended in " << time[i] << " milliseconds \n";
    }

    return time;
}

int* testWithIncreasingThreadsNum(int maxThreads, int N) {
    int *time = (int *) malloc(sizeof(int) * (maxThreads));
    String imgName = "img4k.jpg";
    Mat inputImg = imread("../input/" + imgName, 0);

    for (int t = 10; t <= maxThreads; t++) {
        // evaluating the mean time for each iteration
        int partialSum = 0;
        for (int i = 0; i < N; i++) {
            auto start = chrono::high_resolution_clock::now();
            localBinaryPattern(inputImg, t);
            auto end = chrono::high_resolution_clock::now();
            auto ms_int = duration_cast<chrono::milliseconds>(end - start);

            partialSum += ms_int.count();
        }

        time[t - 1] = partialSum / N;
        cout << "iteration with " << t << " threads ended in " << time[t - 1] << " milliseconds \n";
    }

    return time;
}

