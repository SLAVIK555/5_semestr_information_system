#include <opencv/cv.h>
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/opencv.hpp"
#include <iostream>
//#include "visitor.h"
#include "allocation_and_send.h"
//#include "identification.h"
#include <vector>

using namespace std;
using namespace cv;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
vector<string>allocated;
vector<string>allocated_g;
vector<string>landmarked;
vector<Mat>m_allocated;
vector<Mat>m_allocated_g;

//void allocattor(Mat frame, vector<string> allocated) {};


int main(void) {
	allocation_and_send A;//object of class "allocation_and_send"
						  // Read the image file
	Mat frame = imread("pic.jpg");
	// Apply the classifier to the frame
	if (!frame.empty()) {
		A.allocattor(frame, allocated, allocated_g, landmarked, m_allocated, m_allocated_g);
	}
	else {
		printf(" --(!) No captured frame -- Break!");
	}

	waitKey(0);

	system("pause");
	return 0;
}