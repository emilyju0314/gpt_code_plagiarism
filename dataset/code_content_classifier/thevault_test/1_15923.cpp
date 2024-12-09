BOOST_AUTO_TEST_CASE(NoDropoutTest)
{
  arma::mat input = arma::ones(1500, 1);
  Dropout<> module(0);
  module.Deterministic() = false;

  arma::mat output;
  module.Forward(input, output);

  BOOST_REQUIRE_EQUAL(arma::accu(output), arma::accu(input));
}