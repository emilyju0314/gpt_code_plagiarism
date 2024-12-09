void memAdvancedUsage() {
  cout << "----- MEM ADVANCED USAGE ----" << endl;

  // create gramgenerator and similarity metric
  GramGenFixedLen gramGen(2);
  SimMetricEd simMetric(gramGen);
  
  // create index compressed with holes, using TimeCost as hole selection algorithm 
  // and specifiying the non-default string container and Array<unsigned> as inverted list
  StringContainerRM strContainer;
  strContainer.createContainer("tmpcollection.txt");
  strContainer.openContainer("tmpcollection.txt");  
  strContainer.fillContainer(dictionary.begin(), dictionary.end());
  // params: string container, gram generator, compression ratio, training workload, training metric, training threshold, ratio cost, 
  //         data sampling fraction, queries sampling fraction, max sting length, fanout
  FtIndexerDiscardListsTimeCost<StringContainerRM, Array<unsigned> > 
    indexer(&strContainer, &gramGen, 0.5f, &dictionary, &simMetric, 2.0f, false, 0.01f, 0.25f, 20, 10);
  indexer.addPartFilter(new LengthFilter(20));
  indexer.buildIndex();
  
  // create merger specifying inverted list type
  ScanCountMerger<Array<unsigned> > merger(dictionary.size());
  // create searcher passing merger and indexer
  // specify all template arguments, need to specify merger if not default (DivideSkipMerger)
  FtSearcherMem<FtIndexerDiscardListsTimeCost<StringContainerRM, Array<unsigned> >, ScanCountMerger<Array<unsigned> > > searcher(&merger, &indexer);
  
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
  FtIndexerDiscardListsTimeCost<StringContainerRM, Array<unsigned> > indexerLoaded(&strContainer);
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
  
  cout << "-------------------------" << endl << endl;
}