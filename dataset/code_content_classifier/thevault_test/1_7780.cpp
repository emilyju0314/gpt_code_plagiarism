int StringMap::RTreeJoin(const vector<string> &stringVector1,
			 const vector<string> &stringVector2,
			 const int edThreshold,
			 Rtree *rtree1, 
			 Rtree *rtree2,
			 float newThreshold,
			 const bool countingDuplicates,
			 const string resultFileName)
{
  DistanceFunction df;
  join_pair_result join_result;
  int numberFoundPairs = 0;

  // parameters for collecting performance info:
  long  disk_acc1[10], disk_acc2[10], cpu_comps[10], total_cpus;
  float distance = 0.0;
  int   result=1;

  //float delta = DELTA;  // maximum mapped distance between pairs
  // open the join
  rtree1->SearchJoinOpen(rtree2, &df, &newThreshold,
			 disk_acc1, 10, disk_acc2, 10,
			 cpu_comps, 10, &total_cpus);

  int falsepositive=0;
  ofstream out;
  out.open(resultFileName.c_str());
  while (rtree1->SearchJoinNext(distance, join_result) == 1)
    {
      int id1 = join_result.first.the_id;
      int id2 = join_result.second.the_id;

      // we have to convert a dummy maximal number back to 0 since we have
      // replaced id 0 with this dummy number when constructing the R-trees
      if( id1 == DUMMYMAXNUM ) id1 = 0;
      if( id2 == DUMMYMAXNUM ) id2 = 0;

      /*int eddist = ed(stringVector1[id1], stringVector2[id2]);
	if (eddist <= edThreshold
	&& (countingDuplicates || eddist > 0)) // check if need to ignore those identical-string pairs*/
      if (SimilarString(stringVector1[id1], stringVector2[id2], edThreshold)
	  && (countingDuplicates || stringVector1[id1] != stringVector2[id2])) // check if need to ignore those identical-string pairs
	{
	  out << stringVector1[id1] << endl;
	  out << stringVector2[id2] << endl << endl;
	  numberFoundPairs ++;

	  double newDist = mapper->mappedDistance(stringVector1[id1], stringVector2[id2]);
	  //cout << "Found: [" << stringVector1[id1] << "],[" 
	  //<< stringVector2[id2] << "] = " << newDist << endl;
	}
      else
	falsepositive++;
  }
  out.close();

  rtree1->SearchJoinClose(); // cleanup


  /*out.open(ERRORFILE);
  out<<falsepositive;
  out.close();*/
 
 return numberFoundPairs;
}