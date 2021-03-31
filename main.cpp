#ifdef _OPENMP
#include <omp.h> // for OpenMP library functions
#endif

#include <opencv2/opencv.hpp>
#include "LocalBinaryPattern.h"

using namespace cv;
using namespace std;

int main() {

    Mat inputImg = imread("../input/img.jpg", 0);
    imshow("Image before LBP", inputImg);
    Mat outputImg = localBinaryPattern(inputImg);
    imshow("Image after LBP", outputImg);
    waitKey(0);

    return 0;
}