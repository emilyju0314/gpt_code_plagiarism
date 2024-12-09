BOOST_AUTO_TEST_CASE(SparseKNNKDTreeTest)
{
  // The dimensionality of these datasets must be high so that the probability
  // of a completely empty point is very low.  In this case, with dimensionality
  // 70, the probability of all 70 dimensions being zero is 0.8^70 = 1.65e-7 in
  // the reference set and 0.9^70 = 6.27e-4 in the query set.
  arma::sp_mat queryDataset;
  queryDataset.sprandu(70, 200, 0.2);
  arma::sp_mat referenceDataset;
  referenceDataset.sprandu(70, 500, 0.1);
  arma::mat denseQuery(queryDataset);
  arma::mat denseReference(referenceDataset);

  typedef NeighborSearch<NearestNeighborSort, EuclideanDistance, arma::sp_mat,
      KDTree> SparseKNN;

  SparseKNN a(referenceDataset);
  KNN naive(denseReference, NAIVE_MODE);

  arma::mat sparseDistances;
  arma::Mat<size_t> sparseNeighbors;
  a.Search(queryDataset, 10, sparseNeighbors, sparseDistances);

  arma::mat naiveDistances;
  arma::Mat<size_t> naiveNeighbors;
  naive.Search(denseQuery, 10, naiveNeighbors, naiveDistances);

  for (size_t i = 0; i < naiveNeighbors.n_cols; ++i)
  {
    for (size_t j = 0; j < naiveNeighbors.n_rows; ++j)
    {
      BOOST_REQUIRE_EQUAL(naiveNeighbors(j, i), sparseNeighbors(j, i));
      BOOST_REQUIRE_CLOSE(naiveDistances(j, i), sparseDistances(j, i), 1e-5);
    }
  }
}