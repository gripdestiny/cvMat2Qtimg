#include "cvmat2qimage.h"
#include "QDebug"
QImage cvMat2Qimage::mat2image(const cv::Mat &image)
{
    if(image.type()==CV_8UC1)
    {
        QImage qImg(image.cols,image.rows,QImage::Format_Indexed8);
        qImg.setColorCount(256);
        for(int i=0;i<256;i++)
        {
            qImg.setColor(i,qRgb(i,i,i));
        }
        uchar *pSrc=image.data;
        for(int row=0;row<image.rows;row++)
        {
            uchar *pDest=qImg.scanLine(row);
            memcpy(pDest,pSrc,image.cols);
            pSrc+=image.step;
        }
        return qImg;
    }
    else if(image.type()==CV_8UC3)
    {
        const uchar *pSrc=(const uchar*)image.data;
        QImage qImg(pSrc,image.cols,image.rows,image.step,QImage::Format_RGB888);
        return qImg.rgbSwapped();
    }
    else {
        qDebug()<<"Error:: The cv Mat cannot be converted to QImage";
        return QImage();
    }
}
