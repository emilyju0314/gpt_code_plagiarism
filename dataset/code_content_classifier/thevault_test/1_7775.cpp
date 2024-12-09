int Mapper::findFarthestPoint(int id, int dimLimit)
{
  int farthest = 0;
  double longestdist = 0;

  for (int i = 0; i < size; i ++)
    {
      double dist = getDistance(stringVector[i], coordinatesVector[i],
				stringVector[id], coordinatesVector[id],
				dimLimit);
      if(dist > longestdist)
	{
	  farthest = i;
	  longestdist = dist;
	}
    }

  return farthest;
}