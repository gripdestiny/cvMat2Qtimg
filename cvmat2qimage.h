#ifndef CVMAT2QIMAGE_H
#define CVMAT2QIMAGE_H
#include "QImage"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
class cvMat2Qimage
{
public:
    cvMat2Qimage();

    static QImage mat2image(const cv::Mat &image);

};

#endif // CVMAT2QIMAGE_H
