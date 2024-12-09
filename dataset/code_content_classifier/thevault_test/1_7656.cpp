MStatus CircularizeNode::sortPoints(MPointArray &pointArray, MPoint &centerPoint, MIntArray &intArray)
{
	std::map<double, int> sortedIndices;
	MVector upVec(0, 1, 0);
	unsigned int nPoints = pointArray.length();
	for (unsigned int i = 0; i < nPoints; ++i)
	{
		MVector posVec = (pointArray[i] - centerPoint).normal();
		double angle = upVec.angle(posVec) / (2 * M_PI) * 360;
		if (posVec[0] < centerPoint[0])
			angle = 360 - angle;

		// If 2 or more verts have same angle, return failure
		if (!sortedIndices.insert(std::make_pair(angle, i)).second)
		{
			return MS::kFailure;
		}
	}

	intArray.clear();
	for (auto map_it = sortedIndices.cbegin(); map_it != sortedIndices.cend(); ++map_it)
	{
		intArray.append(map_it->second);
	}
	
	return MS::kSuccess;
}