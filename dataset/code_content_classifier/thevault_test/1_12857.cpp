BOOST_AUTO_TEST_CASE(DoubleReferenceSearchTest)
{
  arma::mat dataset = arma::randu<arma::mat>(5, 500);
  KNN knn(std::move(dataset));

  arma::mat distances, secondDistances;
  arma::Mat<size_t> neighbors, secondNeighbors;
  knn.Search(3, neighbors, distances);
  size_t baseCases = knn.BaseCases();
  size_t scores = knn.Scores();

  knn.Search(3, secondNeighbors, secondDistances);

  BOOST_REQUIRE_EQUAL(knn.BaseCases(), baseCases);
  BOOST_REQUIRE_EQUAL(knn.Scores(), scores);
}