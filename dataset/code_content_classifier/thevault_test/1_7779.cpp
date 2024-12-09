double Mapper::getNewThreshold(const vector<string> &stringVector1, const double percentage1,
			       const vector<string> &stringVector2, const double percentage2,
			       const int edThreshold)
{
  double newThreshold = 0;
  
  // make the ranomization deterministic
  srand(92697);

  // generate two partial lists
  vector<string> v1;
  for (register int i = 0; i < (int) stringVector1.size() * percentage1; i ++)
  {
    int id = rand() % stringVector1.size();
    //int id = i;
    v1.push_back(stringVector1[id]);
  }

  vector<string> v2;
  for (register int i = 0; i < (int) stringVector2.size() * percentage2; i ++)
  {
    int id = rand() % stringVector2.size();
    //int id = i; //!!!!
    v2.push_back(stringVector2[id]);
  }

  // use a nested loop to find the maximal mapped distance of similar pairs
  cout << "Trying to compute a new threshold using " << v1.size() 
       << " strings from the first set and " << v2.size() 
       << " from the second." << endl;

  for (register int i = 0; i < v1.size(); i ++)
    {
      string s1 = v1[i];
      for (register int j = 0; j < v2.size(); j ++)
	{
	  string s2 = v2[j];
	  int eddist = ed(s1, s2);
	  if (eddist > edThreshold) // not similar, keep searching
	    continue;

	  // ignore those identical-string pairs
	  if (eddist == 0)
	    continue;

	  // found one
	  double dist = mappedDistance(s1, s2);
	  //cout << "[" << s1 << "],[" << s2 << "] = " << dist << endl;
	  if(dist > newThreshold)
	    newThreshold = dist;
	}
    }

  if (newThreshold == 0)
    {
      cout << "Mapper::getNewThreshold(): failed to compute a new distance threshold."
	   << "Possible Reasons: didn't get enough samples from the two lists." << endl;
      exit(1);
    }

  cout << "Mapper::getNewThreshold() = " << newThreshold << endl;

  // increase the threshold slightly since the R-tree join uses "<" while
  // we want to use "<="
  return newThreshold + 1e-5;
}