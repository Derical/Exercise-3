#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
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
	Mat src = cv::imread("C:\\Users\\STAR ZHANG\\Pictures\\5.jpg", IMREAD_GRAYSCALE);
	Mat dst;
	
	//大津法二值化
	//threshold(src,dst,100,255,THRESH_BINARY);

	//区域自适应二值化
	adaptiveThreshold(src,dst,255,ADAPTIVE_THRESH_GAUSSIAN_C,THRESH_BINARY_INV,15,10);

	cv::imshow("src",src);
	cv::imshow("dst", dst);
	waitKey(0);
	return 0;
}