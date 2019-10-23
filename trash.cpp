/*void allocattor(string file_with_picture) {
	Mat image;
	Mat crop;
	Mat res;

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
		ellipse(image, center, Size(faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar(255, 0, 255), 4, 8, 0);*//*
rectangle(image, faces[i], Scalar(0, 255, 0), 3);
	}

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

		crop = frame(roi_b);*/
		//resize(crop, res, Size(128, 128), 0, 0, INTER_LINEAR); // This will be needed later while saving images
		//cvtColor(crop, gray, CV_BGR2GRAY); // Convert cropped image to Grayscale

		// Form a filename
		/*filename = "";
		stringstream ssfn;
		ssfn << filenumber << ".jpg";
		filename = ssfn.str();
		filenumber++;

		imwrite(filename, crop);

		waitKey(0);
		//return 0;
	}
	imshow("Detected Face", image);
	imshow("Cropped Face", crop);
}

void sender(string name_of_file_with_face) {

}

*/