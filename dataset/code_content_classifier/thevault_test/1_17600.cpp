CvRect scaleRect(const CvRect rectIn, float scaleX, float scaleY, int w, int h)
{
	CvRect rect;
	// Scale the image region position & size
	rect.x = cvRound(scaleX * (float)rectIn.x);
	rect.y = cvRound(scaleY * (float)rectIn.y);
	rect.width = cvRound(scaleX * (float)rectIn.width);
	rect.height = cvRound(scaleY * (float)rectIn.height);
	// Make sure it doesn't go outside the image
	if (w > 0 && h > 0) {
		if (rect.x + rect.width > w)
			rect.width = w - rect.x;
		if (rect.y + rect.height > h)
			rect.height = h - rect.y;
	}
	return rect;
}