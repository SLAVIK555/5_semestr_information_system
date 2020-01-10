//#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
//#include "catch.hpp"
#define _CRT_SECURE_NO_WARNINGS
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <vector>
#include "opencv2/opencv.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include "allocation_and_send.h"
#include <opencv2/face.hpp>
#include "drawLandmarks.hpp"
#include "identification.h"


using namespace std;
using namespace cv;
using namespace cv::face;

// Create an instance of Facemark
//Ptr<Facemark> facemark = FacemarkLBF::create();
// Load landmark detector
//facemark->loadModel("lbfmodel.yaml");

int allocation_and_send::allocattor(Mat frame, Ptr<Facemark> facemark, int faceid, int& countt, vector<string>names, Ptr<FaceRecognizer> model, int mode)
{
	identification I;

	Mat crop;
	Mat gray;


	// Create an instance of Facemark
	//Ptr<Facemark> facemark = FacemarkLBF::create();
	// Load landmark detector
	//facemark->loadModel("lbfmodel.yaml");
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
	//drawer(frame, faces);
	//cropper(frame, crop, faces, allocated, m_allocated);
	//cropper(gray, crop, faces_g, allocated_g, m_allocated_g);
	//cropper(gray, crop, faces_g, faceid, countt/*, allocated_g, m_allocated_g*/);
	//landmarker(frame, faces_g, allocated_g, landmarked, m_allocated_g, m_landmarked, facemark);
	//I.datasetter(frame, faceid, countt);
	//I.predictor(frame, faces, names, model);
	//return countt;
	switch (mode)
	{
	case 1:
		I.datasetter(frame, faceid, countt);
		break;
	case 3:
		I.predictor(frame, faces, names, model);
		break;
	default:
		break;
	}
	return 0;
}

int allocation_and_send::drawer(Mat frame, std::vector<Rect> faces, int label, double confidence, vector<string>names)
{
	// Draw rectangle on the detected faces
	Mat drawres = frame;
	if (!faces.empty()) {
		for (int i = 0; i < faces.size(); i++)//size_t i = 0
		{
			rectangle(drawres, faces[i], Scalar(0, 255, 0), 3);
		}

		//string names[] = { "unknown", "slava", "igor" };
		/*string Name;
		vector<string>names;
		ifstream in;
		in.open("C:\\Users\\slava\\OneDrive\\Документы\\Visual Studio 2015\\Projects\\MAXIMOV2\\MAXIMOV2\\name.txt", std::ios::in);
		while (true) {
			getline(in, Name);
			if (!in.eof()) {
				names.push_back(Name);
				Name.clear();
			}
			else
			{
				break;
			}
		}*/
		
		stringstream ss;
		ss << names[label] << ";  " << confidence << "%";
		putText(drawres, ss.str(), Point(faces[0].x, faces[0].y), 1, 2, Scalar(0, 0, 255), 2);

		//cout << confidence << endl;
		//Mat d = drawres;
		//string s = to_string(confidence);
		//putText(d, s, Point(faces[1].x, faces[1].y), 1, 2, Scalar(0, 0, 255), 2);
		//cout << faces.size() << endl;
		if (!drawres.empty()) {
			imshow("predict", drawres);
		}
		/*else {
			int i = 0;
			while (true) {
				i++;
				cout << i << endl;
			}
		}*/
		//const string rectangl;
		//displayer(rectangl, drawres);
		return 0;
	}
}

int allocation_and_send::cropper(Mat image, Mat crop, std::vector<Rect> faces, int faceid, int& countt/*, vector<string> all, vector<Mat> img*/)
{
	//identification I;
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

		//name_sender(crop, all);
		//img_sender(crop, img);//send to img-vector
		//landmarker(crop, faces_g, allocated_g, landmarked, m_allocated_g, m_landmarked, facemark);
	}
	if (!crop.empty()) {
		//I.datasetter(crop, faceid, countt);
	}
	//waitKey(0);
	//const string rectangl;
	//displayer(rectangl, crop);
	//return crop;
	cout << countt << endl;
	//return counttt;
}

/*void allocation_and_send::name_sender(Mat image, vector<string> vec)
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
}*/

/*void allocation_and_send::img_sender(Mat image, vector<Mat> img)
{
	img.push_back(image);//add to base of picture
}*/

void allocation_and_send::landmarker(Mat img, std::vector<Rect> faces_g, Ptr<Facemark> facemark)
{
	//identification I;
	// Create an instance of Facemark
	//Ptr<Facemark> facemark = FacemarkLBF::create();
	// Load landmark detector
	//facemark->loadModel("lbfmodel.yaml");
	// Create local copy of image
	//Mat img;
	//for (int it = 0; it<m_allocated_g.size(); it++) {
		//img = m_allocated_g[it];
		// Variable for landmarks. 
		// Landmarks for one face is a vector of points
		// There can be more than one face in the image. Hence, we 
		// use a vector of vector of points. 
		vector< vector<Point2f> > landmarks;
		// Run landmark detector
		bool success = facemark->fit(img, faces_g, landmarks);
		if (success)
		{
			// If successful, render the landmarks on the face
			for (size_t i = 0; i < faces_g.size(); i++)
			{
				cv::rectangle(img, faces_g[i], Scalar(0, 255, 0), 3);
			}
			for (int i = 0; i < landmarks.size(); i++)
			{
				drawLandmarks(img, landmarks[i]);
				for (size_t j = 0; j < landmarks[i].size(); j++) {
					circle(img, Point(landmarks[i][j].x, landmarks[i][j].y), 1, Scalar(0, 0, 0), 2);
					//cout << 1 << endl;
					//I.identificator(img, landmarks, i);
				}
			}
		}
		// Display results 
		//imshow("Facial Landmark Detection", img);
		//img_sender(img, m_landmarked);
		/////////////////////
		//const string fm;
		//displayer(fm, img);
	//}

}

/*void allocation_and_send::displayer(const string name, Mat showimg)
{
	imshow(name, showimg);
}*/
