IPLAPIIMPL(IplImage*, iplCreateImageHeader,
               (int   nChannels,  int     alphaChannel, int     depth,
                char* colorModel, char*   channelSeq,   int     dataOrder,
                int   origin,     int     align,
                int   width,      int   height, IplROI* roi, IplImage* maskROI,
                void* imageId,    IplTileInfo* tileInfo))
{
	switch (depth)
	{
	default:
	case IPL_DEPTH_1U:
		return NULL;

    case IPL_DEPTH_8U:
    case IPL_DEPTH_8S:
    case IPL_DEPTH_32F:
    case IPL_DEPTH_16U:
	case IPL_DEPTH_16S:
    case IPL_DEPTH_32S:
		break;
	}

	IplImage *r = NULL;
	r = new IplImage;
	assert (r != NULL);

	r->nSize = sizeof(IplImage);
	r->ID = 0xf0f0f0f0;			// pasa's ID for IPL under QNX.

	r->nChannels = nChannels;
	r->alphaChannel = alphaChannel;
	r->depth = depth;

	memcpy (r->colorModel, colorModel, 4);
	memcpy (r->channelSeq, channelSeq, 4);

	assert (dataOrder == IPL_DATA_ORDER_PIXEL);

	r->dataOrder = dataOrder;	// IPL_DATA_ORDER_PIXEL, IPL_DATA_ORDER_PLANE
	r->origin = origin;
	
	assert (align == IPL_ALIGN_QWORD);	/// don't want to be bothered w/ alignment beside the 
										/// the 8 bytes stuff.
	assert (align == YARP_IMAGE_ALIGN);

	r->align = align;
	r->width = width;
	r->height = height;
	r->roi = NULL;
	r->maskROI = NULL;
	r->imageId = NULL;

	r->tileInfo = NULL;
	const int linew = width * (depth & IPL_DEPTH_MASK) / 8 * nChannels;
	r->widthStep = linew + PAD_BYTES(linew, YARP_IMAGE_ALIGN);

	r->imageSize = r->widthStep * height;
	r->imageData = NULL;
	r->tileInfo = NULL;

	memset (r->BorderMode, 0, 4);
	memset (r->BorderConst, 0, 4);

	r->imageDataOrigin = NULL;
	return r;
}