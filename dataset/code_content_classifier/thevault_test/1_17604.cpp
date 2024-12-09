void drawCross(IplImage *img, const CvPoint pt, int radius, const CvScalar color)
{
	CvPoint p1, p2, p3, p4;
	// Make sure the points are within the image
	p1 = cvPoint( max(pt.x-radius,0),             pt.y );
	p2 = cvPoint( min(pt.x+radius,img->width-1),  pt.y );
	p3 = cvPoint( pt.x,                           max(pt.y-radius,0) );
	p4 = cvPoint( pt.x,                           min(pt.y+radius,img->height-1) );
	// Draw a horizontal line through the given point
	cvLine(img, p1, p2, color);
	// Draw a vertical line through the given point
	cvLine(img, p3, p4, color);
}