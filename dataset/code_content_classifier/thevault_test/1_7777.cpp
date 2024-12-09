double Mapper::mappedDistance(string s1, string s2)
{
  Coordinates coordinates1 = mappedCoordinates(s1);
  Coordinates coordinates2 = mappedCoordinates(s2);

  assert(coordinates1.size() == coordinates2.size());

  double dist = 0;
  for (int i = 0; i < dimensionality; i ++)
    {
      double x = coordinates1[i] - coordinates2[i];
      dist += x * x;
    }

  return sqrt(dist);
}