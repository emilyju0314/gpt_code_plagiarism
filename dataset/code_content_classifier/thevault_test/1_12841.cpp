BOOST_AUTO_TEST_CASE(EmptySearchTest)
{
  KNN empty;

  arma::mat dataset = arma::randu<arma::mat>(5, 100);
  KNN::Tree queryTree(dataset);
  arma::Mat<size_t> neighbors;
  arma::mat distances;

  BOOST_REQUIRE_THROW(empty.Search(dataset, 5, neighbors, distances),
      std::invalid_argument);
  BOOST_REQUIRE_THROW(empty.Search(5, neighbors, distances),
      std::invalid_argument);
  BOOST_REQUIRE_THROW(empty.Search(queryTree, 5, neighbors, distances),
      std::invalid_argument);
}