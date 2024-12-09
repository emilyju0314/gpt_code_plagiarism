void makeRectFromKeyPoint(KeyPoint kp, Rect &rect, Mat &img) {
	rect = Rect((int) kp.pt.x - kp.size / 2.0, (int) (kp.pt.y - kp.size / 2.0),
			(int) kp.size, (int) kp.size);

	if (rect.x < 0) {
		rect.x = 0;

	}
	if (rect.y < 0) {
		rect.y = 0;

	}
	if (rect.x + rect.width >= img.cols) {
		rect.width =
				(img.cols - rect.x < rect.height) ?
						img.cols - rect.x : rect.height;
		rect.height =
				(img.cols - rect.x < rect.height) ?
						img.cols - rect.x : rect.height;

	}
	if (rect.y + rect.height >= img.rows) {
		rect.width =
				(img.rows - rect.y < rect.width) ?
						img.rows - rect.y : rect.width;
		rect.height =
				(img.rows - rect.y < rect.width) ?
						img.rows - rect.y : rect.width;

	}

}