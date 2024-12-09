BOOST_AUTO_TEST_CASE(DuplicatedSpillSearchTest)
{
  arma::mat dataset;
  dataset.randu(50, 300); // 50 dimensional, 300 points.

  const size_t k = 15;

  for (size_t test = 0; test < 2; test++)
  {
    double tau = test * 0.1;

    SpillKNN::Tree referenceTree(dataset, tau);
    SpillKNN spTreeSearch(std::move(referenceTree));

    arma::Mat<size_t> neighborsSPTree;
    arma::mat distancesSPTree;

    for (size_t mode = 0; mode < 2; mode++)
    {
      if (mode)
        spTreeSearch.SearchMode() = SINGLE_TREE_MODE;

      spTreeSearch.Search(dataset, k, neighborsSPTree, distancesSPTree);

      for (size_t i = 0; i < neighborsSPTree.n_cols; ++i)
      {
        // Test that at least one point was found.
        BOOST_REQUIRE(distancesSPTree(0, i) != DBL_MAX);

        for (size_t j = 0; j < neighborsSPTree.n_rows; ++j)
        {
          if (distancesSPTree(j, i) == DBL_MAX)
            break;
          // All candidates with same distances must be different points.
          for (size_t k = j + 1; k < neighborsSPTree.n_rows &&
              distancesSPTree(k, i) == distancesSPTree(j, i); ++k)
            BOOST_REQUIRE(neighborsSPTree(k, i) != neighborsSPTree(j, i));
        }
      }
    }
  }
}