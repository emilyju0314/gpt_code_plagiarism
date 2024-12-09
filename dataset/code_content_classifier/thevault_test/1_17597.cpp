float findDistanceBetweenPointsF(const CvPoint2D32f p1, const CvPoint2D32f p2)
{
	// Calc the pythagoras distance.
	float dx = (p1.x - p2.x);
	float dy = (p1.y - p2.y);
	return sqrt((float) (dx * dx + dy * dy));
}