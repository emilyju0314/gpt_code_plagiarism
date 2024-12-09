BOOST_AUTO_TEST_CASE(TrainTest)
{
  KNN empty;

  arma::mat dataset = arma::randu<arma::mat>(5, 100);
  KNN baseline(dataset);

  arma::Mat<size_t> neighbors, baselineNeighbors;
  arma::mat distances, baselineDistances;

  empty.Train(dataset);

  empty.Search(5, neighbors, distances);
  baseline.Search(5, baselineNeighbors, baselineDistances);

  BOOST_REQUIRE_EQUAL(neighbors.n_rows, baselineNeighbors.n_rows);
  BOOST_REQUIRE_EQUAL(neighbors.n_cols, baselineNeighbors.n_cols);
  BOOST_REQUIRE_EQUAL(distances.n_rows, baselineDistances.n_rows);
  BOOST_REQUIRE_EQUAL(distances.n_cols, baselineDistances.n_cols);

  for (size_t i = 0; i < distances.n_elem; ++i)
  {
    if (std::abs(baselineDistances[i]) < 1e-5)
      BOOST_REQUIRE_SMALL(distances[i], 1e-5);
    else
      BOOST_REQUIRE_CLOSE(distances[i], baselineDistances[i], 1e-5);

    BOOST_REQUIRE_EQUAL(neighbors[i], baselineNeighbors[i]);
  }
}