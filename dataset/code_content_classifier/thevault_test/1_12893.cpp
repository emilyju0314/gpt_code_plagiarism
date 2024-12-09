BOOST_AUTO_TEST_CASE(TrainingConstructorWithNonDefaultsTest)
{
  arma::mat X;
  arma::rowvec y;

  GenerateProblem(X, y, 1000, 100);

  bool transposeData = true;
  bool useCholesky = true;
  double lambda1 = 0.2;
  double lambda2 = 0.4;

  LARS lars1(useCholesky, lambda1, lambda2);
  arma::vec beta;
  lars1.Train(X, y, beta);

  LARS lars2(X, y, transposeData, useCholesky, lambda1, lambda2);

  BOOST_REQUIRE_EQUAL(beta.n_elem, lars2.Beta().n_elem);
  for (size_t i = 0; i < beta.n_elem; ++i)
    BOOST_REQUIRE_CLOSE(beta[i], lars2.Beta()[i], 1e-5);
}