IplImage* convertMatrixToUcharImage(const CvMat *srcMat)
{
	// Fill the Matrix's float data as a float image into this image.
	IplImage srcIplImg;
	cvGetImage(srcMat, &srcIplImg);

	// Convert the float image into a normal Uchar image.
	return convertFloatImageToUcharImage(&srcIplImg);
}