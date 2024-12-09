IplImage* convertImageYIQtoRGB(const IplImage *imageYIQ)
{
	float fY, fI, fQ;
	float fR, fG, fB;
	const float FLOAT_TO_BYTE = 255.0f;
	const float BYTE_TO_FLOAT = 1.0f / FLOAT_TO_BYTE;
	const float MIN_I = -0.5957f;
	const float MIN_Q = -0.5226f;
	const float Y_TO_FLOAT = 1.0f / 255.0f;
	const float I_TO_FLOAT = -2.0f * MIN_I / 255.0f;
	const float Q_TO_FLOAT = -2.0f * MIN_Q / 255.0f;

	// Create a blank RGB image
	IplImage *imageRGB = cvCreateImage(cvGetSize(imageYIQ), 8, 3);
	if (!imageRGB || imageYIQ->depth != 8 || imageYIQ->nChannels != 3) {
		printf("ERROR in convertImageYIQtoRGB()! Bad input image.\n");
		exit(1);
	}

	int h = imageYIQ->height;				// Pixel height
	int w = imageYIQ->width;				// Pixel width
	int rowSizeYIQ = imageYIQ->widthStep;	// Size of row in bytes, including extra padding
	char *imYIQ = imageYIQ->imageData;		// Pointer to the start of the image pixels.
	int rowSizeRGB = imageRGB->widthStep;	// Size of row in bytes, including extra padding
	char *imRGB = imageRGB->imageData;		// Pointer to the start of the image pixels.
	for (int y=0; y<h; y++) {
		for (int x=0; x<w; x++) {
			// Get the YIQ pixel components
			uchar *pYIQ = (uchar*)(imYIQ + y*rowSizeYIQ + x*3);
			int bY = *(uchar*)(pYIQ+0);	// Y component
			int bI = *(uchar*)(pYIQ+1);	// I component
			int bQ = *(uchar*)(pYIQ+2);	// Q component

			// Convert from 8-bit integers to floats
			fY = (float)bY * Y_TO_FLOAT;
			fI = (float)bI * I_TO_FLOAT + MIN_I;
			fQ = (float)bQ * Q_TO_FLOAT + MIN_Q;
			// Convert from YIQ to RGB
			// where R,G,B are 0-1, Y is 0-1, I is -0.5957 to +0.5957, Q is -0.5226 to +0.5226.
			fR =  fY  + 0.9563 * fI + 0.6210 * fQ;
			fG =  fY  - 0.2721 * fI - 0.6474 * fQ;
			fB =  fY  - 1.1070 * fI + 1.7046 * fQ;
			// Convert from floats to 8-bit integers
			int bR = (int)(fR * FLOAT_TO_BYTE);
			int bG = (int)(fG * FLOAT_TO_BYTE);
			int bB = (int)(fB * FLOAT_TO_BYTE);

			// Clip the values to make sure it fits within the 8bits
			//if (bR > 255 || bR < 0 || bG > 255 || bG < 0 || bB > 255 || bB < 0) {
			//	cout << "Warning: RGB pixel(" << x << "," << y << ") is being clipped. " << bR << "," << bG << "," << bB << endl;
			//}
			if (bR > 255)
				bR = 255;
			if (bR < 0)
				bR = 0;
			if (bG > 255)
				bG = 255;
			if (bG < 0)
				bG = 0;
			if (bB > 255)
				bB = 255;
			if (bB < 0)
				bB = 0;

			// Set the RGB pixel components. NOTE that OpenCV stores RGB pixels in B,G,R order.
			uchar *pRGB = (uchar*)(imRGB + y*rowSizeRGB + x*3);
			*(pRGB+0) = bB;		// B component
			*(pRGB+1) = bG;		// G component
			*(pRGB+2) = bR;		// R component
		}
	}
	return imageRGB;
}