BOOST_AUTO_TEST_CASE(HybridSpillSearchTest)
{
  arma::mat dataset;
  dataset.randu(50, 300); // 50 dimensional, 300 points.

  const size_t k = 3;

  KNN naive(dataset);
  arma::Mat<size_t> neighborsNaive;
  arma::mat distancesNaive;
  naive.Search(dataset, k, neighborsNaive, distancesNaive);

  double maxDist = 0;
  for (size_t i = 0; i < neighborsNaive.n_cols; ++i)
    if (distancesNaive(k - 1, i) > maxDist)
      maxDist = distancesNaive(k - 1, i);

  // If we are sure that tau is a valid strict upper bound of the kth nearest
  // neighbor of the query points, then we can be sure that we will get an exact
  // solution.
  SpillKNN::Tree referenceTree(dataset, maxDist * 1.01 /* tau parameter */);
  SpillKNN spTreeSearch(std::move(referenceTree));

  for (size_t mode = 0; mode < 2; mode++)
  {
    if (mode)
      spTreeSearch.SearchMode() = SINGLE_TREE_MODE;

    arma::Mat<size_t> neighborsSPTree;
    arma::mat distancesSPTree;
    spTreeSearch.Search(dataset, k, neighborsSPTree, distancesSPTree);

    for (size_t i = 0; i < neighborsSPTree.n_elem; ++i)
    {
      BOOST_REQUIRE_EQUAL(neighborsSPTree(i), neighborsNaive(i));
      BOOST_REQUIRE_CLOSE(distancesSPTree(i), distancesNaive(i), 1e-5);
    }
  }
}