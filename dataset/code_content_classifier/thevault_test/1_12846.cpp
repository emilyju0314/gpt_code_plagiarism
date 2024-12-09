BOOST_AUTO_TEST_CASE(MoveTrainTest)
{
  arma::mat dataset = arma::randu<arma::mat>(3, 200);

  // Do it in tree mode, and in naive mode.
  KNN knn;
  knn.Train(std::move(dataset));

  arma::mat distances;
  arma::Mat<size_t> neighbors;
  knn.Search(1, neighbors, distances);

  BOOST_REQUIRE_EQUAL(dataset.n_elem, 0);
  BOOST_REQUIRE_EQUAL(neighbors.n_cols, 200);
  BOOST_REQUIRE_EQUAL(distances.n_cols, 200);

  dataset = arma::randu<arma::mat>(3, 300);
  knn.SearchMode() = NAIVE_MODE;
  knn.Train(std::move(dataset));
  knn.Search(1, neighbors, distances);

  BOOST_REQUIRE_EQUAL(dataset.n_elem, 0);
  BOOST_REQUIRE_EQUAL(neighbors.n_cols, 300);
  BOOST_REQUIRE_EQUAL(distances.n_cols, 300);
}