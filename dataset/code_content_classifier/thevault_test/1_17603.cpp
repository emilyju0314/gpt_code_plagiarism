void drawRect(IplImage *img, const CvRect rect, const CvScalar color)
{
	CvPoint p1, p2;
	p1.x = rect.x;
	p1.y = rect.y;
	p2.x = min(rect.x + rect.width-1, img->width-1);	// Make sure the end-point is within the image
	p2.y = min(rect.y + rect.height-1, img->height-1);	//		"		"		"
	cvRectangle(img, p1, p2, color, 1);
}