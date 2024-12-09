void saveFloatMat(const char *filename, const CvMat *srcMat)
{
	//cout << "in Saving Image(" << ((CvMat*)src)->width << "," << ((CvMat*)src)->height << ") '" << filename << "'." << endl;

	// Fill the Matrix's float data as a float image into this temporary image, since it wont be needed after this function.
	IplImage srcIplImg;
	cvGetImage(srcMat, &srcIplImg);
	// Store the float image
	saveFloatImage(filename, &srcIplImg);
}