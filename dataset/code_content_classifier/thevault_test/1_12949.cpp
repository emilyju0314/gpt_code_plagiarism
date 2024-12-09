BOOST_AUTO_TEST_CASE(LogisticRegressionSparseLBFGSTest)
{
  // Create a random dataset.
  arma::sp_mat dataset;
  dataset.sprandu(10, 800, 0.3);
  arma::mat denseDataset(dataset);
  arma::Row<size_t> labels(800);
  for (size_t i = 0; i < 800; ++i)
    labels[i] = math::RandInt(0, 2);

  LogisticRegression<> lr(denseDataset, labels, 0.3);
  LogisticRegression<arma::sp_mat> lrSparse(dataset, labels, 0.3);

  BOOST_REQUIRE_EQUAL(lr.Parameters().n_elem, lrSparse.Parameters().n_elem);
  for (size_t i = 0; i < lr.Parameters().n_elem; ++i)
    BOOST_REQUIRE_CLOSE(lr.Parameters()[i], lrSparse.Parameters()[i], 5e-4);
}