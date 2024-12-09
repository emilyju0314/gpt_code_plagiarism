CvRect cropRect(const CvRect rectIn, int w, int h)
{
	CvRect roi = CvRect(rectIn);
	// Make sure the displayed image is within the viewing dimensions
	if (roi.x + roi.width > w)	// Limit the bottom-right from past the image
		roi.width = w - roi.x;
	if (roi.y + roi.height > h)
		roi.height = h - roi.y;
	if (roi.x < 0)				// Limit the top-left from before the image
		roi.x = 0;
	if (roi.y < 0)
		roi.y = 0;
	if (roi.x > w-1)			// Limit the top-left from after the image
		roi.x = w-1;
	if (roi.y > h-1)
		roi.y = h-1;
	if (roi.width > w)			// Limit the large sizes
		roi.width = w - roi.x;
	if (roi.height > h)
		roi.height = h - roi.y;
	if (roi.width < 0)			// Limit the negative sizes
		roi.width = 0;
	if (roi.height < 0)
		roi.height = 0;
	return roi;
}