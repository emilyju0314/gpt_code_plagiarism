BOOST_AUTO_TEST_CASE(NaiveTrainTreeTest)
{
  KNN empty(NAIVE_MODE);

  arma::mat dataset = arma::randu<arma::mat>(5, 100);
  KNN::Tree tree(dataset);

  BOOST_REQUIRE_THROW(empty.Train(std::move(tree)), std::invalid_argument);
}