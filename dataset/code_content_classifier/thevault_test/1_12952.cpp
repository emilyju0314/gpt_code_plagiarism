BOOST_AUTO_TEST_CASE(ClassifyProbabilitiesTest)
{
  // Generate a two-Gaussian dataset.
  GaussianDistribution g1(arma::vec("1.0 1.0 1.0"), arma::eye<arma::mat>(3, 3));
  GaussianDistribution g2(arma::vec("9.0 9.0 9.0"), arma::eye<arma::mat>(3, 3));

  arma::mat data(3, 1000);
  arma::Row<size_t> responses(1000);
  for (size_t i = 0; i < 500; ++i)
  {
    data.col(i) = g1.Random();
    responses[i] = 0;
  }
  for (size_t i = 500; i < 1000; ++i)
  {
    data.col(i) = g2.Random();
    responses[i] = 1;
  }

  // Now train a logistic regression object on it.
  LogisticRegression<> lr(data.n_rows, 0.5);
  lr.Train<>(data, responses);

  // Create a test set.
  for (size_t i = 0; i < 500; ++i)
  {
    data.col(i) = g1.Random();
    responses[i] = 0;
  }
  for (size_t i = 500; i < 1000; ++i)
  {
    data.col(i) = g2.Random();
    responses[i] = 1;
  }

  arma::mat probabilities;
  lr.Classify(data, probabilities);

  BOOST_REQUIRE_EQUAL(probabilities.n_cols, data.n_cols);
  BOOST_REQUIRE_EQUAL(probabilities.n_rows, 2);

  for (size_t i = 0; i < data.n_cols; ++i)
  {
    BOOST_REQUIRE_CLOSE(probabilities(0, i) + probabilities(1, i), 1.0, 1e-5);

    // 10% tolerance.
    if (responses[i] == 0)
      BOOST_REQUIRE_CLOSE(probabilities(0, i), 1.0, 10.0);
    else
      BOOST_REQUIRE_CLOSE(probabilities(1, i), 1.0, 10.0);
  }
}