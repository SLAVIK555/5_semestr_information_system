#pragma once
#ifndef IDENTIFICATION_H
#define IDENTIFICATION_H

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

class identification {

public:
	int identificator(Mat frame, vector< vector<Point2f> > landmarks, int i);
	int datasetter(Mat crop, int faceid, int& countt);
	int trainer(int faceid, int& countt);
	int predictor(Mat image, std::vector<Rect> faces);
};

#endif
