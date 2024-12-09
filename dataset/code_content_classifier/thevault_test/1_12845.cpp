BOOST_AUTO_TEST_CASE(DatasetMoveConstructorTest)
{
  arma::mat dataset = arma::randu<arma::mat>(3, 200);
  arma::mat copy(dataset);

  KNN moveknn(std::move(copy));
  KNN knn(dataset);

  BOOST_REQUIRE_EQUAL(copy.n_elem, 0);
  BOOST_REQUIRE_EQUAL(moveknn.ReferenceSet().n_rows, 3);
  BOOST_REQUIRE_EQUAL(moveknn.ReferenceSet().n_cols, 200);

  arma::mat moveDistances, distances;
  arma::Mat<size_t> moveNeighbors, neighbors;

  moveknn.Search(1, moveNeighbors, moveDistances);
  knn.Search(1, neighbors, distances);

  BOOST_REQUIRE_EQUAL(moveNeighbors.n_rows, neighbors.n_rows);
  BOOST_REQUIRE_EQUAL(moveNeighbors.n_cols, neighbors.n_cols);
  BOOST_REQUIRE_EQUAL(moveDistances.n_rows, distances.n_rows);
  BOOST_REQUIRE_EQUAL(moveDistances.n_cols, distances.n_cols);
  for (size_t i = 0; i < moveDistances.n_elem; ++i)
  {
    BOOST_REQUIRE_EQUAL(moveNeighbors[i], neighbors[i]);
    if (std::abs(distances[i]) < 1e-5)
      BOOST_REQUIRE_SMALL(moveDistances[i], 1e-5);
    else
      BOOST_REQUIRE_CLOSE(moveDistances[i], distances[i], 1e-5);
  }
}