IplImage* smoothImageBilateral(const IplImage *src, float smoothness)
{
	IplImage *imageSmooth = cvCreateImage(cvGetSize(src), src->depth, src->nChannels);
	IplImage *imageOut = cvCreateImage(cvGetSize(src), src->depth, src->nChannels);
	// Do bilateral fitering on the input image
	cvSmooth( src, imageSmooth, CV_BILATERAL, 5, 5, smoothness, smoothness );

	// Mix the smoothed image with the original image
	cvAddWeighted( src, 0.70, imageSmooth, 0.70, 0.0, imageOut );

	//cvSaveImage("bilatA.png", src);
	//cvSaveImage("bilatB.png", imageSmooth);
	//cvSaveImage("bilatC.png", imageOut);
	cvReleaseImage(&imageSmooth);
	return imageOut;
}