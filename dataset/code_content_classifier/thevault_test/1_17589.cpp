IplImage* drawUCharGraph(const uchar *arraySrc, int nArrayLength, IplImage *imageDst)
{
	int s = 200;	// size of graph height
	int b = 10;		// border around graph within the image
	int w = nArrayLength + b*2;	// width of the image
	int h = s + b*2;		// height of the image
	IplImage *imageGraph;	// output image

	// Get the desired image to draw into.
	if (!imageDst) {
		// Create an RGB image for graphing the data
		imageGraph = cvCreateImage(cvSize(w,h), 8, 3);

		// Clear the image
		cvSet(imageGraph, WHITE);
	}
	else {
		// Create a new copy of the image, so we know we have to free an image later
		imageGraph = cvCloneImage(imageDst);
	}
	if (!imageGraph) {
		cerr << "ERROR in drawUCharGraph(): Couldn't create image of " << w << " x " << h << endl;
		exit(1);
	}
	CvScalar colorGraph = getGraphColor();	// use a different color each time.

	// Draw the horizontal & vertical axis
	cvLine(imageGraph, cvPoint(b,h-b), cvPoint(b+nArrayLength, h-b), BLACK);
	cvLine(imageGraph, cvPoint(b,h-b), cvPoint(b, h-(b+s)), BLACK);

	// Find the max value of the data, so we can draw it at full scale
	float maxV = 0.0;
	for (int i=0; i<nArrayLength; i++) {
		float v = (float)arraySrc[i];
		if (v > maxV)
			maxV = v;
	}

	// Draw the values
	CvPoint ptPrev = cvPoint(b,h-b);	// Start the lines at the 1st point.
	if (maxV == 0)
		maxV = 0.00000001f;	// Stop a divide-by-zero error
	float fscale = (float)s / maxV;
	for (int i=0; i<nArrayLength; i++) {
		int y = (int)((float)arraySrc[i] * fscale);	// Get the values at a bigger scale
		CvPoint ptNew = cvPoint(b+i,h-(b+y));
		cvLine(imageGraph, ptPrev, ptNew, colorGraph);	// Draw a line from the previous point to the new point
		ptPrev = ptNew;
	}

	return imageGraph;
}