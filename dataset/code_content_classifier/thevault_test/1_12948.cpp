BOOST_AUTO_TEST_CASE(LogisticRegressionSGDTrainTest)
{
  // Make a random dataset with random labels.
  arma::mat dataset(5, 800);
  dataset.randu();
  arma::Row<size_t> labels(800);
  for (size_t i = 0; i < 800; ++i)
    labels[i] = math::RandInt(0, 2);

  ens::SGD<> sgd;
  sgd.Shuffle() = false;
  LogisticRegression<> lr(dataset, labels, sgd, 0.3);

  ens::SGD<> sgd2;
  sgd2.Shuffle() = false;
  LogisticRegression<> lr2(dataset.n_rows, 0.3);
  lr2.Train(dataset, labels, sgd2);

  BOOST_REQUIRE_EQUAL(lr.Parameters().n_elem, lr2.Parameters().n_elem);
  for (size_t i = 0; i < lr.Parameters().n_elem; ++i)
    BOOST_REQUIRE_CLOSE(lr.Parameters()[i], lr2.Parameters()[i], 1e-5);
}