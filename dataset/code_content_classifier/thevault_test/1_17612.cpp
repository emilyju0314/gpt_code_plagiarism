int saveImage(const char *filename, const IplImage *image)
{
	int ret = -1;
	IplImage *image8Bit = cvCreateImage(cvSize(image->width,image->height), IPL_DEPTH_8U, image->nChannels);	// 8-bit greyscale image.
	if (image8Bit)
		cvConvert(image, image8Bit);	// Convert to an 8-bit image instead of potentially 16,24,32 or 64bit image.
	if (image8Bit)
		ret = cvSaveImage(filename, image8Bit);
	if (image8Bit)
		cvReleaseImage(&image8Bit);
	return ret;
}