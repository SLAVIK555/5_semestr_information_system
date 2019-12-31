#pragma once
#ifndef ALLOCATION_AND_SEND_H
#define ALLOCATION_AND_SEND_H

#include <string>
#include <vector>
#include <conio.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/face.hpp>
#include "opencv2/opencv.hpp"
//#include "drawLandmarks.hpp"


using namespace std;
using namespace cv;
using namespace cv::face;

class allocation_and_send {
	//Mat frame;
	//Mat img;
	//vector<string>allocated;
public:
	int allocattor(Mat frame, Ptr<Facemark> facemark, int faceid, int& countt);
	void drawer(Mat frame, std::vector<Rect> faces, int label, double confidence);
	int cropper(Mat image, Mat crop, std::vector<Rect> faces, int faceid, int& countt/*, vector<string>all, vector<Mat> img*/);
	//void name_sender(Mat image, vector<string> vec);
	//void img_sender(Mat image, vector<Mat> img);
	void landmarker(Mat img, std::vector<Rect> faces_g, Ptr<Facemark> facemark);
	//void displayer(const string name, Mat showimg);
	
};

#endif
