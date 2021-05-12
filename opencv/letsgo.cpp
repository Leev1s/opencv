#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/core/core.hpp>
using namespace cv;
using namespace std;
/*int main(void)//基本图像处理函数
{
    string path="/Users/lev1s/Desktop/图像.jpeg";
    Mat img=imread(path);
    Mat imgGray,imgBlur,imgCanny,imgDil,imgErode;
    //cvtColor(img, imgGray, COLOR_BGR2GRAY);
    GaussianBlur(imgGray, imgBlur, Size(5,5),3,3);//高斯模糊
    
    Canny(imgBlur, imgCanny, 25, 75);//边缘检测
    
    Mat kernal=getStructuringElement(MORPH_RECT, Size(3,3));//定义增大单元大小
    dilate(imgCanny, imgDil, kernal);//增大
    erode(imgDil, imgErode, kernal);//缩小以达到图像连续
    
    //imshow("img", img);
    //imshow("imgGray", imgGray);
    //imshow("imgBlur", imgBlur);
    //imshow("imgCanny",imgCanny);
    //imshow("imgDil",imgDil);
    imshow("imgErode",imgErode);
    waitKey(0);
}
*/


/*int main(void)//图像缩放与裁剪
{
    string path="/Users/lev1s/Desktop/图像.jpeg";
    Mat img=imread(path);
    Mat imgResize,imgCrop;
    
    resize(img, imgResize, Size(),0.3,0.3);//resize
    
    Rect roi(200,800,300,300);//裁剪的位置以及大小
    imgCrop=img(roi);//裁剪操作
    
    imshow("img", img);
    imshow("imgResize", imgResize);
    imshow("imgCrop",imgCrop);
    waitKey(0);
}
*/


/*int main(void)//绘制形状与打印文本
{
    //Blank Image
    Mat img(512,512,CV_8UC3,Scalar(255,255,255));//创建一个☝️图像，Scalar指定了图像颜色
    
    circle(img, Point(256,256), 155, Scalar(0,0,0),FILLED);//画一个圆，Point指定了圆心，155指定了半径,最后一个参数决定厚度,最后一个参数为FILLED则为一个实心圆
    rectangle(img, Point(130,226), Point(382,286), Scalar(255,255,255),FILLED);
    line(img, Point(130,296), Point(382,296), Scalar(255,255,255),2);
    
    putText(img, "WOW", Point(137,267), FONT_HERSHEY_SCRIPT_COMPLEX, 1, Scalar(0,69,255),2);//创建文字
    imshow("img", img);
    waitKey(0);
}
*/


/*int main(void)//图像扭曲变换（文档识别）
{
    float w=250,h=350;
    Mat matrix,imgWarp;
    
    string path="/Users/lev1s/Desktop/图像.jpeg";
    Mat img=imread(path);
    
    Point2f src[4]={{529,142},{771,190},{405,395},{674,457}};//选取图像中需要转换的区域（矩形）
    Point2f dst[4]={{0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h}};//定义图像原始大小
    
    matrix=getPerspectiveTransform(src, dst);//系数矩阵
    warpPerspective(img, imgWarp, matrix, Point(w,h));//进行视角变换
    
    for(int i=0;i<4;i++)
    {circle(img, src[i], 10, Scalar(0,0,255),2);}//在选取的四个点上画出圆圈
    
    imshow("WOW", img);
    imshow("WOWOW",imgWarp);
    waitKey(0);
}
*/



/*int main(void)//Color Detection
{
    Mat imgHSV,mask;
    int hmin=0,smin=0,vmin=0;//定义初始值
    int hmax=179,smax=255,vmax=255;//定义初始值
    string path="/Users/lev1s/Desktop/2.jpeg";
    Mat img=imread(path);
    
    cvtColor(img, imgHSV, COLOR_BGR2HSV);//转换色彩空间
    
    namedWindow("Trackbars");//参数调整窗口
    createTrackbar("Hue Min", "Trackbars", &hmin, 179);
    createTrackbar("Hue Max", "Trackbars", &hmax, 179);
    createTrackbar("Sat Min", "Trackbars", &smin, 255);
    createTrackbar("Sat Max", "Trackbars", &smax, 255);
    createTrackbar("Val Min", "Trackbars", &vmin, 255);
    createTrackbar("Val Max", "Trackbars", &vmax, 255);
    //使用trackbar必须添加循环
    while(true){
    Scalar lower(hmin,smin,vmin);
    Scalar upper(hmax,smax,vmax);
    inRange(imgHSV, lower, upper, mask);//添加遮罩
        printf("%d %d %d %d %d %d\n",hmin,hmax,smin,smax,vmin,vmax);
    imshow("img", img);
    //imshow("imgHSV", imgHSV);
    imshow("mask",mask);
    waitKey(1);
    }
}
*/


//#########################轮廓识别#############################
/*int main(void)//调用图片
{
    Mat imgGray,imgBlur,imgCanny,imgDil;
    void getContours(Mat,Mat);
    
    string path="/Users/lev1s/Desktop/2.jpg";
    Mat img=imread(path);
    //图像预处理
    cvtColor(img, imgGray, COLOR_BGR2GRAY);
    GaussianBlur(imgGray, imgBlur, Size(7,7),5,5);//高斯模糊
    Canny(imgBlur, imgCanny, 25, 75);//边缘检测
    Mat kernal=getStructuringElement(MORPH_RECT, Size(3,3));//定义增大单元大小
    dilate(imgCanny, imgDil, kernal);//增大
    
    getContours(imgDil,img);//调用过滤器
    
    imshow("img", img);
    waitKey(0);
}
*/


/*int main()//调用摄像头
{
    Mat imgGray,imgBlur,imgCanny,imgDil;
    void getContours(Mat,Mat);
    VideoCapture cam(0);
    Mat img;
    
    while (true)
    {
        cam.read(img);
        //图像预处理
        cvtColor(img, imgGray, COLOR_BGR2GRAY);
        GaussianBlur(imgGray, imgBlur, Size(7,7),5,5);//高斯模糊
        Canny(imgBlur, imgCanny, 25, 75);//边缘检测
        Mat kernal=getStructuringElement(MORPH_RECT, Size(3,3));//定义增大单元大小
        dilate(imgCanny, imgDil, kernal);//增大
        
        getContours(imgDil,img);//调用过滤器
        
        imshow("img",img);
        waitKey(1);
    }
}
*/




/*void getContours(Mat imgDil,Mat img)//扫描轮廓
{
    vector<vector<Point>>contours;
    vector<Vec4i>hierarchy;
    
    findContours(imgDil,contours,hierarchy,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE);//寻找轮廓
    //drawContours(img, contours, -1, Scalar(255,0,255),2);//如果在这一步绘制那么将绘制全部轮廓
    
    //过滤器
    for(int i=0;i<contours.size();i++)//遍历所有轮廓
    {
        int area=contourArea(contours[i]);
        cout<<area<<endl;//打印所有轮廓的面积
        
        vector<vector<Point>>conPoly(contours.size());
        vector<Rect>boundRect(contours.size());
        string objectType;
        
        if(area>1500)//面积过滤器
        {
            float peri=arcLength(contours[i], true);
            approxPolyDP(contours[i], conPoly[i], 0.04*peri, true);//把一个连续光滑曲线折线化
            
            printf("++++++++++");
            cout<<conPoly[i].size()<<endl;//打印端点个数
            boundRect[i]=boundingRect(conPoly[i]);//得到包覆此轮廓的最小正矩形
            
            int objCor=(int)conPoly[i].size();
            if(objCor==3){objectType="Tri";}
            if(objCor==4)
            {
                float aspRatio=(float)boundRect[i].width/(float)boundRect[i].height;
                cout<<aspRatio<<endl;
                if(aspRatio>0.95&&aspRatio<1.05){objectType="Square";}
                else{objectType="Rect";}
            }
            if(objCor>4){objectType="Circle";}
            drawContours(img, conPoly, i, Scalar(255,0,255),1.5);
            rectangle(img,boundRect[i].tl(), boundRect[i].br(), Scalar(0,255,0),2);//绘制包覆此轮廓的最小正矩形
            putText(img, objectType, {boundRect[i].x,boundRect[i].y+boundRect[i].height}, FONT_HERSHEY_SIMPLEX, 1, Scalar(0,69,255),2);//创建文字
 
            
        }
    }

}
*/



//###########################人脸检测##############################
/*int main(void)
{
    string path="/Users/lev1s/Desktop/图像.jpeg";
    Mat img=imread(path);
    
    CascadeClassifier faceCascade;
    faceCascade.load("/Users/lev1s/Desktop/opencv-4.5.2/data/haarcascades/haarcascade_frontalface_default.xml");
    
    if(faceCascade.empty()){cout<<"XML file not loaded"<<endl;}//检测XMl是否加载
    
    vector<Rect> faces;
    faceCascade.detectMultiScale(img, faces,1.2,3);
    
    for(int i=0;i<faces.size();i++)//遍历面容
    {
        rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255,0,255),2);//绘制矩形
    }
    
    imshow("img", img);
    waitKey(0);
}
*/


//#######################虚拟画家#########################
//{hmin,hmax,smin,smax,vmin,vmax}
/*vector<vector<int>>myColor{{34,82,70,255,41,255},//green
                           {101,109,141,255,50,255}//blue
    };//视频中的颜色
vector<Scalar>myColorValues{{0,255,0},//green
                            {255,0,0}//blue
    };//想要绘制的颜色

Mat img;
vector<vector<int>>newPoints;

int main()
{
    vector<vector<int>> findColor(Mat);
    void draw(vector<vector<int>>,vector<Scalar>);
    VideoCapture cam(1);

    while (true)
    {
        cam.read(img);
        
        newPoints=findColor(img);//调用函数
        draw(newPoints,myColorValues);
        
        imshow("img",img);
        waitKey(1);
    }
}

//#################################################################
vector<vector<int>> findColor(Mat img)//查找对应颜色
{
    Mat imgHSV,mask;
    Point getContours(Mat);
    cvtColor(img, imgHSV, COLOR_BGR2HSV);//转换色彩空间
    for(int i=0;i<myColor.size();i++)
    {
        Mat mask;
        Scalar lower(myColor[i][0],myColor[i][2],myColor[i][4]);
        Scalar upper(myColor[i][1],myColor[i][3],myColor[i][5]);
        inRange(imgHSV, lower, upper, mask);//添加遮罩
        //imshow(to_string(i),mask);
        Point myPoint = getContours(mask);
        if(myPoint.x!=0&&myPoint.y!=0)
        {
            newPoints.push_back({myPoint.x,myPoint.y,i});
            
        }
        
    }
    return newPoints;
}

//###################################################################
void draw(vector<vector<int>>newPoints,vector<Scalar>myColorValues)//绘制图形
{
    for(int i=0;i<newPoints.size();i++)
    {
        circle(img,Point(newPoints[i][0],newPoints[i][1]), 30,myColorValues[newPoints[i][2]],FILLED);
    }
}

//####################################################################
Point getContours(Mat mask)//扫描轮廓
{
    vector<vector<Point>>contours;
    vector<Vec4i>hierarchy;
    
    findContours(mask,contours,hierarchy,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE);//寻找轮廓
    //drawContours(img, contours, -1, Scalar(255,0,255),2);//如果在这一步绘制那么将绘制全部轮廓
    
    //过滤器
    
    vector<vector<Point>>conPoly(contours.size());
    //vector<Rect>boundRect(contours.size());
    Point myPoint;
    
    for(int i=0;i<contours.size();i++)//遍历所有轮廓
    {
        int area=contourArea(contours[i]);
        cout<<area<<endl;//打印所有轮廓的面积
        
        //string objectType
        
        if(area>2000)//面积过滤器
        {
            float peri=arcLength(contours[i], true);
            approxPolyDP(contours[i], conPoly[i], 0.02*peri, true);//把一个连续光滑曲线折线化
            
            printf("++++++++++");
            cout<<conPoly[i].size()<<endl;//打印端点个数
            //boundRect[i] = boundingRect(conPoly[i]);//得到包覆此轮廓的最小正矩形
            RotatedRect rRect = minAreaRect(conPoly[i]);
            //rectangle(img,boundRect[i].tl(), boundRect[i].br(), Scalar(0,255,0),2);//绘制包覆此轮廓的最小正矩形
            //myPoint.x=rRect.center.x;myPoint.y=rRect.center.y;
            Point2f vertices[4];
                rRect.points(vertices);
                for (int i = 0; i < 4; i++)
                    line(img, vertices[i], vertices[(i + 1) % 4], Scalar(0, 255, 0), 2);//绘制最小面积旋转矩形
            drawContours(img, conPoly, i, Scalar(255,0,255),3);
            myPoint.x=(vertices[1].x+vertices[2].x)/2;
            myPoint.y=(vertices[1].y+vertices[2].y)/2;
            
        }
    }
    return(myPoint);
}
*/

//###################################文档处理########################################
/*Mat imgOriginal,imgGray,imgCanny,imgThre,imgBlur,imgErode,imgDil,imgWarp,imgCrop;
vector<Point>initialPoints,docPoints;
float w=420,h=596;
int cropVal=3;
int CannyMin=25;
int CannyMax=75;
Mat preProcessing(Mat img)
{
    cvtColor(img, imgGray, COLOR_BGR2GRAY);
    GaussianBlur(imgGray, imgBlur, Size(3,3),1,1);//高斯模糊
    Canny(imgBlur, imgCanny, CannyMin, CannyMax);//边缘检测
    
    Mat kernal=getStructuringElement(MORPH_RECT, Size(3,3));//定义增大单元大小
    dilate(imgCanny, imgDil, kernal);//增大
    //erode(imgDil, imgErode, kernal);//缩小以达到图像连续
    return imgDil;
}

vector<Point> getContours(Mat img)//扫描轮廓
{
    int maxArea=0;
    vector<vector<Point>>contours;
    vector<Vec4i>hierarchy;
    findContours(img,contours,hierarchy,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE);//寻找轮廓
    vector<vector<Point>>conPoly(contours.size());//这一行应放在contours有内容之后
    vector<Point>m;
    //过滤器
    for(int i=0;i<contours.size();i++)//遍历所有轮廓
    {
        int area=contourArea(contours[i]);
        cout<<area<<endl;//打印所有轮廓的面积
        if(area>2000)//面积过滤器
        {
            float peri=arcLength(contours[i], true);
            approxPolyDP(contours[i], conPoly[i], 0.02*peri, true);//把一个连续光滑曲线折线化
            if(area>maxArea && conPoly[i].size()==4)
            {
                drawContours(imgOriginal, conPoly, i, Scalar(255,0,255),3);
                m={conPoly[i][0],conPoly[i][1],conPoly[i][2],conPoly[i][3]};
                maxArea=area;
            }
            //drawContours(imgOriginal, conPoly, i, Scalar(255,0,255),3);
            //rectangle(imgOriginal,boundRect[i].tl(), boundRect[i].br(), Scalar(0,255,0),2);//绘制包覆此轮廓的最小正矩形
        }
    }
    return m;
}

void drawPoints(vector<Point>points,Scalar color)
{
    for(int i=0;i<points.size();i++)
    {
        circle(imgOriginal, points[i], 3, color,FILLED);
        putText(imgOriginal, to_string(i), points[i], FONT_HERSHEY_PLAIN, 2 , color,2);
    }
}

vector<Point> reorder(vector<Point>points)
{
    vector<Point>newPoints;
    vector<int>sumPoints,subPoints;
    for(int i=0;i<4;i++)
    {
        sumPoints.push_back(points[i].x+points[i].y);
        subPoints.push_back(points[i].x-points[i].y);
    }
    newPoints.push_back(points[min_element(sumPoints.begin(),sumPoints.end())-sumPoints.begin()]);
    newPoints.push_back(points[max_element(subPoints.begin(),subPoints.end())-subPoints.begin()]);
    newPoints.push_back(points[min_element(subPoints.begin(),subPoints.end())-subPoints.begin()]);
    newPoints.push_back(points[max_element(sumPoints.begin(),sumPoints.end())-sumPoints.begin()]);
    return newPoints;
}

Mat getWarp(Mat img,vector<Point>points,float w,float h)
{
    Point2f src[4]={points[0],points[1],points[2],points[3]};//选取图像中需要转换的区域（矩形）
    Point2f dst[4]={{0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h}};//定义图像原始大小
    
    Mat matrix=getPerspectiveTransform(src, dst);//系数矩阵
    warpPerspective(img, imgWarp, matrix, Point(w,h));//进行视角变换
    return imgWarp;
}
*/
/*int main(void)
{
    string path="/Users/lev1s/Desktop/3.jpeg";
    imgOriginal=imread(path);
    //resize(imgOriginal, imgOriginal,Size(),0.5,0.5);//缩小图片
    //图像预处理
    do
    {
        imgThre=preProcessing(imgOriginal);
        initialPoints=getContours(imgThre);//轮廓识别
        CannyMin=CannyMin-5;
        if(CannyMin==0){CannyMin=5;}
        CannyMax=CannyMax+75;
    }
    while(initialPoints.size()==0);
    
    //drawPoints(initialPoints, Scalar(0,0,255));
    docPoints=reorder(initialPoints);
    drawPoints(docPoints, Scalar(0,255,0));
    
    imgWarp=getWarp(imgOriginal,docPoints,w,h);//扭曲
    
    Rect roi(cropVal,cropVal,w-(2*cropVal),h-(2*cropVal));//裁切
    imgCrop=imgWarp(roi);
    
    imshow("imgOriginal", imgOriginal);
    imshow("imgDil", imgThre);
    imshow("imgWarp", imgWarp);
    imshow("imgCrop", imgCrop);
    waitKey(0);
}
*/

/*int main(void)
{
    VideoCapture cam(1);
    namedWindow("Trackbars");//参数调整窗口
    resizeWindow("Trackbars", 200, 50);
    createTrackbar("Min", "Trackbars", &CannyMin, 200);
    createTrackbar("Max", "Trackbars", &CannyMax, 500);
    while (true)
    {
        cam.read(imgOriginal);
        imgThre=preProcessing(imgOriginal);
        initialPoints=getContours(imgThre);//轮廓识别
        //drawPoints(initialPoints, Scalar(0,0,255));
        if(initialPoints.size()!=0)
        {
            docPoints=reorder(initialPoints);
            //drawPoints(docPoints, Scalar(0,255,0));
        
            imgWarp=getWarp(imgOriginal,docPoints,w,h);//扭曲
        
            Rect roi(cropVal,cropVal,w-(2*cropVal),h-(2*cropVal));//裁切
            imgCrop=imgWarp(roi);
            //imshow("imgWarp", imgWarp);
            imshow("imgCrop", imgCrop);
        }
        imshow("imgOriginal", imgOriginal);
        imshow("imgDil", imgThre);
        waitKey(1);
    }
}
*/

/*int main()
{
    // 【1】读入一张图片
    Mat srcImage = imread("/Users/lev1s/Desktop/000.jpg");
    resize(srcImage, srcImage,Size(),0.1,0.1);//缩小图片
    cvtColor(srcImage, srcImage, COLOR_BGR2GRAY);
    int rowNumber = srcImage.rows;    //行数
    int colNumber = srcImage.cols*srcImage.channels();   //列数*通道数=每一行元素的个数
    for(int i = 0; i < rowNumber; i++)  //行循环，可根据需要换成rowNumber
    {
        uchar* data = srcImage.ptr<uchar>(i);  //获取第i行的首地址
        for(int j = 0; j < colNumber; j++)  //列循环，同理
        {
            int intensity = data[j];
            cout << intensity << " " ;
        }
        cout << endl;
    }
 
    //cvtColor(srcImage,dstImage,CV_BGR2GRAY);
    // 【2】在窗口中显示载入的图片
    //imshow("效果图",dstImage);
    // 【3】等待按任意键窗口自动关闭
    waitKey();
 
    return 0;
}*/

int main()
{
    string path="/Users/lev1s/Desktop/badapple.mp4";
    VideoCapture cap(path);
    Mat img;
    int t=0;
    char imgTxt[76][202];
    while(true)
    {
        t=0;
        cap.read(img);
        resize(img, img,Size(),0.07,0.07);//缩小图片
        cvtColor(img, img, COLOR_BGR2GRAY);
        for(int i = 0; i < 76; i++)  //行循环，可根据需要换成rowNumber
        {
            uchar* data = img.ptr<uchar>(i);  //获取第i行的首地址
            for(int j = 0; j < 101; j++)  //列循环，同理
            {
                int intensity = data[j];
                if(intensity==0)
                {imgTxt[i][2*j]='#';
                imgTxt[i][2*j-1]='#';}
                else if(intensity>0&&intensity<=15)
                {imgTxt[i][2*j]='$';
                 imgTxt[i][2*j-1]='$';}
                else if(intensity>15&&intensity<=30)
                {imgTxt[i][2*j]='@';
                 imgTxt[i][2*j-1]='@';}
                else if(intensity>30&&intensity<=70)
                {imgTxt[i][2*j]='*';
                 imgTxt[i][2*j-1]='*';}
                else if(intensity>70&&intensity<=120)
                {imgTxt[i][2*j]='!';
                 imgTxt[i][2*j-1]='!';}
                else if(intensity>100&&intensity<=130)
                {imgTxt[i][2*j]=';';
                 imgTxt[i][2*j-1]=';';}
                else if(intensity>130&&intensity<=160)
                {imgTxt[i][2*j]='~';
                 imgTxt[i][2*j-1]='~';}
                else if(intensity>160&&intensity<=190)
                {imgTxt[i][2*j]=',';
                 imgTxt[i][2*j-1]=',';}
                else if(intensity>190&&intensity<=220)
                {imgTxt[i][2*j]='.';
                 imgTxt[i][2*j-1]='.';}
                else
                {imgTxt[i][2*j]=' ';
                 imgTxt[i][2*j-1]=' ';}
                //cout << intensity << " " ;
            }
            //cout << endl;
        }
        for(int i=0;i<76;i++)
        {
            for(int j=0;j<202;j++)
            {
                printf("%c",imgTxt[i][j]);
                t++;
                if(t%202==0)
                {
                    printf("\n");
                }
            }
        }
        imshow("...",img);
        waitKey(33.3);//延迟,单位为毫秒
    }
}
