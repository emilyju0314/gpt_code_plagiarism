CvPoint2D32f mapRotatedImagePoint(const CvPoint2D32f pointOrig, const IplImage *image, float angleDegrees, float scale)
{
	// Get the old image center.
	CvPoint2D32f ptImageCenterOrig = cvPoint2D32f(image->width / 2.0f, image->height / 2.0f);
	// Get the new image center (after the rotation & scale that was performed to the image by 'rotateImage()').
	CvPoint2D32f ptImageCenterNew = scalePointF(ptImageCenterOrig, scale);
	// Get the relative coords of the point
	CvPoint2D32f relPOrig = subtractPointF(pointOrig, ptImageCenterOrig);	// relative coords
	// Rotate & scale the relative coords of the point
	CvPoint2D32f relPNew = rotatePointF(relPOrig, angleDegrees);
	relPNew = scalePointF(relPNew, scale);
	// Get the absolute coords of the new point
	CvPoint2D32f ptPNew = addPointF(relPNew, ptImageCenterNew);
	return ptPNew;
}