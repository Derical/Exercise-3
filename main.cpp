#include <opencv2/opencv.hpp>
#include <iostream>
#include <opencv2\imgproc\types_c.h>
#include <string.h>
using namespace cv;
using namespace std;

void threshold_Mat(int th, void* data)
{
	Mat src = *(Mat*)(data);
	Mat dst;
	threshold(src, dst, th, 255, 0);
	imshow("threshold", dst);
}

int main()
{
	// ------------------------- Exercise 1 -------------------------
	//VideoCapture cap(0);

	//double scale = 0.5;

	////0 - 180
	////肤色
	//double i_minH = 0;
	//double i_maxH = 20;
	////0 - 255
	//double i_minS = 43;
	//double i_maxS = 255;
	////0 - 255
	//double i_minV = 55;
	//double i_maxV = 255;

	//while (1)
	//{
	//	Mat frame;
	//	Mat hsvMat;
	//	Mat detectMat;

	//	cap >> frame;
	//	Size ResImgSiz = Size(frame.cols * scale, frame.rows * scale); 
	//	Mat rFrame = Mat(ResImgSiz,frame.type());
	//	resize(frame, rFrame, ResImgSiz, INTER_LINEAR);

	//	cvtColor(rFrame,hsvMat,COLOR_BGR2HSV);

	//	rFrame.copyTo(detectMat);

	//	cv::inRange(hsvMat, Scalar(i_minH, i_minS, i_minV), Scalar(i_maxH, i_maxS, i_maxV),detectMat);

	//	imshow("whie: in the range",detectMat);
	//	imshow("frame", rFrame); 
	//	
	//	waitKey(30);

	//}


	// ------------------------- Exercise 2 -------------------------

	//读取图片并转换为单通道灰度
	//Mat src = cv::imread("C:\\Users\\STAR ZHANG\\Pictures\\5.jpg", IMREAD_GRAYSCALE);
	//Mat dst;
	//
	////大津法二值化
	////threshold(src,dst,100,255,THRESH_BINARY);

	////区域自适应二值化
	//adaptiveThreshold(src,dst,255,ADAPTIVE_THRESH_GAUSSIAN_C,THRESH_BINARY_INV,15,10);

	//cv::imshow("src",src);
	//cv::imshow("dst", dst);
	//waitKey(0);

	// ------------------------- Exercise 3 -------------------------

	Mat src, gray;
	int ValueSlider = 100;
	int maxTh = 255;

	src = imread("C:\\Users\\STAR ZHANG\\Pictures\\5.jpg");

	if (!src.data)
	{
		cout << "图像载入失败！" << endl;
		return 0;
	}
	cvtColor(src, gray,CV_BGR2GRAY);

	////显示原图
	//imshow("src",src);
	////显示灰度图
	//imshow("gray", gray);

	//创建窗口
	//参数为自动调整大小
	namedWindow("threshold",WINDOW_GUI_NORMAL);
	//创建滑动条
	char Trackername[50];
	sprintf_s(Trackername,"二值化阈值 %d",ValueSlider);
	createTrackbar(Trackername, "threshold", &ValueSlider, maxTh, threshold_Mat, &gray);
	waitKey(0);

	return 0;
}