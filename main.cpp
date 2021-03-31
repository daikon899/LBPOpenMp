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
    double start = omp_get_wtime();
    Mat outputImg = localBinaryPattern(inputImg);
    double end = omp_get_wtime();
    double time = end - start;
    cout << time <<"\n";
    imshow("Image after LBP", outputImg);
    waitKey(0);

    return 0;
}