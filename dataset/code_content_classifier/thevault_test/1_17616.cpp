void saveFloatImage(const char *filename, const IplImage *srcImg)
{
	cout << "Saving Float Image '" << filename << "' (" << srcImg->width << "," << srcImg->height << "). " << endl;
	IplImage *byteImg = convertFloatImageToUcharImage(srcImg);
	cvSaveImage(filename, byteImg);
	cvReleaseImage(&byteImg);
	//cout << "done saveFloatImage()" << endl;
}