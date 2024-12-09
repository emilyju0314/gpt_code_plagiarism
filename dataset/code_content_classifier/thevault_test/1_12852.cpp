BOOST_AUTO_TEST_CASE(SingleBallTreeTest)
{
  arma::mat data;
  data.randu(50, 300); // 50 dimensional, 300 points.

  typedef BallTree<EuclideanDistance, NeighborSearchStat<NearestNeighborSort>,
      arma::mat> TreeType;
  TreeType tree(data);

  KNN naive(tree.Dataset(), NAIVE_MODE);

  // BinarySpaceTree modifies data. Use modified data to maintain the
  // correspondance between points in the dataset for both methods. The order of
  // query points in both methods should be same.

  NeighborSearch<NearestNeighborSort, EuclideanDistance, arma::mat, BallTree>
      ballTreeSearch(std::move(tree), SINGLE_TREE_MODE);

  arma::Mat<size_t> ballTreeNeighbors;
  arma::mat ballTreeDistances;
  ballTreeSearch.Search(2, ballTreeNeighbors, ballTreeDistances);

  arma::Mat<size_t> naiveNeighbors;
  arma::mat naiveDistances;
  naive.Search(2, naiveNeighbors, naiveDistances);

  for (size_t i = 0; i < ballTreeNeighbors.n_elem; ++i)
  {
    BOOST_REQUIRE_EQUAL(ballTreeNeighbors[i], naiveNeighbors[i]);
    BOOST_REQUIRE_CLOSE(ballTreeDistances[i], naiveDistances[i], 1e-5);
  }
}