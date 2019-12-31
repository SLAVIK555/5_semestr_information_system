#include <iostream>
#include <conio.h>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/face.hpp"

/*#include "highgui.hpp"
#include "imgproc.hpp"
#include "objdetect.hpp"
#include "face.hpp"*/
//#include "drawLandmarks.hpp"
#include "allocation_and_send.h"
#include "identification.h"
//
using namespace std;
using namespace cv;
using namespace cv::face;

//vector<string>allocated;
//vector<string>allocated_g;
//vector<string>landmarked;
//vector<Mat>m_allocated;
//vector<Mat>m_allocated_g;
//vector<Mat>m_landmarked;
Mat frame;
//Ptr<Facemark> facemark;

int faceid;
int countt=0;

int main(int argc, char** argv)
{
	cout << "enter user id" << endl;
	cin >> faceid;
	// Load Face Detector
	//CascadeClassifier faceDetector("haarcascade_frontalface_alt2.xml");
	// Create an instance of Facemark
	Ptr<Facemark> facemark = FacemarkLBF::create();
	// Load landmark detector
	facemark->loadModel("lbfmodel.yaml");
	// Set up webcam for video capture
	VideoCapture cam(0);
	// Variable to store a video frame and its grayscale 
	//Mat frame, gray;
	// Read a frame
	identification I;
	//I.trainer(faceid, countt);
	while (cam.read(frame))
	{
		allocation_and_send A;//object of class "allocation_and_send"
		A.allocattor(frame, facemark, faceid, countt);
		//identification I;
		//I.datasetter(frame, faceid, countt);
		//cout << "11" << endl;
		// Find face
		//vector<Rect> faces;
		// Convert frame to grayscale because
		// faceDetector requires grayscale image.
		//cvtColor(frame, gray, COLOR_BGR2GRAY);
		// Detect faces
		//faceDetector.detectMultiScale(gray, faces);
		// Variable for landmarks. 
		// Landmarks for one face is a vector of points
		// There can be more than one face in the image. Hence, we 
		// use a vector of vector of points. 
		//vector< vector<Point2f> > landmarks;
		// Run landmark detector
		//bool success = facemark->fit(frame, faces, landmarks);
		//if (success)
		//{
		// If successful, render the landmarks on the face
		//for (size_t i = 0; i < faces.size(); i++)
		//{
		//	cv::rectangle(frame, faces[i], Scalar(0, 255, 0), 3);
		//}
		//for (int i = 0; i < landmarks.size(); i++)
		//{
		//	drawLandmarks(frame, landmarks[i]);
		/*for (size_t j = 0; j < landmarks[i].size(); j++)
		circle(frame, Point(landmarks[i][j].x, landmarks[i][j].y), 1, Scalar(255, 0, 0), 2);*/
		//}
		//}
		// Display results 
		//imshow("Facial Landmark Detection", frame);
		// Exit loop if ESC is pressed
		if (waitKey(1) == 27) break;
	}
	//system("pause");
	return 0;
}
