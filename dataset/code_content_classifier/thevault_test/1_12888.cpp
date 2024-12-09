BOOST_AUTO_TEST_CASE(PredictTest)
{
  for (size_t i = 0; i < 2; ++i)
  {
    // Run with both true and false.
    bool useCholesky = bool(i);

    arma::mat X;
    arma::rowvec y;

    GenerateProblem(X, y, 1000, 100);

    for (double lambda1 = 0.0; lambda1 < 1.0; lambda1 += 0.2)
    {
      for (double lambda2 = 0.0; lambda2 < 1.0; lambda2 += 0.2)
      {
        LARS lars(useCholesky, lambda1, lambda2);
        arma::vec betaOpt;
        lars.Train(X, y, betaOpt);

        // Calculate what the actual error should be with these regression
        // parameters.
        arma::vec betaOptPred = (X * X.t()) * betaOpt;
        arma::rowvec predictions;
        lars.Predict(X, predictions);
        arma::vec adjPred = X * predictions.t();

        BOOST_REQUIRE_EQUAL(predictions.n_elem, 1000);
        for (size_t i = 0; i < betaOptPred.n_elem; ++i)
        {
          if (std::abs(betaOptPred[i]) < 1e-5)
            BOOST_REQUIRE_SMALL(adjPred[i], 1e-5);
          else
            BOOST_REQUIRE_CLOSE(adjPred[i], betaOptPred[i], 1e-5);
        }
      }
    }
  }
}