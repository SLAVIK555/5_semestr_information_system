#define _CRT_SECURE_NO_WARNINGS
#include <sstream>
#include <iostream>
#include <conio.h>
#include "opencv2/opencv.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include "allocation_and_send.h"
//#include <opencv2/face.hpp>
//#include "drawLandmarks.hpp"


using namespace std;
using namespace cv;
//using namespace cv::face;

void allocation_and_send::allocattor(Mat frame, vector<string> allocated, vector<string>allocated_g, vector<string>landmarked, vector<Mat>m_allocated, vector<Mat>m_allocated_g)
{
	Mat crop;
	Mat gray;

	// Load Face cascade (.xml file)
	CascadeClassifier faceDetector("haarcascade_frontalface_alt2.xml");

	// Detect faces
	std::vector<Rect> faces;
	std::vector<Rect> faces_g;
	faceDetector.detectMultiScale(frame, faces);

	// Convert frame to grayscale because
	// faceDetector requires grayscale image.
	cvtColor(frame, gray, COLOR_BGR2GRAY);
	// Detect faces for faceDetector
	faceDetector.detectMultiScale(gray, faces_g);

	//Calling methoods
	drawer(frame, faces);
	cropper(frame, crop, faces, allocated, m_allocated);
	cropper(gray, crop, faces_g, allocated_g, m_allocated_g);
	landmarker(frame, faces_g, allocated_g, landmarked, m_allocated, m_allocated_g);
}

void allocation_and_send::drawer(Mat frame, std::vector<Rect> faces)
{
	// Draw rectangle on the detected faces
	Mat drawres = frame;
	for (int i = 0; i < faces.size(); i++)//size_t i = 0
	{
		rectangle(drawres, faces[i], Scalar(0, 255, 0), 3);
	}
}

void allocation_and_send::cropper(Mat image, Mat crop, std::vector<Rect> faces, vector<string> all, vector<Mat> img)
{
	// Set Region of Interest
	cv::Rect roi_b;
	cv::Rect roi_c;

	size_t ic = 0; // ic is index of current element
	int ac = 0; // ac is area of current element

	size_t ib = 0; // ib is index of biggest element
	int ab = 0; // ab is area of biggest element

	for (ic = 0; ic < faces.size(); ic++) // Iterate through all current elements (detected faces)

	{
		roi_c.x = faces[ic].x;
		roi_c.y = faces[ic].y;
		roi_c.width = (faces[ic].width);
		roi_c.height = (faces[ic].height);

		ac = roi_c.width * roi_c.height; // Get the area of current element (detected face)

		roi_b.x = faces[ib].x;
		roi_b.y = faces[ib].y;
		roi_b.width = (faces[ib].width);
		roi_b.height = (faces[ib].height);

		ab = roi_b.width * roi_b.height; // Get the area of biggest element, at beginning it is same as "current" element

		if (ac > ab)
		{
			ib = ic;
			roi_b.x = faces[ib].x;
			roi_b.y = faces[ib].y;
			roi_b.width = (faces[ib].width);
			roi_b.height = (faces[ib].height);
		}

		crop = image(roi_b);

		name_sender(crop, all);
		img_sender(crop, img);//img-vector
		//sender(crop, all, img);

	}
}

void allocation_and_send::name_sender(Mat image, vector<string> vec)
{
	string filename;
	int filenumber = 0;

	// Form a filename
	filename = "";
	stringstream ssfn;
	ssfn << filenumber << ".jpg";
	filename = ssfn.str();
	filenumber++;

	//imwrite(filename, image);//inwrite image
	vec.push_back(filename);//add to base of name of files
}

void allocation_and_send::img_sender(Mat image, vector<Mat> img)
{
	img.push_back(image);//add to base of picture
}

/**
void allocation_and_send::sender(Mat image, vector<string> vec, vector<Mat> img)
{
	string filename;
	int filenumber = 0;

	// Form a filename
	filename = "";
	stringstream ssfn;
	ssfn << filenumber << ".jpg";
	filename = ssfn.str();
	filenumber++;

	imwrite(filename, image);//inwrite image
	vec.push_back(filename);//add to base of name of files
	//img.push_back(image);//add to base of picture
}*/

void allocation_and_send::landmarker(Mat frame, std::vector<Rect> faces_g, vector<string> allocated_g, vector<string> landmarked, vector<Mat>m_allocated, vector<Mat>m_allocated_g)
{
	// Create an instance of Facemark
	Ptr<Facemark> facemark = FacemarkLBF::create();
	// Load landmark detector
	facemark->loadModel("lbfmodel.yaml");
	// Create local copy of image
	Mat img;
	for (int it = 0; it<m_allocated_g.size(); it++) {
		img = m_allocated_g[it];
		// Variable for landmarks. 
		// Landmarks for one face is a vector of points
		// There can be more than one face in the image. Hence, we 
		// use a vector of vector of points. 
		vector< vector<Point2f> > landmarks;
		// Run landmark detector
		bool success = facemark->fit(frame, faces_g, landmarks);
		if (success)
		{
			// If successful, render the landmarks on the face
			for (size_t i = 0; i < faces_g.size(); i++)
			{
				cv::rectangle(frame, faces_g[i], Scalar(0, 255, 0), 3);
			}
			for (int i = 0; i < landmarks.size(); i++)
			{
				drawLandmarks(frame, landmarks[i]);
				/*for (size_t j = 0; j < landmarks[i].size(); j++)
				circle(frame, Point(landmarks[i][j].x, landmarks[i][j].y), 1, Scalar(255, 0, 0), 2);*/
			}
		}
		// Display results 
		//imshow("Facial Landmark Detection", frame);
		img_sender(img, landmarked);
	}
}
