#include <opencv2\opencv.hpp>
#include <math.h>

using namespace std;
using namespace cv;

int main() {
	
	Mat srcImg = imread("../../data/images/capsicum.jpg");
	imshow("srcimage", srcImg);

	//飽和係數:越大過飽和，越小去飽和
	float saturationScale = 100;

	Mat hsvImg;

	cvtColor(srcImg, hsvImg, COLOR_BGR2HSV);

	hsvImg.convertTo(hsvImg, CV_32F);
	
	vector<Mat>channels;
	//切割成3個channel
	split(hsvImg, channels);

	channels[1] = channels[1] * saturationScale;

	//將範圍控制在0~255之間
	min(channels[1], 255, channels[1]);
	max(channels[1], 0, channels[1]);

	merge(channels, hsvImg);

	hsvImg.convertTo(hsvImg, CV_8UC3);
	
	Mat deSatImg;
	cvtColor(hsvImg, deSatImg, COLOR_HSV2BGR);
	imshow("desaturated Image", deSatImg);

	waitKey(0);
	return 0;
}