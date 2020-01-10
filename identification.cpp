#include "identification.h"
#include "allocation_and_send.h"
#include <sstream>
#include <iostream>
#include <string>
#include <cstdio>
#include <conio.h>
#include "opencv2/opencv.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include "allocation_and_send.h"
#include <opencv2/face.hpp>
#include <math.h>
//#include <sstream>
#include <vector>
//#include "drawLandmarks.hpp"


using namespace std;
using namespace cv;
using namespace cv::face;

int identification::identificator(Mat frame, vector<vector<Point2f>> landmarks, int i)
{
	/**
	vector<string>name_of_identificated;
	vector<float>wid_of_identificated;
	vector<float>hid_of_identificated;

	string name;
	ifstream nfile("nameofidentificated.txt");
	while (!nfile.eof()) {
		nfile >> name;
		name_of_identificated.push_back(name);
	}
	nfile.close();

	float wid;
	ifstream wfile("widofidentificated.txt");
	while (!wfile.eof()) {
		wfile >> wid;
		wid_of_identificated.push_back(wid);
	}
	wfile.close();

	float hid;
	ifstream hfile("hidofidentificated.txt");
	while (!hfile.eof()) {
		hfile >> hid;
		hid_of_identificated.push_back(hid);
	}
	hfile.close();
	*/

	//for (size_t j = 0; j < landmarks[i].size(); j++) {
	//	circle(frame, Point(landmarks[i][j].x, landmarks[i][j].y), 1, Scalar(255, 0, 0), 2);
	//}
	line(frame, Point(landmarks[i][27].x, landmarks[i][27].y), Point(landmarks[i][8].x, landmarks[i][8].y), Scalar(0, 0, 255), 2);
	float XL = (landmarks[i][45].x + landmarks[i][42].x) / 2;
	float YL = (landmarks[i][45].y + landmarks[i][42].y) / 2;
	float XR = (landmarks[i][39].x + landmarks[i][36].x) / 2;
	float YR = (landmarks[i][39].y + landmarks[i][36].y) / 2;
	line(frame, Point(XL, YL), Point(XR, YR), Scalar(0, 0, 255), 2);
	float DX = XR - XL;
	float DY = YR - YL;
	float L = sqrt(DX * DX + DY * DY);
	float X1 = (landmarks[i][27].x);
	float Y1 = (landmarks[i][27].y);
	float X2 = (landmarks[i][8].x);
	float Y2 = (landmarks[i][8].y);
	float DX1 = abs(X1 - X2);
	float DY1 = abs(Y1 - Y2);
	float L1 = sqrt(DX1 * DX1 + DY1 * DY1);
	float X0 = (XL + XR) / 2;
	float Y0 = (YL + YR) / 2;
	float sin_AL = DY / L;
	float cos_AL = DX / L;

	float X_User_0 = (landmarks[i][27].x - X0) / L;
	float Y_User_0 = -(landmarks[i][27].y - Y0) / L;
	float X_User27 = X_User_0 * cos_AL - Y_User_0 * sin_AL;
	float Y_User27 = X_User_0 * sin_AL + Y_User_0 * cos_AL;

	X_User_0 = (landmarks[i][30].x - X0) / L;
	Y_User_0 = -(landmarks[i][30].y - Y0) / L;
	float X_User30 = X_User_0 * cos_AL - Y_User_0 * sin_AL;
	float Y_User30 = X_User_0 * sin_AL + Y_User_0 * cos_AL;
	//if (name_of_identificated.size() == wid_of_identificated.size() && name_of_identificated.size() == hid_of_identificated.size()) {
		if (abs(X_User27 - X_User30) <= 0.1) {
			putText(frame, std::to_string(abs(L1 / L)), Point(landmarks[i][27].x, landmarks[i][27].y), 1, 2, Scalar(0, 0, 255), 2);
		}
		//for (int it = 0; it < name_of_identificated.size(); it++) {
		//	if (abs(wid_of_identificated[it] - L) < 0.1 && abs(hid_of_identificated[it] - L1) < 0.1) {
		//		putText(frame, name_of_identificated[it], Point(landmarks[i][27].x, landmarks[i][27].y), 1, 2, Scalar(0, 255, 255));
		//	}
		//}
	//}
	//else {
	//	return 1;
	//}
	
		return 0;
}

int identification::datasetter(Mat image, int faceid, int& countt)
{
	//allocation_and_send A;

	//Mat gray;
	//Mat crop;
	//std::vector<Rect> faces_g;

	//CascadeClassifier faceDetector("haarcascade_frontalface_alt2.xml");
	//cvtColor(frame, gray, COLOR_BGR2GRAY);
	//faceDetector.detectMultiScale(gray, faces_g);

	//A.cropper(gray, crop, faces_g);
	//cout << "11" << endl;
	string filename;
	// Form a filename
	filename = "";
	stringstream ssfn;
	ssfn << "C:\\Users\\slava\\OneDrive\\Документы\\Visual Studio 2015\\Projects\\MAXIMOV2\\x64\\Release\\dataset\\Users\\" << faceid << "\\data\\" << countt << ".bmp";
	filename = ssfn.str();
	//if (!crop.empty()) {
	//resize(image, image, (200, 200));
	imwrite(filename, image);
	//namedWindow(filename, 1);
	imshow(filename, image);
	//cout << "11" << endl;
	//}
	//cout << filename << endl;
	countt++;
	//return countt;
	//if (countt == 20) {
	//	exit(0);
	//}
	//if (waitKey(1) == 27) break;
	return 0;
}

int identification::delitor(int faceid, int & countt)
{
	string filename;
	// Form a filename
	while (true) {
		filename = "";
		stringstream ssfn;
		ssfn << "C:\\Users\\slava\\OneDrive\\Документы\\Visual Studio 2015\\Projects\\MAXIMOV2\\x64\\Release\\dataset\\Users\\" << faceid << "\\data\\" << countt << ".bmp";
		filename = ssfn.str();
		Mat img = imread(filename);
		if (!img.empty()) {
			remove(filename.c_str());
			countt++;
		}
		else
		{
			countt = 0;
			break;
		}
	}

	//if (!crop.empty()) {
	//resize(image, image, (200, 200));
	//imwrite(filename, image);
	//imshow(filename, image);
	//cout << "11" << endl;
	//}
	//cout << filename << endl;
	//countt++;
	//return countt;
	return 0;
}

int identification::trainer(int max_num_of_faceid, int& countt)
{
	//int countt = 0;
	
	//string filename = "";
	//stringstream ssfn;
	//ssfn << "C:\\Users\\slava\\OneDrive\\Документы\\Visual Studio 2015\\Projects\\MAXIMOV2\\x64\\Release\\dataset\\Users\\" << faceid << "\\data\\" << countt << ".bmp";
	//filename = ssfn.str();
	Mat graysc;

	vector<Mat>images;
	vector<int>labels;
	//int i;
	//int max_num_of_faceid = 2;
	for (int faceid = 1; faceid <= max_num_of_faceid; faceid++) {
		//i = 1;
		//for (countt = 0; countt < 142; countt++) {
		while (true) {
			string filename = "";
			stringstream ssfn;
			ssfn << "C:\\Users\\slava\\OneDrive\\Документы\\Visual Studio 2015\\Projects\\MAXIMOV2\\x64\\Release\\dataset\\Users\\" << faceid << "\\data\\" << countt << ".bmp";
			filename = ssfn.str();

			Mat img = imread(filename);
			if (!img.empty()) {
				
				cvtColor(img, graysc, COLOR_BGR2GRAY);
				images.push_back(graysc);
				labels.push_back(faceid);
				cout << "loading" << " " << faceid << " " << countt << endl;
				countt++;
				//imshow("window", graysc);
				//waitKey(0);
			}
			else {
				countt = 0;
				break;
			}
		}
		//}
	}
	//images.push_back(imread("C:\\Users\\slava\\OneDrive\\Документы\\Visual Studio 2015\\Projects\\MAXIMOV2\\x64\\Release\\dataset\\Users\\2\\data\\0.bmp"));
	//labels.push_back(2);
	
	//Ptr<FaceRecognizer> model = FisherFaceRecognizer::create();
	//Ptr<FaceRecognizer> createLBPHFaceRecognizer(int radius = 1, int neighbors = 8, int grid_x = 8, int grid_y = 8, double threshold = DBL_MAX);
	Ptr<FaceRecognizer> model = LBPHFaceRecognizer::create();
	model->train(images, labels);
	cout << "training" << endl;
	model->write("C:\\Users\\slava\\OneDrive\\Документы\\Visual Studio 2015\\Projects\\MAXIMOV2\\x64\\Release\\dataset\\training\\training.xml");
	cout << "training done" << endl;
	return 0;
}

int identification::predictor(Mat image, std::vector<Rect> faces, vector<string>names, Ptr<FaceRecognizer> model)
{
	allocation_and_send A;

	Mat gray;
	if (!image.empty()) {
		cvtColor(image, gray, COLOR_BGR2GRAY);

		//Ptr<FaceRecognizer> model = FisherFaceRecognizer::create();
		//Ptr<FaceRecognizer> model = LBPHFaceRecognizer::create();
		//model->read("C:\\Users\\slava\\OneDrive\\Документы\\Visual Studio 2015\\Projects\\MAXIMOV2\\x64\\Release\\dataset\\training\\training.xml");
		// Some variables for the predicted label and associated confidence (e.g. distance):
		int predicted_label = -1;
		double predicted_confidence = 0.0;
		// Get the prediction and associated confidence from the model
		model->predict(gray, predicted_label, predicted_confidence);
		if (predicted_confidence < 100) {
			predicted_confidence = (int)(100 - predicted_confidence);
			A.drawer(image, faces, predicted_label, predicted_confidence, names);
		}
		else {
			predicted_confidence = (int)(100 - predicted_confidence);
			predicted_label = 0;
			A.drawer(image, faces, predicted_label, predicted_confidence, names);
		}
		/*else {
			int i = 0;
			while (true) {
				i++;
				cout << i << endl;
			}
		}*/
	}
	/*else {
		int i = 0;
		while (true) {
			i++;
		}
	}*/

	return 0;
}

int identification::getcount(int faceid, int & countt)
{
	string filename;
	// Form a filename
	while (true) {
		filename = "";
		stringstream ssfn;
		ssfn << "C:\\Users\\slava\\OneDrive\\Документы\\Visual Studio 2015\\Projects\\MAXIMOV2\\x64\\Release\\dataset\\Users\\" << faceid << "\\data\\" << countt << ".bmp";
		filename = ssfn.str();
		Mat img = imread(filename);
		if (!img.empty()) {
			//remove(filename.c_str());
			countt++;
		}
		else
		{
			return countt;
			break;
		}
	}
	return 0;
}

