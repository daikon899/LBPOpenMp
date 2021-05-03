#ifdef _OPENMP
#include <omp.h>
#endif

#include <opencv2/opencv.hpp>
#include "LocalBinaryPattern.h"

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
    //String imgName = argv[1];
    String imgName = "img.jpg";
    Mat inputImg = imread("../input/" + imgName, 0);
    //imshow("Image before LBP", inputImg);
    auto start = chrono::high_resolution_clock::now();
    Mat outputImg = localBinaryPattern(inputImg);
    auto end = chrono::high_resolution_clock::now();
    auto ms_int = chrono::duration_cast<chrono::milliseconds>(end - start);

    //imshow("Image after LBP", outputImg);
    //waitKey(0);

    return ms_int.count();
}