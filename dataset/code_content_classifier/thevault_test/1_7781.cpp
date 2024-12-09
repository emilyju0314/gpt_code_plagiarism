int StringMap::SimilarPairs(const vector<string> &stringVector1,
			    const vector<string> &stringVector2,
			    int edThreshold,
			    bool countingDuplicates)
{
  int count = 0;

  cout << "Computing # of similar pairs. Be patient, since it may take O(n^2) time ... " << endl << endl;
  for (int i = 0; i < stringVector1.size(); i ++)
    for (int j = 0; j < stringVector2.size(); j ++)
      {
	/*int eddist = ed(stringVector1[i], stringVector2[j]);
	if (eddist <= edThreshold
	&& (countingDuplicates || eddist > 0)) // check if need to ignore those identical-string pairs*/
      if (SimilarString(stringVector1[i], stringVector2[j], edThreshold)
	  && (countingDuplicates || stringVector1[i] != stringVector2[j])) // check if need to ignore those identical-string pairs
	{
	  //cout << stringVector1[i] << " || " << stringVector2[j] << endl;
	  count ++;
	}
      }

  return count;
}