BOOST_AUTO_TEST_CASE(TrainingAndAccessingBetaTest)
{
  arma::mat X;
  arma::rowvec y;

  GenerateProblem(X, y, 1000, 100);

  LARS lars1;
  arma::vec beta;
  lars1.Train(X, y, beta);

  LARS lars2;
  lars2.Train(X, y);

  BOOST_REQUIRE_EQUAL(beta.n_elem, lars2.Beta().n_elem);
  for (size_t i = 0; i < beta.n_elem; ++i)
    BOOST_REQUIRE_CLOSE(beta[i], lars2.Beta()[i], 1e-5);
}