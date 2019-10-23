#ifndef ALLOCATION_AND_SEND_H
#define ALLOCATION_AND_SEND_H

#include <string>
#include <vector>
#include <conio.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/opencv.hpp"
//#include <opencv2/face.hpp>
//#include "drawLandmarks.hpp"

using namespace std;
using namespace cv;
//using namespace cv::face;

class allocation_and_send {
	Mat frame;
	//Mat img;
	//vector<string>allocated;
public:
	void allocattor(Mat frame, vector<string>allocated, vector<string>allocated_g, vector<string>landmarked, vector<Mat>m_allocated, vector<Mat>m_allocated_g);
	void drawer(Mat frame, std::vector<Rect> faces);
	void cropper(Mat image, Mat crop, std::vector<Rect> faces, vector<string>all, vector<Mat> img);
	void name_sender(Mat image, vector<string> vec);
	void img_sender(Mat image, vector<Mat> img);
	void landmarker(Mat frame, std::vector<Rect> faces_g, vector<string>allocated_g, vector<string>landmarked, vector<Mat>m_allocated, vector<Mat>m_allocated_g);
};

#endif
#pragma once
