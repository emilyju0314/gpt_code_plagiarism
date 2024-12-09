TEST_F(ArchiveTest, StressArchive) {
  static const int INDEX_SIZE = 1000;
  static const int N_QUERIES = 100;
  
  // setup the random number generator
  mt19937 randEngine(13654);
  uniform_real<> dist(0, 1);
  variate_generator<mt19937&, uniform_real<> > generator(
    randEngine, dist);

  // Now build the index
  for (int i = 0; i < INDEX_SIZE; ++i) {
    index->AddDocument(CreateRandomDoc(generator));
  }
  index->BuildIndex();

  // Now do the round trip
  WriteToBuf(*index);
  shared_ptr<ImageSearchIndex> copy = ReadFromBuf();

  // Finally, issue random queries and check the results
  for (int i = 0; i < N_QUERIES; ++i) {
    vector<SearchResult> origResults;
    vector<SearchResult> copyResults;

    shared_ptr<ImageDocument> queryDoc = CreateRandomDoc(generator);
    index->Search(*queryDoc, &origResults);
    sort_heap(origResults.begin(), origResults.end());
    copy->Search(*queryDoc, &copyResults);
    sort_heap(copyResults.begin(), copyResults.end());


    ASSERT_EQ(origResults.size(), copyResults.size());
    for (unsigned int i = 0; i < origResults.size(); ++i) {
      EXPECT_FLOAT_EQ(origResults[i].score(), copyResults[i].score());
      ExpectEqDoc(*origResults[i].doc(), *copyResults[i].doc());
    }
  }
}