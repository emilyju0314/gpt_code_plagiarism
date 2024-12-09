BOOST_AUTO_TEST_CASE(BatchNormTest)
{
  arma::mat input, output;
  input << 5.1 << 3.5 << 1.4 << arma::endr
        << 4.9 << 3.0 << 1.4 << arma::endr
        << 4.7 << 3.2 << 1.3 << arma::endr;

  BatchNorm<> model(input.n_rows);
  model.Reset();

  // Non-Deteministic Forward Pass Test.
  model.Deterministic() = false;
  model.Forward(input, output);
  arma::mat result;
  result << 1.1658 << 0.1100 << -1.2758 << arma::endr
         << 1.2579 << -0.0699 << -1.1880 << arma::endr
         << 1.1737 << 0.0958 << -1.2695 << arma::endr;

  CheckMatrices(output, result, 1e-1);
  result.clear();

  // Deterministic Forward Pass test.
  output = model.TrainingMean();
  result << 3.33333333 << arma::endr
         << 3.1 << arma::endr
         << 3.06666666 << arma::endr;

  CheckMatrices(output, result, 1e-1);
  result.clear();

  output = model.TrainingVariance();
  result << 2.2956 << arma::endr
         << 2.0467 << arma::endr
         << 1.9356 << arma::endr;

  CheckMatrices(output, result, 1e-1);
  result.clear();

  model.Deterministic() = true;
  model.Forward(input, output);

  result << 1.1658 << 0.1100 << -1.2757 << arma::endr
         << 1.2579 << -0.0699 << -1.1880 << arma::endr
         << 1.1737 << 0.0958 << -1.2695 << arma::endr;

  CheckMatrices(output, result, 1e-1);
}