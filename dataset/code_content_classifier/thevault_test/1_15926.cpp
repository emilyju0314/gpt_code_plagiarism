BOOST_AUTO_TEST_CASE(NoAlphaDropoutTest)
{
  arma::mat input = arma::ones(1500, 1);
  AlphaDropout<> module(0);
  module.Deterministic() = false;

  arma::mat output;
  module.Forward(input, output);

  BOOST_REQUIRE_EQUAL(arma::accu(output), arma::accu(input));
}