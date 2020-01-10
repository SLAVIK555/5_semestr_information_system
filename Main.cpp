//#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
//#define CATCH_CONFIG_RUNNER
//#include "catch.hpp"

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
int mode;

int main(int argc, char** argv)
{
	cout << "enter mode; 1-dataset; 2-train; 3-predict" << endl;
	cin >> mode;
	
	//cout << "enter user id" << endl;
	//cin >> faceid;
	// Load Face Detector
	//CascadeClassifier faceDetector("haarcascade_frontalface_alt2.xml");
	string Name;
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
	}
	// Create an instance of Facemark
	Ptr<Facemark> facemark = FacemarkLBF::create();
	// Load landmark detector
	facemark->loadModel("lbfmodel.yaml");
	/////////////////////////////////////////////////////////////////////
	Ptr<FaceRecognizer> model = LBPHFaceRecognizer::create();
	model->read("C:\\Users\\slava\\OneDrive\\Документы\\Visual Studio 2015\\Projects\\MAXIMOV2\\x64\\Release\\dataset\\training\\training.xml");
	// Set up webcam for video capture
	VideoCapture cam(0);
	// Variable to store a video frame and its grayscale 
	//Mat frame, gray;
	// Read a frame
	//identification I;
	//I.trainer(faceid, countt);

	switch (mode)
	{
	case 1:
		cout << "enter user id" << endl;
		cin >> faceid;
		cout << "delete previous data? 1-yes(recomended); 2-no(add new data)" << endl;
		int i;
		cin >> i;
		//i = 2;
		//cin >> i;
		switch (i)
		{
		case 1:
			identification I;
			I.delitor(faceid, countt);
			break;
		case 2:
			//identification I;
			I.getcount(faceid, countt);
			while (cam.read(frame)) {
				allocation_and_send A;//object of class "allocation_and_send"
				A.allocattor(frame, facemark, faceid, countt, names, model, mode);
				if (waitKey(1) == 27) break;
				}
			
			break;
		default:
			break;
		}
		/*while (cam.read(frame)) {
			allocation_and_send A;//object of class "allocation_and_send"
			A.allocattor(frame, facemark, faceid, countt, names, model, mode);
			if (waitKey(1) == 27) break;
		}*/
		break;//for case 1:mode


	case 2:
		int max_num_of_faceid;
		cout << "enter max_num_of_faceid" << endl;
		cin >> max_num_of_faceid;
		identification I;
		I.trainer(max_num_of_faceid, countt);
		break;


	case 3:
		faceid = 1;
		while (cam.read(frame)) {
			allocation_and_send A;//object of class "allocation_and_send"
			A.allocattor(frame, facemark, faceid, countt, names, model, mode);
			if (waitKey(1) == 27) break;
		}
		break;
	default:
		break;
	}
	//while (cam.read(frame))
	//{
		//allocation_and_send A;//object of class "allocation_and_send"
		//A.allocattor(frame, facemark, faceid, countt, names, model);
		//cout << 1 << endl;
		//TEST_CASE("drawer") {
		//	REQUIRE(A.allocator(frame, facemark, faceid, countt) == countt);
		//}
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
		//for (size_t j = 0; j < landmarks[i].size(); j++)
		//circle(frame, Point(landmarks[i][j].x, landmarks[i][j].y), 1, Scalar(255, 0, 0), 2);******
		//}
		//}
		// Display results 
		//imshow("Facial Landmark Detection", frame);
		// Exit loop if ESC is pressed
	//	if (waitKey(1) == 27) break;
	//}
	//system("pause");
	return 0;
}

/*TEST_CASE("drawer") {
	REQUIRE(A.allocator(frame, facemark, faceid, countt) == countt);
}*/
