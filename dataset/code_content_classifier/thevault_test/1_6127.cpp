IPLAPIIMPL(void, iplSet, (IplImage* image, int fillValue))
{
	assert (image->imageData != NULL);
	assert ((image->depth & IPL_DEPTH_MASK) == 8);
	memset (image->imageData, fillValue, image->imageSize);
}