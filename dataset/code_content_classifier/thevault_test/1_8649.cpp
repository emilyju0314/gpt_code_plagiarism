void determine_type(Card& res, Mat& img) {
	// imwrite("next_card.jpg", img);

	// BGR average.
	cv::Vec3d average;
	int count;
	get_average_non_black(img, average, count);

	detect_color(res, average);

	detect_fullness(res, img);

	detect_shape(res, img);
}