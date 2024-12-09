void FindMeteor::CMetDetection::CheckContourandHough(vector<vector<Point>>& contour, vector<Vec4i>& lines)
{
	vector<Point2f> midPoint;
	for (int i = 0; i < lines.size(); i++) {
		midPoint.push_back(Point((lines[i][0] + lines[i][2]) / 2, (lines[i][1] + lines[i][3]) / 2));
	}
	for (int i = 0; i < contour.size(); i++) {
		bool isInContour = false;
		for (int j = 0; j < lines.size(); j++) {
			if (fabs(pointPolygonTest(contour[i], midPoint[j], 1)) < 1.5) {
				isInContour = true;
				break;
				
			}
		}
		if (!isInContour) {
			contour.erase(contour.begin() + i);
			i--;
			continue;
		}
	}
}