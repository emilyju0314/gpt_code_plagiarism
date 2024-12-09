void FindMeteor::CMetDetection::CheckRectContour(vector<vector<Point>> &contours_poly, cv::Mat& dilateImg)
{

	for (int i = 0; i < contours_poly.size(); i++) {


		if (fabs(norm(contours_poly[i][0] - contours_poly[i][1])) > fabs(norm(contours_poly[i][0] - contours_poly[i][3]))) {
			/// The long edge of the rectangle should be longer than the short edge. 
			if (fabs(norm(contours_poly[i][0] - contours_poly[i][1])) < 3.0 * fabs(norm(contours_poly[i][0] - contours_poly[i][3]))) {
				contours_poly.erase(contours_poly.begin() + i);
				i--;
				continue;
			}
			if (fabs(norm(contours_poly[i][0] - contours_poly[i][1])) < 3.0 * fabs(norm(contours_poly[i][1] - contours_poly[i][2]))) {
				contours_poly.erase(contours_poly.begin() + i);
				i--;
				continue;
			}

			/// The difference of short edges should less than 10px AND The short edge of rectangle should less than 15px
			if (fabs(norm(contours_poly[i][0] - contours_poly[i][3]) - norm(contours_poly[i][1] - contours_poly[i][2])) > 10.0|| 
				fabs(norm(contours_poly[i][0] - contours_poly[i][3]))>15.0 || fabs(norm(contours_poly[i][1] - contours_poly[i][2]))>15.0) {
				contours_poly.erase(contours_poly.begin() + i);
				i--;
				continue;
			}

			/// The long edge of rectangle should NOT be greater than 75px 
			if (fabs(norm(contours_poly[i][0] - contours_poly[i][1])) <= 75.0 || fabs(norm(contours_poly[i][2] - contours_poly[i][3])) <=75.0) {
				contours_poly.erase(contours_poly.begin() + i);
				i--;
				continue;
			}
		}
		else {
			/// The long edge of the rectangle should be longer than the short edge. 
			if (fabs(norm(contours_poly[i][0] - contours_poly[i][3])) < 3.0 * fabs(norm(contours_poly[i][0] - contours_poly[i][1]))) {
				contours_poly.erase(contours_poly.begin() + i);
				i--;
				continue;
			}
			if (fabs(norm(contours_poly[i][0] - contours_poly[i][3])) < 3.0 * fabs(norm(contours_poly[i][2] - contours_poly[i][3]))) {
				contours_poly.erase(contours_poly.begin() + i);
				i--;
				continue;
			}

			/// The difference of short edges should less than 10px AND The short edge of rectangle should less than 15px
			if (fabs(norm(contours_poly[i][0] - contours_poly[i][1]) - norm(contours_poly[i][2] - contours_poly[i][3])) > 10.0 ||
				fabs(norm(contours_poly[i][0] - contours_poly[i][1])) > 15.0 || fabs(norm(contours_poly[i][2] - contours_poly[i][3])) > 15.0) {
				contours_poly.erase(contours_poly.begin() + i);
				i--;
				continue;
			}
			/// The long edge of rectangle should NOT be greater than 75px 
			if (fabs(norm(contours_poly[i][0] - contours_poly[i][3])) <= 75.0 || fabs(norm(contours_poly[i][1] - contours_poly[i][2])) <= 75.0) {
				contours_poly.erase(contours_poly.begin() + i);
				i--;
				continue;
			}
		}

		///*== filling rate in a contour ==*///
		int samePixel = 0;
		int allPixel = 0;

		Rect m_rect = boundingRect(contours_poly.at(i));

		for (int nX = m_rect.x; nX < (m_rect.x + m_rect.width); ++nX)
		{
			for (int nY = m_rect.y; nY < (m_rect.y + m_rect.height); ++nY)
			{
				Point2f tempoint(nX, nY);

				if (pointPolygonTest(contours_poly[i], tempoint, 0) >= 0) {
					allPixel++;
					Point2f tempoint(nX, nY);
					if (dilateImg.at<uchar>(nY, nX) == 255)
						samePixel++;
				}
			}
		}


		if (double(samePixel) / double(allPixel) < 0.5&&double(samePixel)<500)
		{
			contours_poly.erase(contours_poly.begin() + i);
			i--;
			continue;
		}
	
	}

}