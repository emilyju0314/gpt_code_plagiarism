void printImageInfo(const IplImage *image_tile, const char *label)
{
	if (label)
	{
		std::cout << label << ": ";
	}
	if (image_tile)
	{
		std::cout << "[Image] = " << image_tile->width << "x" << image_tile->height << "px, " << image_tile->nChannels
			<< "channels of " << image_tile->depth << "bit depth, widthStep=" << image_tile->widthStep << ", origin=" << image_tile->origin;
		if (image_tile->roi)
		{
			std::cout << " ROI=[at " << image_tile->roi->xOffset << "," << image_tile->roi->yOffset
				<< " of size " << image_tile->roi->width << "x" << image_tile->roi->height << ", COI=" << image_tile->roi->coi << "].";
		}
		else {
			std::cout << " ROI=<null>.";
		}
		std::cout << std::endl;
	}
	else
	{
		std::cout << "[Image] = <null>" << std::endl;
	}
}