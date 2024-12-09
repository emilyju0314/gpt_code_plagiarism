bool SingleStringTest(int argc, char *argv[])
{
  // read in the two lists of strings from two files
  string mapperFileName("mapper.bin");
  StringMap *sm;
  vector<string> stringVector;

  int useSavedFiles = false;
  cout << "Usage: " << argv[0] << " [load]" << endl;
  if (argc==2 && 0==strcmp(argv[1],"load")) // use old tree
    useSavedFiles = true;

  if (useSavedFiles) // use the saved mapper
    {
      sm = new StringMap(mapperFileName);
      stringVector = sm->getStrings();
    }
  else // build a mapper from scratch
    {
      string srcFileName("source.txt");
      readStrings(stringVector, srcFileName);
      
      // create a StringMap
      sm = new StringMap(stringVector);
      
      // map the strings to a new Euclidean space
      sm->Map();
      sm->saveMapperToFile(mapperFileName);
    }

  int edThreshold = 2;
  // Compute the new threshold in the new Euclidean space by doing sampling.
  // The percentage can be reduced (to save time) if the data set is large
  float newThreshold = sm->getNewThreshold(stringVector, 0.5,
					   edThreshold);

  string rtreeFileName("rtreesearch.bin");
  if (useSavedFiles) // use the saved RTree
    {
      sm->LoadSearchRTree(stringVector, rtreeFileName);
    }
  else
    {
      cout << "Constructing an R-trees ...." << endl;
      sm->ConstructSearchRtree(stringVector, rtreeFileName);
    }

  // this flag indicates whether we need to counter duplicate-string pairs
  //bool countingDuplicates = false;
  bool countingDuplicates = true;

  double totalRecall = 0;
  int queryNumber = 50;
  float totalStringMapTime = 0;
  float totalNaiveTime = 0;
  clock_t startTime, endTime;
  float diffTime;
  struct tms buff;

  for (register int i = 0; i < queryNumber; i ++)
    {
      int id = rand() % stringVector.size();
      string queryString = stringVector[id];

      cout << "\nSearching for [" << queryString << "]" << endl
	   << "-----------------" << endl;
      startTime = times(&buff);
      int numberFoundStrings = sm->Search(queryString,
					  edThreshold,
					  newThreshold,
					  countingDuplicates);
      endTime = times(&buff);
      float stringMapTime = static_cast<float>(endTime - startTime) / sysconf(_SC_CLK_TCK);
      totalStringMapTime += stringMapTime;
      
      // compute the recall of mapping these strings
      // use a naive approach
      cout << "-----------------" << endl;
      startTime = times(&buff);
      int numberSimilarStrings = sm->SimilarStrings(queryString,
						    stringVector,
						    edThreshold,
						    countingDuplicates);
      endTime = times(&buff);
      float naiveTime = static_cast<float>(endTime - startTime) / sysconf(_SC_CLK_TCK);
      totalNaiveTime += naiveTime;
      
      double recall;
      if (numberSimilarStrings > 0)
	recall = (float)numberFoundStrings / (float) numberSimilarStrings;
      else
	recall = 1;

      cout << "Recall is " << numberFoundStrings << "/" << numberSimilarStrings
	   << " = " << recall
	   << ". StringMap time = "<< stringMapTime
	   << " seconds. Naive time " << naiveTime << " secs." << endl;

      totalRecall += recall;
    }

  cout << "\nAvg String Map time " << totalStringMapTime / queryNumber
       << ". Naive time " << totalNaiveTime / queryNumber << endl;
  cout << "Avg recall " << totalRecall / queryNumber << endl;

  delete sm;

  return true;
}