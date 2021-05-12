#include <iostream>
#include <string>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>

using namespace cv;
using namespace std;

///打开图片
/*int main(void)
{
    string path="/Users/lev1s/Desktop/图像.jpeg";
    Mat img=imread(path);
    imshow("WOW", img);
    waitKey(0);
}
*/

///打开视频文件
/*int main()
{
    string path="......";
    VideoCapture cap(path);
    Mat img;
    
    while(true)
    {
        cap.read(img);
        imshow("...",img);
        waitKey(20);//延迟,单位为毫秒
    }
}
*/

///捕获摄像头
/*int main()
{
    VideoCapture cam(0);
    Mat img;
    
    while (true)
    {
        cam.read(img);
        imshow("WOW",img);
        waitKey(1);
    }
}
*/
