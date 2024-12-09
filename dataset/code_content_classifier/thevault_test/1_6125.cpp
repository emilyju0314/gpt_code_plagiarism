IPLAPIIMPL(void, iplAllocateImage,(IplImage* image, int doFill, int fillValue))
{
	// Not implemented depth != 8
	int depth = (image->depth & IPL_DEPTH_MASK)/8;
	assert (image->dataOrder == IPL_DATA_ORDER_PIXEL);
	///assert (image->widthStep == image->width * (image->depth & IPL_DEPTH_MASK) / 8 * image->nChannels);
	assert (image->imageSize == image->widthStep * image->height);

	image->imageData = AllocAligned<char> (image->imageSize);	/// new char[image->imageSize];
	assert (image->imageData != NULL);

	if (image->origin == IPL_ORIGIN_TL)
		image->imageDataOrigin = image->imageData + image->imageSize - image->widthStep;
	else
		image->imageDataOrigin = image->imageData;

	if (doFill)
	{
		// this of course is only valid for depth == 8.
		switch (image->depth)
		{
		case IPL_DEPTH_8U:
		case IPL_DEPTH_8S:
			memset (image->imageData, fillValue, image->imageSize);
			break;

		default:
			assert (1 == 0);
			break;
		}
	}
}