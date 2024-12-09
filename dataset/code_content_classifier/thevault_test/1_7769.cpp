void ondiskBasicUsage2() {
  cout << "----- ONDISK BASIC USAGE 2 ----" << endl;

  // create gramgenerator and similarity metric
  GramGenFixedLen gramGen(2);
  SimMetricEd simMetric(gramGen);
  
  // using disk-based string container
  StringContainerRM strContainer(PHO_AUTO);
  strContainer.createAndOpen("collection.rm");
  strContainer.fillContainer("data/female_names.txt", 4000); // fill the container from a datafile and use the first 4000 lines
  // params: container, gramgen, disableStreamBuffer, index filename, bytes per run, max str len, fanout
  FtIndexerOnDisk<> indexer(&strContainer, &gramGen, false, "invlists.ix", 50000, 20, 10);
  indexer.autoAddPartFilter(); // automatically choose a partitioning filter based on container stats
  indexer.buildIndex();
  
  // create merger specifying inverted list type
  OnDiskMergerAdapt<> merger;
  // create searcher passing merger and indexer
  FtSearcherOnDisk<FtIndexerOnDisk<>, OnDiskMergerAdapt<> > searcher(&merger, &indexer);
  
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