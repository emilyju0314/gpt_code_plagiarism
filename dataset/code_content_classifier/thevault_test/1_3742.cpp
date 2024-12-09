void btNearestPointInLineSegment(const btVector3& point, const btVector3& line0, const btVector3& line1, btVector3& nearestPoint)
{
	btVector3 lineDelta = line1 - line0;

	// Handle degenerate lines
	if (lineDelta.fuzzyZero())
	{
		nearestPoint = line0;
	}
	else
	{
		// [0..1] delta
		btScalar delta = (point - line0).dot(lineDelta) / (lineDelta).dot(lineDelta);

		// Clamp the point to conform to the segment's endpoints
		if (delta < 0)
			delta = 0;
		else if (delta > 1)
			delta = 1;

		nearestPoint = line0 + lineDelta * delta;
	}
}