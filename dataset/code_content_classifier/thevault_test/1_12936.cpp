BOOST_AUTO_TEST_CASE(LogisticRegressionSeparableEvaluate)
{
  // Very simple fake dataset.
  arma::mat data("1 2 3;"
                 "1 2 3;");
  arma::Row<size_t> responses("1 1 0");

  // Create a LogisticRegressionFunction.
  LogisticRegressionFunction<> lrf(data, responses,
      0.0 /* no regularization */);

  // These were hand-calculated using Octave.
  BOOST_REQUIRE_CLOSE(lrf.Evaluate(arma::rowvec("1 1 1"), 0, 1), 4.85873516e-2,
      1e-5);
  BOOST_REQUIRE_CLOSE(lrf.Evaluate(arma::rowvec("1 1 1"), 1, 1), 6.71534849e-3,
      1e-5);
  BOOST_REQUIRE_CLOSE(lrf.Evaluate(arma::rowvec("1 1 1"), 2, 1), 7.00091146645,
      1e-5);

  BOOST_REQUIRE_CLOSE(lrf.Evaluate(arma::rowvec("0 0 0"), 0, 1), 0.6931471805,
      1e-5);
  BOOST_REQUIRE_CLOSE(lrf.Evaluate(arma::rowvec("0 0 0"), 1, 1), 0.6931471805,
      1e-5);
  BOOST_REQUIRE_CLOSE(lrf.Evaluate(arma::rowvec("0 0 0"), 2, 1), 0.6931471805,
      1e-5);

  BOOST_REQUIRE_CLOSE(lrf.Evaluate(arma::rowvec("-1 -1 -1"), 0, 1),
      3.0485873516, 1e-5);
  BOOST_REQUIRE_CLOSE(lrf.Evaluate(arma::rowvec("-1 -1 -1"), 1, 1),
      5.0067153485, 1e-5);
  BOOST_REQUIRE_CLOSE(lrf.Evaluate(arma::rowvec("-1 -1 -1"), 2, 1),
      9.1146645377e-4, 1e-5);

  BOOST_REQUIRE_SMALL(lrf.Evaluate(arma::rowvec("200 -40 -40"), 0, 1), 1e-5);
  BOOST_REQUIRE_SMALL(lrf.Evaluate(arma::rowvec("200 -40 -40"), 1, 1), 1e-5);
  BOOST_REQUIRE_SMALL(lrf.Evaluate(arma::rowvec("200 -40 -40"), 2, 1), 1e-5);

  BOOST_REQUIRE_SMALL(lrf.Evaluate(arma::rowvec("200 -80 0"), 0, 1), 1e-5);
  BOOST_REQUIRE_SMALL(lrf.Evaluate(arma::rowvec("200 -80 0"), 1, 1), 1e-5);
  BOOST_REQUIRE_SMALL(lrf.Evaluate(arma::rowvec("200 -80 0"), 2, 1), 1e-5);

  BOOST_REQUIRE_SMALL(lrf.Evaluate(arma::rowvec("200 -100 20"), 0, 1), 1e-5);
  BOOST_REQUIRE_SMALL(lrf.Evaluate(arma::rowvec("200 -100 20"), 1, 1), 1e-5);
  BOOST_REQUIRE_SMALL(lrf.Evaluate(arma::rowvec("200 -100 20"), 2, 1), 1e-5);
}