IPLAPIIMPL(void, iplAddS,(IplImage* srcImage, IplImage* dstImage, int value))
{
	assert (compareHeader (srcImage, dstImage));
	assert (srcImage->depth == dstImage->depth);

	// assume images have the same size and 8 bits/pixel/planes.
	switch (srcImage->depth)
	{
	case IPL_DEPTH_8U:
		{
			const int size = srcImage->imageSize;
			unsigned char * src = (unsigned char *)srcImage->imageData;
			unsigned char * dst = (unsigned char *)dstImage->imageData;
			
			short tmp;

			for (int i = 0; i < size; i++)
			{
				tmp = *src++ + value;
				if (tmp < 0) 
					tmp = 0;
				else
				if (tmp > 255)
					tmp = 255;
				*dst++ = char(tmp);
			}
		}
		break;

	case IPL_DEPTH_8S:
		{
			const int size = srcImage->imageSize;
			char * src = srcImage->imageData;
			char * dst = dstImage->imageData;
			
			short tmp;

			for (int i = 0; i < size; i++)
			{
				tmp = *src++ + value;
				if (tmp < -128) 
					tmp = -128;
				else
				if (tmp > 127)
					tmp = 127;
				*dst++ = char(tmp);
			}
		}
		break;

	default:
		assert (1 == 0);
		// NOT IMPLEMENTED.
		break;
	}
}