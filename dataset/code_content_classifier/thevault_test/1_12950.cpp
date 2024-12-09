BOOST_AUTO_TEST_CASE(LogisticRegressionSparseSGDTest)
{
  // Create a random dataset.
  arma::sp_mat dataset;
  dataset.sprandu(10, 800, 0.3);
  arma::mat denseDataset(dataset);
  arma::Row<size_t> labels(800);
  for (size_t i = 0; i < 800; ++i)
    labels[i] = math::RandInt(0, 2);

  LogisticRegression<> lr(10, 0.3);
  ens::SGD<> sgd;
  sgd.Shuffle() = false;
  lr.Train(denseDataset, labels, sgd);

  LogisticRegression<arma::sp_mat> lrSparse(10, 0.3);
  ens::SGD<> sgdSparse;
  sgdSparse.Shuffle() = false;
  lrSparse.Train(dataset, labels, sgdSparse);

  BOOST_REQUIRE_EQUAL(lr.Parameters().n_elem, lrSparse.Parameters().n_elem);
  for (size_t i = 0; i < lr.Parameters().n_elem; ++i)
    BOOST_REQUIRE_CLOSE(lr.Parameters()[i], lrSparse.Parameters()[i], 1e-5);
}