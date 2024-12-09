float findAngleBetweenPointsF(const CvPoint2D32f p1, const CvPoint2D32f p2)
{
	// Calculate the angle of in-plane-rotation of the face based on the angle of the 2 eye positions.
	float dx = (float)(p2.x - p1.x);
	if (dx == 0.0f)
		dx = 0.00000001f;	// Stop a divide-by-zero error.
	float radians = atan2((float) (p2.y - p1.y), dx);	// angle = inv_tan(dy / dx).
	return (radians * 180.0f / CV_PI);	// convert to degrees from radians.
}