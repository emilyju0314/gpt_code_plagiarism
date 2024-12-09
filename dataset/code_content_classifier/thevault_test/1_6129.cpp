IPLAPIIMPL(void, iplRGB2HSV,(IplImage* rgbImage, IplImage* hsvImage))
{
	// Image types should be checked.
	const int planesize = rgbImage->widthStep * rgbImage->height;
	unsigned char *sdata = (unsigned char *)rgbImage->imageData; // bgr
	unsigned char *ddata0 = (unsigned char *)hsvImage->imageData;		// Hue.
	unsigned char *ddata1 = ddata0 + 1;		// Saturation.
	unsigned char *ddata2 = ddata1 + 1;		// Value.

	double max,min;
	double red,green,blue;
	double hue,sat;

	const int width = rgbImage->width;
	const int height = rgbImage->height;
	const int size = width * height; // # of pixels.

	for (int i = 0; i < size; i++)
	{
		blue = *sdata++ / 255.0;
		green = *sdata++ / 255.0;
		red = *sdata++ / 255.0;

		if (red > green && red > blue) 
		{
			max = red;
			if (green > blue)
				min = blue;
			else
				min = green;
		}
		else
		if (green > red && green > blue)
		{
			max = green;
			if (red > blue)
				min = blue;
			else
				min = red;
		}
		else
		{
			max = blue;
			if (red > green)
				min = green;
			else
				min = red;
		}

		// value
		*ddata2 = (unsigned char)(255.0 * max);
		ddata2 += 3;

		// saturation
		if (max != 0.0)
		{
			sat = *ddata1 = (unsigned char)(255 * (max - min) / max);
		}
		else
			sat = *ddata1 = 0;
		ddata1 += 3;

		// hue
		if (sat == 0)
			*ddata0 = 0;
		else
		{
			double rc = (max - red) / (max - min);
			double gc = (max - green) / (max - min);
			double bc = (max - blue) / (max - min);
			if (red == max)
				hue = bc - gc;
			else
			if (green == max)
				hue = 2 + rc - bc;
			else
			if (blue == max)
				hue = 4 + gc - rc;

			hue *= 60.0;
			if (hue < 0.0)
				hue += 360.0;
		
			assert (hue >= 0.0 && hue < 360.0);
			// IPL 2.5 compatibility. Scaling to 0-255
			// there's a little chance that the value rounds to 256.0!
			// need clipping rather than truncation.
			hue = (hue / 360.0 * 256.0);
			if (hue == 256.0)
				hue = 255.0;

			*ddata0 = (unsigned char)(hue);
		}

		ddata0 += 3;
	}
}