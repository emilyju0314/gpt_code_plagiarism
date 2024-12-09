IplImage *rotateImage(const IplImage *src, float angleDegrees, float scale)
{
	// Create a map_matrix, where the left 2x2 matrix is the transform and the right 2x1 is the dimensions.
	float m[6];
	CvMat M = cvMat(2, 3, CV_32F, m);
	int w = src->width;
	int h = src->height;

	float divscale = 1.0f;
	if (scale != 1.0f && scale > 1e-20)
		divscale = 1.0f / scale;
	float angleRadians = angleDegrees * (CV_PI / 180.0f);
	m[0] = (float)(cos(angleRadians) * divscale);
	m[1] = (float)(sin(angleRadians) * divscale);
	m[3] = -m[1];
	m[4] = m[0];
	m[2] = w*0.5f;  
	m[5] = h*0.5f;  

	// Make a spare image for the result
	CvSize sizeRotated;
	sizeRotated.width = cvRound(scale * w);
	sizeRotated.height = cvRound(scale * h);

	// Rotate and scale
	IplImage *imageRotated = cvCreateImage( sizeRotated, src->depth, src->nChannels );

	// Transform the image
	cvGetQuadrangleSubPix( src, imageRotated, &M);

	return imageRotated;
}