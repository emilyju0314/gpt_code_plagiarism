BOOST_AUTO_TEST_CASE(MoveOperatorNaiveTest)
{
  arma::mat dataset = arma::randu<arma::mat>(5, 500);
  KNN* knn = new KNN(std::move(dataset), NAIVE_MODE);

  // Get predictions.
  arma::mat distances, distances2;
  arma::Mat<size_t> neighbors, neighbors2;

  knn->Search(3, neighbors, distances);

  // Use move constructor.
  KNN knn2 = std::move(*knn);

  delete knn;

  BOOST_REQUIRE_EQUAL(knn2.SearchMode(), NAIVE_MODE);

  knn2.Search(3, neighbors2, distances2);

  CheckMatrices(neighbors, neighbors2);
  CheckMatrices(distances, distances2);
}