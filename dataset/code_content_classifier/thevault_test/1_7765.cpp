void memBasicUsage2() {  
  cout << "----- MEM BASIC USAGE 2 ----" << endl;

  // create gramgenerator and similarity metric
  GramGenFixedLen gramGen(2); // using fixed-length grams
  SimMetricEd simMetric(gramGen); // using the edit distance
  
  // create simple indexer with default template arguments
  // default: in-memory index using Array<unsigned> as an inverted list container
  // first create a string container and fill it with strings to index
  StringContainerVector strContainer;
  strContainer.fillContainer("data/female_names.txt", 4000); // fill the container from a datafile and use the first 4000 lines
  FtIndexerMem<> indexer(&strContainer, &gramGen, 20, 10); // maxStrLen=20, fanout=10
  indexer.addPartFilter(new CharsumFilter(20)); // add charsum filtering with a maximum string length of 20
  indexer.buildIndex();
  
  // create merger
  DivideSkipMerger<> merger;
  // create searcher passing merger and indexer with default template arguments
  // default: same as indexer, i.e. assumed simple indexer with Array<unsigned> as inverted lists and DivideSkipMerger as merger type
  FtSearcherMem<> searcher(&merger, &indexer);
  
  vector<unsigned> resultStringIDs;
  Query query("kathrin", simMetric, 1.0f);
  searcher.search(query, resultStringIDs);  
  cout << "SIMILAR STRINGS: " << endl;
  for(unsigned i = 0; i < resultStringIDs.size(); i++) {
    string tmp;
    strContainer.retrieveString(tmp, resultStringIDs.at(i));
    cout << tmp << endl;
  }
  
  cout << "SAVING INDEX" << endl;
  indexer.saveIndex("exampleindex.ix");

  cout << "LOADING INDEX" << endl;
  FtIndexerMem<> indexerLoaded(&strContainer);
  indexerLoaded.loadIndex("exampleindex.ix");
  
  resultStringIDs.clear();
  searcher.setFtIndexer(&indexerLoaded);
  searcher.search(query, resultStringIDs);
  cout << "SIMILAR STRINGS: " << endl;
  for(unsigned i = 0; i < resultStringIDs.size(); i++) {
    string tmp;
    strContainer.retrieveString(tmp, resultStringIDs.at(i));
    cout << tmp << endl;
  }

  cout << "----------------------" << endl << endl;
}