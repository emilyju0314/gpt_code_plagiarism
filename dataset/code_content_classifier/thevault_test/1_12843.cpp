BOOST_AUTO_TEST_CASE(TrainTreeTest)
{
  KNN empty;

  arma::mat dataset = arma::randu<arma::mat>(5, 100);
  KNN baseline(dataset);

  arma::Mat<size_t> neighbors, baselineNeighbors;
  arma::mat distances, baselineDistances;

  std::vector<size_t> oldFromNewReferences;
  KNN::Tree tree(dataset, oldFromNewReferences);
  empty.Train(std::move(tree));

  empty.Search(5, neighbors, distances);
  baseline.Search(5, baselineNeighbors, baselineDistances);

  BOOST_REQUIRE_EQUAL(neighbors.n_rows, baselineNeighbors.n_rows);
  BOOST_REQUIRE_EQUAL(neighbors.n_cols, baselineNeighbors.n_cols);
  BOOST_REQUIRE_EQUAL(distances.n_rows, baselineDistances.n_rows);
  BOOST_REQUIRE_EQUAL(distances.n_cols, baselineDistances.n_cols);

  // We have to unmap the results.
  arma::mat tmpDistances(distances.n_rows, distances.n_cols);
  arma::Mat<size_t> tmpNeighbors(neighbors.n_rows, neighbors.n_cols);
  for (size_t i = 0; i < distances.n_cols; ++i)
  {
    tmpDistances.col(oldFromNewReferences[i]) = distances.col(i);
    for (size_t j = 0; j < distances.n_rows; ++j)
    {
      tmpNeighbors(j, oldFromNewReferences[i]) =
          oldFromNewReferences[neighbors(j, i)];
    }
  }

  for (size_t i = 0; i < distances.n_elem; ++i)
  {
    if (std::abs(baselineDistances[i]) < 1e-5)
      BOOST_REQUIRE_SMALL(tmpDistances[i], 1e-5);
    else
      BOOST_REQUIRE_CLOSE(tmpDistances[i], baselineDistances[i], 1e-5);

    BOOST_REQUIRE_EQUAL(tmpNeighbors[i], baselineNeighbors[i]);
  }
}