int StringMap::SimilarStrings(const string queryString,
			      const vector<string> &stringVector,
			      const int edThreshold,
			      bool countingDuplicates)
{
  int count = 0;

  for (int i = 0; i < stringVector.size(); i ++)
    {
      int eddist = ed(queryString, stringVector[i]);
      if (eddist <= edThreshold
	  && (countingDuplicates || eddist > 0)) // check if need to ignore those identical-string pairs
	{
	  //cout << "Similar String:\t [" << stringVector[i] << "]" << endl;
	  count ++;
	}
      }

  return count;
}