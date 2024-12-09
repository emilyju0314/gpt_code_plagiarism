void memBasicUsage3() {  
  cout << "----- MEM BASIC USAGE 3 ----" << endl;

  // create gramgenerator and similarity metric
  GramGenFixedLen gramGen(2); // using fixed-length grams
  SimMetricJacc simMetric(gramGen); // using the jaccard distance (using set semantics)
  
  // create simple indexer with default template arguments
  // default: in-memory index using Array<unsigned> as an inverted list container
  // first create a string container and fill it with strings to index
  StringContainerVector strContainer;
  strContainer.fillContainer("data/female_names.txt", 4000); // fill the container from a datafile and use the first 4000 lines
  FtIndexerMem<> indexer(&strContainer, &gramGen, 20, 10); // maxStrLen=20, fanout=10
  indexer.addPartFilter(new LengthFilter(20)); // add length filtering with a maximum string length of 50
  indexer.buildIndex();
  
  // create merger
  ScanCountMerger<> merger(4000);
  // create searcher, specifying a non-default merger
  FtSearcherMem<FtIndexerMem<>, ScanCountMerger<> > searcher(&merger, &indexer);
  
  vector<unsigned> resultStringIDs;
  Query query("kathrin", simMetric, 0.7f);
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