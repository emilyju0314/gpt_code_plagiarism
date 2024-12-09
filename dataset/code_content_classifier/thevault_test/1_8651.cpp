void clean_the_white(const Mat& img_initial, Mat& img_bw) {
	Mat img_gray;
	cv::cvtColor(img_initial, img_gray, cv::COLOR_BGR2GRAY);
	
	// Cut the inner 40% of the image, and threshold based on that part only.
	Mat img_gray_50 = img_gray(cv::Rect(
		img_gray.cols * 3 / 10, img_gray.rows * 3 / 10,
		img_gray.cols * 4 / 10, img_gray.rows * 4 / 10));


	Mat img_bw_50;
	double threshold = cv::threshold(
		img_gray_50, img_bw_50, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);
	// Move the threshold a bit up, we know that our white is pretty white,
	// and anything very close to it must be kept out.
	threshold += (255.0 - threshold) / 2.5;

	// Now use that threshold on the initial image.
	cv::threshold(img_gray, img_bw, threshold, 255, CV_THRESH_BINARY);

	// imwrite("Ximg_gray.jpg", img_gray);
	// imwrite("Ximg_bw.jpg", img_bw);
}