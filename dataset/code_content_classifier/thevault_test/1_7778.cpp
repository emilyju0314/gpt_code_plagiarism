double Mapper::getNewThreshold(const vector<string> &stringVector1,
			       const vector<string> &stringVector2,
			       const int edThreshold)
{
  return getNewThreshold(stringVector1, 0.10,
			 stringVector2, 0.10,
			 edThreshold);
}