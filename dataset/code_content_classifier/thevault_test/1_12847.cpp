BOOST_AUTO_TEST_CASE(DualTreeVsNaive1)
{
  arma::mat dataset;

  // Hard-coded filename: bad?
  if (!data::Load("test_data_3_1000.csv", dataset))
    BOOST_FAIL("Cannot load test dataset test_data_3_1000.csv!");

  KNN knn(dataset);

  KNN naive(dataset, NAIVE_MODE);

  arma::Mat<size_t> neighborsTree;
  arma::mat distancesTree;
  knn.Search(dataset, 15, neighborsTree, distancesTree);

  arma::Mat<size_t> neighborsNaive;
  arma::mat distancesNaive;
  naive.Search(dataset, 15, neighborsNaive, distancesNaive);

  for (size_t i = 0; i < neighborsTree.n_elem; i++)
  {
    BOOST_REQUIRE_EQUAL(neighborsTree(i), neighborsNaive(i));
    BOOST_REQUIRE_CLOSE(distancesTree(i), distancesNaive(i), 1e-5);
  }
}