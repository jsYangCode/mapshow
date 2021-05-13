/* By YJS
*  高精度地图制作过程文件，用于将投影生成的2D导航地图进行二值栅格化
*/

#include <opencv2/opencv.hpp>
#include "opencv2/core/core.hpp"
#include <opencv2/ml/ml.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <fstream>

using namespace std;
using namespace cv;

int main(int argc, char **argv)
{
    
    string targetImg, sourceImg;
    printf("please input source Img path :\n");
    getline(cin,sourceImg);
    printf("please input target Img path :\n");
    getline(cin,targetImg);

    cout<<"targetImg = "<<targetImg<<endl;
    cout<<"sourceImg = "<<sourceImg<<endl;

    Mat srcImg = cv::imread(sourceImg,0);//imread(picname);

    if (srcImg.empty())
    {
        cerr << "failed to open the file : " << sourceImg << endl;
        return -1;
    }

    printf("sourceRGB.channels() : %d\n", srcImg.channels());
    int key =29;

    for (int r = 0; r < srcImg.rows; r++)
    {
        uchar * pixelptr = srcImg.ptr<uchar>(r);

        for (int c = 0; c<srcImg.cols*srcImg.channels(); c++)
        {

            if(pixelptr[c]>key)
                //printf("%d ",pixelptr[c]);
                pixelptr[c] = 0;
             else
                 pixelptr[c] = 255;
            
        }
    }
    cout<<"img cols:"<<srcImg.cols<<endl<<
          "img rows:"<<srcImg.rows<<endl;
    imwrite(targetImg,srcImg);
    cout << "write to file ok!" << endl;
    return 0;
}




