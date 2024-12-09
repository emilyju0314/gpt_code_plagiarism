CvRect scaleRectInPlace(const CvRect rectIn, float scaleX, float scaleY, float borderX, float borderY, int w, int h)
{
	CvRect rect = rectIn;	// Make a local copy
	// Scale the image region size and add an extra border to the region size
	rect.x -= cvRound((scaleX - 1.0f) * (float)rect.width * 0.5f + borderX);
	rect.y -= cvRound((scaleY - 1.0f) * (float)rect.height * 0.5f + borderY);
	rect.width = cvRound(scaleX * (float)rect.width + 2.0f * borderX);
	rect.height = cvRound(scaleY * (float)rect.height + 2.0f * borderY);
	// Make sure it doesn't go outside the image
	if (w > 0 && h > 0) {
		if (rect.x < 0) {
			rect.width += rect.x;	// shrink the width, since 'x' is negative
			rect.x = 0;
		}
		if (rect.x + rect.width > w)
			rect.width = w - rect.x;
		if (rect.y < 0) {
			rect.height += rect.y;	// shrink the height, since 'y' is negative
			rect.y = 0;
		}
		if (rect.y + rect.height > h)
			rect.height = h - rect.y;
	}
	return rect;
}