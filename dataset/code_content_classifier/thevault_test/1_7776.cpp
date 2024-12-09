Coordinates Mapper::mappedCoordinates(string s)
{
  Coordinates coordinates;

  getDistanceFlag = true;
  for (int dim = 0; dim < dimensionality; dim ++)
    {
      int idA = pivotsA[dim];
      int idB = pivotsB[dim];

      double dab = getDistance(stringVector[idA], coordinatesVector[idA], 
			       stringVector[idB], coordinatesVector[idB], 
			       dim);

      double x = getDistance(s, coordinates,
			     stringVector[idA], coordinatesVector[idA], 
			     dim);

      double y = getDistance(s, coordinates,
			     stringVector[idB], coordinatesVector[idB], 
			     dim);
      
      double coord = (x * x + dab * dab - y * y)/(2 * dab);

      coordinates.push_back(coord);
    }
  
  return coordinates;
}