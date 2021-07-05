#include "stdafx.h"
#include "CppUnitTest.h"

//#include <allocation_and_send.h>
//#include <identification.h>

using namespace std;
using namespace cv;
using namespace cv::face;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MAXIMOV2_TEST
{		
	TEST_CLASS(UnitTest1)
	{
		Mat frame;

		int faceid;
		int countt = 0;

		//Ptr<Facemark> facemark = FacemarkLBF::create();
		//Ptr<Facemark> facemark = createFacemarkLBF();
		//facemark->loadModel("lbfmodel.yaml");
		//CascadeClassifier faceDetector("haarcascade_frontalface_alt2.xml");
	public:
		
		TEST_METHOD(Test_Camera_testing)
		{
			// TODO: Your test code here
			//Mat frame;
			VideoCapture cam(0);
			Assert::AreEqual(cam.read(frame), true);
		}

		TEST_METHOD(Test_Loading_Facemark)
		{
			Ptr<Facemark> facemark = FacemarkLBF::create();
			facemark->loadModel("lbfmodel.yaml");
			Assert::AreEqual(!facemark.empty(), true);
			facemark->clear();
		}

		TEST_METHOD(Test_Haarcascade_load)
		{
			CascadeClassifier faceDetector("haarcascade_frontalface_alt2.xml");
			Assert::AreEqual(!faceDetector.empty(), true);
		}

		TEST_METHOD(Test_Vector_face_size)
		{
			frame = imread("C:\\Users\\slava\\OneDrive\\Документы\\Visual Studio 2015\\Projects\\MAXIMOV2\\MAXIMOV2\\pic.jpg");
			CascadeClassifier faceDetector("haarcascade_frontalface_alt2.xml");
			std::vector<Rect> faces;
			faceDetector.detectMultiScale(frame, faces);
			Assert::AreEqual(!faces.empty(), true);
		}

		TEST_METHOD(Test_File_access1)
		{
			int max_num_of_faceid = 2;
			for (faceid = 1; faceid <= max_num_of_faceid; faceid++) 
			{
				while (true) {
					string filename = "";
					stringstream ssfn;
					ssfn << "C:\\Users\\slava\\OneDrive\\Документы\\Visual Studio 2015\\Projects\\MAXIMOV2\\x64\\Release\\dataset\\Users\\" << faceid << "\\data\\" << countt << ".bmp";
					filename = ssfn.str();
					try
					{
						Mat img = imread(filename);
						if (!img.empty()) {
							throw(1);
						}
						else {
							countt = 0;
							//throw(2);
							break;
						}
						//TODO
						//throw(1);
					}
					catch (int a)
					{
						Assert::AreEqual(a, 1);
						//Assert::AreEqual(a, 2);
						return;
					}

					try
					{
						Mat img = imread(filename);
						if (!img.empty()) {
							//throw(1);
						}
						else {
							countt = 0;
							throw(2);
							break;
						}
						//TODO
						//throw(1);
					}
					catch (int a)
					{
						//Assert::AreEqual(a, 1);
						Assert::AreEqual(a, 2);
						return;
					}
				}
			}
		}////

		TEST_METHOD(Test_File_access2) 
		{
			string Name;
			ifstream in;
			in.open("C:\\Users\\slava\\OneDrive\\Документы\\Visual Studio 2015\\Projects\\MAXIMOV2\\MAXIMOV2\\name.txt", std::ios::in);
			while (true) {
				getline(in, Name);
				if (!in.eof()) {
					Assert::AreEqual(!Name.empty(), true);
					Name.clear();
				}
				else
				{
					break;
				}
			}
		}

		TEST_METHOD(Test_Vector_model_size)
		{
			Mat graysc;

			vector<Mat>images;
			vector<int>labels;

			int faceid = 1;
			int countt = 0;

			string filename = "";
			stringstream ssfn;
			ssfn << "C:\\Users\\slava\\OneDrive\\Документы\\Visual Studio 2015\\Projects\\MAXIMOV2\\x64\\Release\\dataset\\Users\\" << faceid << "\\data\\" << countt << ".bmp";
			filename = ssfn.str();

			Mat img = imread(filename);
			if (!img.empty()) {

				cvtColor(img, graysc, COLOR_BGR2GRAY);
				images.push_back(graysc);
				labels.push_back(faceid);
				//cout << "loading" << " " << faceid << " " << countt << endl;
				//countt++;
				//imshow("window", graysc);
				//waitKey(0);
				Assert::AreEqual(!images.empty() && !labels.empty(), true);
			}
		}

		TEST_METHOD(Test_Model)
		{
			Ptr<FaceRecognizer> model = LBPHFaceRecognizer::create();
			model->read("C:\\Users\\slava\\OneDrive\\Документы\\Visual Studio 2015\\Projects\\MAXIMOV2\\x64\\Release\\dataset\\training\\training.xml");
			Assert::AreEqual(!model.empty(), true);
		}

	};

	TEST_CLASS(UnitTest2)
	{
	
	public:

		TEST_METHOD(Test_Mode_1)
		{
			Mat frame;
			int faceid;
			int countt = 0;
			int mode=1;

			string Name;
			vector<string>names;
			ifstream in;
			in.open("C:\\Users\\slava\\OneDrive\\Документы\\Visual Studio 2015\\Projects\\MAXIMOV2\\MAXIMOV2\\name.txt", std::ios::in);
			getline(in, Name);
			names.push_back(Name);
			/*while (true) {
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

			// Create an instance of Facemark
			Ptr<Facemark> facemark = FacemarkLBF::create();
			// Load landmark detector
			facemark->loadModel("lbfmodel.yaml");
			/////////////////////////////////////////////////////////////////////
			Ptr<FaceRecognizer> model = LBPHFaceRecognizer::create();
			model->read("C:\\Users\\slava\\OneDrive\\Документы\\Visual Studio 2015\\Projects\\MAXIMOV2\\x64\\Release\\dataset\\training\\training.xml");
			// Set up webcam for video capture
			VideoCapture cam(0);
			cam.read(frame);

			//cout << "enter user id" << endl;
			//cin >> faceid;
			faceid = 3;
			//while (cam.read(frame)) {
				allocation_and_send A;//object of class "allocation_and_send"
				//int x = A.allocattor(frame, facemark, faceid, countt, names, model, mode);
				//Assert::AreEqual(x, 0);
				Assert::AreEqual(A.allocattor(frame, facemark, faceid, countt, names, model, mode), 0);
				//if (waitKey(1) == 27) break;
			//}
		}

		TEST_METHOD(Test_Mode_2)
		{
			int countt = 0;
			int max_num_of_faceid = 2;
			//cout << "enter max_num_of_faceid" << endl;
			//cin >> max_num_of_faceid;
			identification I;
			Assert::AreEqual(I.trainer(max_num_of_faceid, countt), 0);
		}

		TEST_METHOD(Test_Mode_3)
		{
			Mat frame;
			int faceid;
			int countt = 0;
			int mode = 3;

			/*string Name;
			vector<string>names;
			ifstream in;
			in.open("C:\\Users\\slava\\OneDrive\\Документы\\Visual Studio 2015\\Projects\\MAXIMOV2\\MAXIMOV2\\name.txt", std::ios::in);
			getline(in, Name);
			names.push_back(Name);*/
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
			/*while (true) {
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

			// Create an instance of Facemark
			Ptr<Facemark> facemark = FacemarkLBF::create();
			// Load landmark detector
			facemark->loadModel("lbfmodel.yaml");
			/////////////////////////////////////////////////////////////////////
			Ptr<FaceRecognizer> model = LBPHFaceRecognizer::create();
			model->read("C:\\Users\\slava\\OneDrive\\Документы\\Visual Studio 2015\\Projects\\MAXIMOV2\\x64\\Release\\dataset\\training\\training.xml");
			// Set up webcam for video capture
			VideoCapture cam(0);
			cam.read(frame);

			//cout << "enter user id" << endl;
			//cin >> faceid;
			faceid = 3;
			//while (cam.read(frame)) {
			allocation_and_send A;//object of class "allocation_and_send"
								  //int x = A.allocattor(frame, facemark, faceid, countt, names, model, mode);
								  //Assert::AreEqual(x, 0);
			Assert::AreEqual(A.allocattor(frame, facemark, faceid, countt, names, model, mode), 0);
			//if (waitKey(1) == 27) break;
			//}
		}
	};
}