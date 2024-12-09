BOOST_AUTO_TEST_CASE(CopyConstructorAndOperatorNaiveTest)
{
  arma::mat dataset = arma::randu<arma::mat>(5, 50);
  KNN knn(std::move(dataset), NAIVE_MODE);

  // Copy constructor and operator.
  KNN knn2(knn);
  KNN knn3 = knn;

  BOOST_REQUIRE_EQUAL(knn2.SearchMode(), NAIVE_MODE);
  BOOST_REQUIRE_EQUAL(knn3.SearchMode(), NAIVE_MODE);

  // Get results.
  arma::mat distances, distances2, distances3;
  arma::Mat<size_t> neighbors, neighbors2, neighbors3;

  knn.Search(3, neighbors, distances);
  knn2.Search(3, neighbors2, distances2);
  knn3.Search(3, neighbors3, distances3);

  CheckMatrices(neighbors, neighbors2);
  CheckMatrices(neighbors, neighbors3);
  CheckMatrices(distances, distances2);
  CheckMatrices(distances, distances3);
}