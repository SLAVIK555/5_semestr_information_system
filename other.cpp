/*
#include "opencv2/opencv.hpp"
 
#include <iostream>
#include <fstream>
#include <sstream>
 
using namespace cv;
using namespace std;
 
static Mat toGrayscale(InputArray _src) {
    Mat src = _src.getMat();
    // only allow one channel
    if(src.channels() != 1)
        CV_Error(CV_StsBadArg, "Only Matrices with one channel are supported");
    // create and return normalized image
    Mat dst;
    cv::normalize(_src, dst, 0, 255, NORM_MINMAX, CV_8UC1);
    return dst;
}
 
static void read_csv(const string& filename, vector<Mat>& images, vector<int>& labels, char separator = ';') {
    std::ifstream file(filename.c_str(), ifstream::in);
    if (!file)
        throw std::exception();
    string line, path, classlabel;
    while (getline(file, line)) {
        stringstream liness(line);
        getline(liness, path, separator);
        getline(liness, classlabel);
        images.push_back(imread(path, 0));
        labels.push_back(atoi(classlabel.c_str()));
    }
}
 
int main(int argc, const char *argv[]) {
    // check for command line arguments
    if (argc != 2) {
        cout << "usage: " << argv[0] << " <csv.ext>" << endl;
        exit(1);
    }
    // path to your CSV
    string fn_csv = string(argv[1]);
    // images and corresponding labels
    vector<Mat> images;
    vector<int> labels;
    // read in the data
    try {
        read_csv(fn_csv, images, labels);
    } catch (exception&) {
        cerr << "Error opening file "" << fn_csv << ""." << endl;
        exit(1);
    }
    // get width and height
    //int width = images[0].cols;
    int height = images[0].rows;
    // get test instances
    Mat testSample = images[images.size() - 1];
    int testLabel = labels[labels.size() - 1];
    // ... and delete last element
    images.pop_back();
    labels.pop_back();
    // build the Fisherfaces model
    Ptr<FaceRecognizer> model = createFisherFaceRecognizer();
    model->train(images, labels);
    // test model
    int predicted = model->predict(testSample);
    cout << "predicted class = " << predicted << endl;
    cout << "actual class = " << testLabel << endl;
    // get the eigenvectors
    Mat W = model->eigenvectors();/////////////////////////////////////////Mat W = model->getMat("eigenvectors");
    // show first 10 fisherfaces
    for (int i = 0; i < min(10, W.cols); i++) {
        // get eigenvector #i
        Mat ev = W.col(i).clone();
        // reshape to original size AND normalize between [0...255]
        Mat grayscale = toGrayscale(ev.reshape(1, height));
        // show image (with Jet colormap)
        Mat cgrayscale;
        applyColorMap(grayscale, cgrayscale, COLORMAP_JET);
        imshow(format("%d", i), cgrayscale);
    }
    waitKey(0);
    return 0;
}
*/


/*
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/opencv.hpp"
#include"allocation_and_send.h"
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

void detectAndDisplay(Mat frame)
{
std::vector<Rect> faces;
Mat frame_gray;
Mat crop;
Mat res;
Mat gray;
string text;
stringstream sstm;

cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
equalizeHist(frame_gray, frame_gray);

// Detect faces
face_cascade.detectMultiScale(frame_gray, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));

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

crop = frame(roi_b);
resize(crop, res, Size(128, 128), 0, 0, INTER_LINEAR); // This will be needed later while saving images
cvtColor(crop, gray, CV_BGR2GRAY); // Convert cropped image to Grayscale

// Form a filename
filename = "";
stringstream ssfn;
ssfn << filenumber << ".jpg";
filename = ssfn.str();
filenumber++;

imwrite(filename, gray);

Point pt1(faces[ic].x, faces[ic].y); // Display detected faces on main window
Point pt2((faces[ic].x + faces[ic].height), (faces[ic].y + faces[ic].width));
rectangle(frame, pt1, pt2, Scalar(0, 255, 0), 2, 8, 0);
}

// Show image
sstm << "Crop area size: " << roi_b.width << "x" << roi_b.height << " Filename: " << filename;
text = sstm.str();

putText(frame, text, cvPoint(30, 30), FONT_HERSHEY_COMPLEX_SMALL, 0.8, cvScalar(0, 0, 255), 1, CV_AA);
imshow("original", frame);

if (!crop.empty())
{
imshow("detected", crop);
}
else
destroyWindow("detected");

//////////////////////////////
int main(void)
{
// Load the cascade
if (!face_cascade.load(face_cascade_name)){
printf("--(!)Error loading\n");
return (-1);
}

// Read the image file
Mat frame = imread("/home/sruthi/Downloads/pic.jpg");

// Apply the classifier to the frame
if (!frame.empty()){
detectAndDisplay(frame);
}
else{
printf(" --(!) No captured frame -- Break!");
//break;
}

int c = waitKey(10);

if (27 == char(c)){
//break;
}

return 0;
}
/////////////////////////////




}

*/
