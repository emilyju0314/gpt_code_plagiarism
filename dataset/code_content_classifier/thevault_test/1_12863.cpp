BOOST_AUTO_TEST_CASE(GreedyTreeSearch)
{
  // Initalize dataset.
  arma::mat dataset = arma::randu<arma::mat>(3, 100);

  // Build tree with a leaf_size of 1.
  KDTree<EuclideanDistance, NeighborSearchStat<NearestNeighborSort>,
      arma::mat> tree(dataset, 1);

  NeighborSearch<NearestNeighborSort, LMetric<2>, arma::mat, KDTree>
      greedyTreeSearch(std::move(tree), GREEDY_SINGLE_TREE_MODE);

  arma::Mat<size_t> neighbors;
  arma::mat distances;

  // Search for 5 nearest neighbours.
  greedyTreeSearch.Search(5, neighbors, distances);

  // Check that all neighbour values are between 0 and 100, as only 100 points
  // are present in dataset.
  BOOST_REQUIRE_EQUAL(arma::accu(neighbors < 0 || neighbors >= 100), 0);

  // Check that all distances values are between 0.0 and 1.0 as arma::randu
  // generates a uniform distribution in [0, 1].
  BOOST_REQUIRE_EQUAL(arma::accu(distances < 0.0 || distances > std::sqrt(3.0)),
      0);
}