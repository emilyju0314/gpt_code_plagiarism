BOOST_AUTO_TEST_CASE(SingleTreeVsNaive)
{
  arma::mat dataset;

  // Hard-coded filename: bad?
  // Code duplication: also bad!
  if (!data::Load("test_data_3_1000.csv", dataset))
    BOOST_FAIL("Cannot load test dataset test_data_3_1000.csv!");

  KNN knn(dataset, SINGLE_TREE_MODE);

  // Set up computation for naive mode.
  KNN naive(dataset, NAIVE_MODE);

  arma::Mat<size_t> neighborsTree;
  arma::mat distancesTree;
  knn.Search(15, neighborsTree, distancesTree);

  arma::Mat<size_t> neighborsNaive;
  arma::mat distancesNaive;
  naive.Search(15, neighborsNaive, distancesNaive);

  for (size_t i = 0; i < neighborsTree.n_elem; i++)
  {
    BOOST_REQUIRE_EQUAL(neighborsTree[i], neighborsNaive[i]);
    BOOST_REQUIRE_CLOSE(distancesTree[i], distancesNaive[i], 1e-5);
  }
}