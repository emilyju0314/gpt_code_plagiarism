IplImage* resizeImage(const IplImage *origImg, int newWidth, int newHeight, bool keepAspectRatio)
{
	IplImage *outImg = 0;
	int origWidth;
	int origHeight;
	if (origImg) {
		origWidth = origImg->width;
		origHeight = origImg->height;
	}
	if (newWidth <= 0 || newHeight <= 0 || origImg == 0 || origWidth <= 0 || origHeight <= 0) {
		std::cerr << "ERROR: Bad desired image size of " << newWidth << "x" << newHeight << " in resizeImage().\n";
		exit(1);
	}

	if (keepAspectRatio) {
		//cerr << "ResizeImage :" << origWidth << "x" << origHeight << " -> " << newWidth << "x" << newHeight << " (rOld" << (origWidth / (float)origHeight) << ", rNew" << (newWidth / (float)newHeight) << endl;
		// Resize the image without changing its aspect ratio, by cropping off the edges and enlarging the middle section.
		CvRect r;
		float origAspect = (origWidth / (float)origHeight);	// input aspect ratio
		float newAspect = (newWidth / (float)newHeight);	// output aspect ratio
		if (origAspect > newAspect) {	// crop width to be origHeight * newAspect
			int tw = (origHeight * newWidth) / newHeight;
			r = cvRect((origWidth - tw)/2, 0, tw, origHeight);
		}
		else {	// crop height to be origWidth / newAspect
			int th = (origWidth * newHeight) / newWidth;
			r = cvRect(0, (origHeight - th)/2, origWidth, th);
		}
		//cerr << "cropping image to (" << r.width << "x" << r.height << " at (" << r.x << "," << r.y << ")." << endl;
		IplImage *croppedImg = cropImage(origImg, r);
		// Call this function again, but with the new aspect ratio image.
		//cerr << "calling resizeImage(" << newWidth << "," << newHeight << "false)" << endl;
		outImg = resizeImage(croppedImg, newWidth, newHeight, false);	// do a scaled image resize, since the aspect ratio is correct now.
		cvReleaseImage( &croppedImg );

	}
	else {

		// Scale the image to the new dimensions, even if the aspect ratio will be changed.
		outImg = cvCreateImage(cvSize(newWidth, newHeight), origImg->depth, origImg->nChannels);
		if (newWidth > origImg->width && newHeight > origImg->height) {
			// Make the image larger
			//printf("Making the image larger\n"); fflush(stdout);
			cvResetImageROI((IplImage*)origImg);
			cvResize(origImg, outImg, CV_INTER_LINEAR);	// CV_INTER_CUBIC or CV_INTER_LINEAR is good for enlarging
		}
		else {
			// Make the image smaller
			//printf("Making the image smaller\n"); fflush(stdout);
			cvResetImageROI((IplImage*)origImg);
			cvResize(origImg, outImg, CV_INTER_AREA);	// CV_INTER_AREA is good for shrinking / decimation, but bad at enlarging.
		}

	}
	return outImg;
}