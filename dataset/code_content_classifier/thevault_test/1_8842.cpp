void eraseLines(Mat &origional, Mat &dst, int lineheight, vector<Point2d> &out_lines) {
	Mat grey = origional.clone();
	adaptiveThreshold(origional, grey, 128, ADAPTIVE_THRESH_GAUSSIAN_C,
			THRESH_BINARY, 7, 5);

	Mat canny;
	Canny(grey, canny, 50, 200, 3);
	vector<Vec4i> p_lines;

	/// 2. Use Probabilistic Hough Transform
	HoughLinesP(canny, p_lines, 1, CV_PI / 180, 120, 100, 100);

	/// Show the result

	vector<vector<Vec4i> > lines;

	while (p_lines.size() != 0) {
		int lowesty = canny.rows;
		Vec4i lowestline;
		int lowestindex = -1;
		vector<Vec4i> temp;


		//find the lowest segment of each line
		for (size_t i = 0; i < p_lines.size(); i++) {
			Vec4i l = p_lines[i];

			if (l[1] < lowesty || l[3] < lowesty) {
				lowestline = l;
				lowesty = (l[1] < l[3] ? l[1] : l[3]);
				lowestindex = i;
			}
		}

		//erase first line and push back to temp
		p_lines.erase(p_lines.begin() + lowestindex);
		temp.push_back(lowestline);
		double midy = (lowestline[1] + lowestline[3]) / 2.0;

		for (size_t i = 0; i < p_lines.size(); i++) {
			Vec4i l = p_lines[i];

			if (l[1] < midy + lineheight / 2.0 && l[1] > midy - lineheight / 2.0
					&& l[3] < lowesty + lineheight / 2.0
					&& l[3] > lowesty - lineheight / 2.0) {
				temp.push_back(l);
				p_lines.erase(p_lines.begin() + i);
				i--;
			}
		}
		lines.push_back(temp);

		for (size_t i = 0; i < lines.size(); i++) {

			int min_x = canny.cols;
			int min_y = canny.rows;
			int max_x = 0;
			int max_y = 0;
			for (size_t j = 0; j < lines[i].size(); j++) {
				Vec4i l = lines[i][j];
				line(dst, Point(l[0], l[1]), Point( l[2],  l[3]), Scalar(128), 2,
													CV_AA);
				if (l[0] < min_x) {
					min_x = l[0];
					min_y = l[1];
				}
				if (l[2] < min_x) {
					min_x = l[2];
					min_y = l[3];
				}
				if (l[0] > max_x) {
					max_x = l[0];
					max_y = l[1];
				}
				if (l[2] > max_x) {
					max_x = l[2];
					max_y = l[3];
				}

			}
			int dx = max_x - min_x;
			int dy = max_y - min_y;

			cout << min_x << ", " << max_x << ", " << min_y << ", " << max_y
					<< ", " << endl;
			if ((dx) > (0.8 * dst.cols) && dy < 0.5 * lineheight) {
				double a = (double) dy / (double) dx;

				double b = min_y - (min_x * a);



				double zz = a * dst.cols + b;

				//int begin = (int) (b + 0.5);
				//int end = (int) (zz + 0.5);
				Point2d out_l = Point2d(a,b);
				if(!inPointVector(out_l, out_lines)){
					out_lines.push_back(out_l);
				}


			}

		}


	}
	namedWindow("lines");
	imshow("lines", dst);
}