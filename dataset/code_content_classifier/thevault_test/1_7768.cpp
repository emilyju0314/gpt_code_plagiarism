void ondiskBasicUsage1() {
  cout << "----- ONDISK BASIC USAGE 1 ----" << endl;

  // create gramgenerator and similarity metric
  GramGenFixedLen gramGen(2);
  SimMetricEd simMetric(gramGen);
  
  // using disk-based string container
  StringContainerRM strContainer(PHO_AUTO);
  strContainer.createAndOpen("collection.rm");
  strContainer.fillContainer(dictionary.begin(), dictionary.end()); // fill the container from dictionary
  // params: container, gramgen, disableStreamBuffer, index filename, bytes per run, max str len, fanout
  FtIndexerOnDisk<> indexer(&strContainer, &gramGen, false, "invlists.ix", 50000, 20, 10);
  indexer.addPartFilter(new LengthFilter(20)); // param: max str len
  indexer.buildIndex();
  
  // create merger specifying inverted list type
  OnDiskMergerSimple<> merger;
  // create searcher passing merger and indexer
  FtSearcherOnDisk<> searcher(&merger, &indexer);
  
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
  FtIndexerOnDisk<> indexerLoaded(&strContainer);
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