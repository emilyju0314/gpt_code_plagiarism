TEST(TestSuite, discrete_prior_factor) {
  // Make an empty discrete factor graph
  gtsam::DiscreteFactorGraph dfg;

  // We'll make a variable with 2 possible assignments
  const size_t cardinality = 2;
  gtsam::DiscreteKey dk(gtsam::Symbol('d', 1), cardinality);
  const std::vector<double> probs{0.1, 0.9};

  // Make a discrete prior factor and add it to the graph
  DiscretePriorFactor dpf(dk, probs);
  dfg.push_back(dpf);

  // Solve
  gtsam::DiscreteFactor::sharedValues mostProbableEstimate = dfg.optimize();

  // Get the most probable estimate
  size_t mpeD = (*mostProbableEstimate).at(dk.first);

  // Get the marginals
  gtsam::DiscreteMarginals discreteMarginals(dfg);
  gtsam::Vector margProbs = discreteMarginals.marginalProbabilities(dk);

  // Verify that each marginal probability is within `tol` of the true marginal
  for (size_t i = 0; i < dk.second; i++) {
    bool margWithinTol = (abs(margProbs[i] - probs[i]) < tol);
    EXPECT_EQ(margWithinTol, true);
  }

  // Ensure that the most probable estimate is correct
  EXPECT_EQ(mpeD, 1);
}