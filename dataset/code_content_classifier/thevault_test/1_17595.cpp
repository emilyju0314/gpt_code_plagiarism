IplImage* convertImageRGBtoYIQ(const IplImage *imageRGB)
{
	float fR, fG, fB;
	float fY, fI, fQ;
	const float FLOAT_TO_BYTE = 255.0f;
	const float BYTE_TO_FLOAT = 1.0f / FLOAT_TO_BYTE;
	const float MIN_I = -0.5957f;
	const float MIN_Q = -0.5226f;
	const float Y_TO_BYTE = 255.0f;
	const float I_TO_BYTE = 255.0f / (MIN_I * -2.0f);
	const float Q_TO_BYTE = 255.0f / (MIN_Q * -2.0f);

	// Create a blank YIQ image
	IplImage *imageYIQ = cvCreateImage(cvGetSize(imageRGB), 8, 3);
	if (!imageYIQ || imageRGB->depth != 8 || imageRGB->nChannels != 3) {
		printf("ERROR in convertImageRGBtoYIQ()! Bad input image.\n");
		exit(1);
	}

	int h = imageRGB->height;				// Pixel height
	int w = imageRGB->width;				// Pixel width
	int rowSizeRGB = imageRGB->widthStep;	// Size of row in bytes, including extra padding
	char *imRGB = imageRGB->imageData;		// Pointer to the start of the image pixels.
	int rowSizeYIQ = imageYIQ->widthStep;	// Size of row in bytes, including extra padding
	char *imYIQ = imageYIQ->imageData;		// Pointer to the start of the image pixels.
	for (int y=0; y<h; y++) {
		for (int x=0; x<w; x++) {
			// Get the RGB pixel components. NOTE that OpenCV stores RGB pixels in B,G,R order.
			uchar *pRGB = (uchar*)(imRGB + y*rowSizeRGB + x*3);
			int bB = *(uchar*)(pRGB+0);	// Blue component
			int bG = *(uchar*)(pRGB+1);	// Green component
			int bR = *(uchar*)(pRGB+2);	// Red component

			// Convert from 8-bit integers to floats
			fR = bR * BYTE_TO_FLOAT;
			fG = bG * BYTE_TO_FLOAT;
			fB = bB * BYTE_TO_FLOAT;
			// Convert from RGB to YIQ,
			// where R,G,B are 0-1, Y is 0-1, I is -0.5957 to +0.5957, Q is -0.5226 to +0.5226.
			fY =    0.299 * fR +    0.587 * fG +    0.114 * fB;
			fI = 0.595716 * fR - 0.274453 * fG - 0.321263 * fB;
			fQ = 0.211456 * fR - 0.522591 * fG + 0.311135 * fB;
			// Convert from floats to 8-bit integers
			int bY = (int)(0.5f + fY * Y_TO_BYTE);
			int bI = (int)(0.5f + (fI - MIN_I) * I_TO_BYTE);
			int bQ = (int)(0.5f + (fQ - MIN_Q) * Q_TO_BYTE);

			// Clip the values to make sure it fits within the 8bits
			//if (bY > 255 || bY < 0 || bI > 255 || bI < 0 || bQ > 255 || bQ < 0) {
			//	cout << "Warning: YIQ pixel(" << x << "," << y << ") is being clipped. " << bY << "," << bI << "," << bQ << endl;
			//}
			if (bY > 255)
				bY = 255;
			if (bY < 0)
				bY = 0;
			if (bI > 255)
				bI = 255;
			if (bI < 0)
				bI = 0;
			if (bQ > 255)
				bQ = 255;
			if (bQ < 0)
				bQ = 0;

			// Set the YIQ pixel components
			uchar *pYIQ = (uchar*)(imYIQ + y*rowSizeYIQ + x*3);
			*(pYIQ+0) = bY;		// Y component
			*(pYIQ+1) = bI;		// I component
			*(pYIQ+2) = bQ;		// Q component
		}
	}
	return imageYIQ;
}