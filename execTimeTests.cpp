//
// Created by marcolarino on 03/05/21.
//

#include <opencv2/opencv.hpp>
#include <chrono>
#include "LocalBinaryPattern.h"

using namespace cv;
using namespace std;
using namespace std::chrono;


int main(int argc, char ** argv) {
    int numTests = 10;
    int *time =  (int*) malloc(sizeof(int) * numTests) ;
    String imgName = "img.jpg";
    Mat inputImg = imread("../input/" + imgName, 0);

    for (int i = 0; i < numTests; i++) {
        //creating at each iteration a larger image
        int borderSize = i * 1000;
        Mat workingImg;
        copyMakeBorder(inputImg, workingImg, borderSize, borderSize, borderSize, borderSize, BORDER_CONSTANT, 0);

        // evaluating the mean time for each iteration
        int N = 10;
        int partialSum = 0;
        for (int j = 0; j < N; j++) {
            auto start = chrono::high_resolution_clock::now();
            localBinaryPattern(workingImg);
            auto end = chrono::high_resolution_clock::now();
            auto ms_int = duration_cast<chrono::milliseconds>(end - start);

            partialSum += ms_int.count();
        }

        time[i] = partialSum / N;
        cout << "iteration " << i << " ended in " << time[i] << " milliseconds \n";
    }

    cout << "tests ended" << "\n";
    free(time);

    return 0;
}
