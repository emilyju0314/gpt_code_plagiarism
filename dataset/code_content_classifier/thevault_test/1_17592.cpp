void showUCharGraph(const char *name, const uchar *arraySrc, int nArrayLength, int delay_ms, IplImage *background)
{
	// Draw the graph
	IplImage *imageGraph = drawUCharGraph(arraySrc, nArrayLength, background);

	// Display the graph into a window
    cvNamedWindow( name );
    cvShowImage( name, imageGraph );

	cvWaitKey( 10 );		// Note that cvWaitKey() is required for the OpenCV window to show!
	cvWaitKey( delay_ms );	// Wait longer to make sure the user has seen the graph

	cvReleaseImage(&imageGraph);
}