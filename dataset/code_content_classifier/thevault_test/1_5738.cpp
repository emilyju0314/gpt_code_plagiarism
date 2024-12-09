void FindMeteor::CMetDetection::getPointsRange(int &s1, int &h1, const vector<Point> &contours_in_i, map<int, Point> &outputArray)
{
	for (int a = s1; a <= h1; a++) {
		if (a < 0)
		{
			a = 0;
			h1 = h1 + 1;
		}

		if (s1 < 0 && a == h1 && s1 + contours_in_i.size() >= 0) /// "if"maybe have problem
		{

			a = s1 + contours_in_i.size();
			h1 = contours_in_i.size() - 1;
			s1 = 0;
		}


		if (a > contours_in_i.size() - 1) {
			a = 0;
			h1 = h1 % contours_in_i.size();
		}
		outputArray[a] = contours_in_i[a];
	}
}