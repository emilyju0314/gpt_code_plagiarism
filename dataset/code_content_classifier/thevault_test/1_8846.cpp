void drawPoints(Mat &image, std::vector<KeyPoint> points, Scalar color) {
	for (unsigned int i = 0; i < points.size(); i++) {
		LOGD("Drawpoints:");
		LOGD("Keypoint size:");
		LogInt((int)points[i].size);
		LOGD("Keypoint location:");
		LogInt((int)points[i].pt.x);
		LogInt((int)points[i].pt.y);

		KeyPoint kp = points[i];
		CvRect rect = cvRect(kp.pt.x - ((int) kp.size / 2),
				kp.pt.y - ((int) kp.size / 2), (int) kp.size, (int) kp.size);
		rectangle(image, cvPoint(rect.x, rect.y),
				cvPoint(rect.x + rect.width, rect.y + rect.height), color, 4, 8,0);
	}

}