#include<stdio.h>
#include<iostream>
#include"allocation_and_send.h"
#include "opencv2/opencv.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;

void allocattor(string file_with_picture){
	Mat image;
 	image = imread(file_with_picture, CV_LOAD_IMAGE_COLOR);
 	
 	// Load Face cascade (.xml file)
 	CascadeClassifier face_cascade;
 	face_cascade.load("haarcascade_frontalface_alt2.xml");
 	
 	// Detect faces
 	std::vector<Rect> faces;
 	face_cascade.detectMultiScale(image, faces, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(30, 30));
 	
 	// Draw circles on the detected faces
 	for (int i = 0; i < faces.size(); i++)//size_t i = 0
	{
 	/*Point center(faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5);
 	ellipse(image, center, Size(faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar(255, 0, 255), 4, 8, 0);*/
 	rectangle(image, faces[i], Scalar(0, 255, 0), 3);
 	}
 	imshow("Detected Face", image);

	waitKey(0);
 	//return 0;
}

void sender(string name_of_file_with_face){
	
}
