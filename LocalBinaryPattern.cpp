#include "LocalBinaryPattern.h"

#ifdef _OPENMP

#include <omp.h>

#endif

Mat localBinaryPattern(Mat &imgIn) {
    int weights[8] = {1, 2, 4, 8, 16, 32, 64, 128};
    Mat imgOut = Mat::zeros(imgIn.rows, imgIn.cols, CV_8UC1);

    copyMakeBorder(imgIn, imgIn, 1, 1, 1, 1, BORDER_CONSTANT, 0);

    int tid, nThreads;
    tid = -1;

    #ifdef _OPENMP
    std::cout << "_OPENMP defined" << std::endl;
    std::cout << "Num processors (Phys+HT): " << omp_get_num_procs() << std::endl;
    omp_set_num_threads(128);
    #endif

    #pragma omp parallel default(none) shared(imgIn, weights, imgOut) private(tid, nThreads)
    {
        #pragma omp for collapse(2) schedule(static)
        for (int i = 1; i < imgIn.rows - 1; i++) {
            for (int j = 1; j < imgIn.cols - 1; j++) {
                int neighbors[8];
                neighbors[0] = imgIn.at<uchar>(i - 1, j - 1);
                neighbors[1] = imgIn.at<uchar>(i - 1, j);
                neighbors[2] = imgIn.at<uchar>(i - 1, j + 1);
                neighbors[3] = imgIn.at<uchar>(i, j + 1);
                neighbors[4] = imgIn.at<uchar>(i + 1, j + 1);
                neighbors[5] = imgIn.at<uchar>(i + 1, j);
                neighbors[6] = imgIn.at<uchar>(i + 1, j - 1);
                neighbors[7] = imgIn.at<uchar>(i, j - 1);

                int oldVal = imgIn.at<uchar>(i, j);

                int newVal = 0;
                for (int k = 0; k < 8; k++) {
                    if (neighbors[k] >= oldVal)
                        newVal += weights[k];
                }
                imgOut.at<uchar>(i - 1, j - 1) = newVal;
            }
        }

    }

    return imgOut;
}