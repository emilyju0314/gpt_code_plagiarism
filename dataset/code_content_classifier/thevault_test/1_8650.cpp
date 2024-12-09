Card detect_card(const Mat& img, cv::Rect area) {
	Card res;
	
	Mat card_img = img(area);
	// imwrite("current_card_whole_unclear.jpg", card_img);
	clear_card(card_img);
	// imwrite("current_card_whole.jpg", card_img);

	Mat card_img_dilated;
	cv::dilate(
		card_img, card_img_dilated,
		Mat(), // use default 3x3 kernel.
		Point(-1, -1),
		1, // Just 1 iteration, if 2, some parts start to connect
		1,
		1);
	// imwrite("current_card_whole_dialted.jpg", card_img_dilated);
	
	// Find out how many parts are there.
	std::vector<cv::Rect> blobs;

	Mat img_gray;
	cv::cvtColor(card_img_dilated, img_gray, cv::COLOR_BGR2GRAY);
	Mat img_bw;
	cv::threshold(img_gray, img_bw, 50, 255, CV_THRESH_BINARY);
	// imwrite("current_card_whole_bw.jpg", img_bw);
	
	FindBlobs(img_bw, blobs);
	
	// Probably this is not a card, but some other white object.
	if (blobs.size() > 3 || blobs.size() == 0)
	{
		res.type = Card_type::NOT_A_CARD_SOME_OTHER_WHITE_OBJECT;
		return res;
	}

	switch (blobs.size()) {
	case 1:
		res.count = Card_count::ONE;
		break;
	case 2:
		res.count = Card_count::TWO;
		break;
	default:
		res.count = Card_count::THREE;
	}

	// Add 3 more pixels from each size, probably they exist.
	int pixel_length = 3;
	if (blobs[0].x > pixel_length)
		blobs[0].x -= pixel_length;
	if (blobs[0].y > pixel_length)
		blobs[0].y -= pixel_length;
	if (blobs[0].x + blobs[0].width + 2* pixel_length  < card_img.cols)
		blobs[0].width += 2 * pixel_length;
	if (blobs[0].y + blobs[0].height + 2 * pixel_length < card_img.rows)
		blobs[0].height += 2 * pixel_length;
	
	Mat first_one = card_img(blobs[0]);
	
	// Take the first one, hope it's ok, and try to determine the type.
	determine_type(res, first_one);
	
	return res;
}