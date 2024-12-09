TEST(TestSuite, simple_discrete_dcsam) {
  // Create a DCSAM instance
  DCSAM dcsam;

  // Make an empty hybrid factor graph
  HybridFactorGraph hfg;

  // We'll make a variable with 2 possible assignments
  const size_t cardinality = 2;
  gtsam::DiscreteKey dk(gtsam::Symbol('d', 1), cardinality);
  const std::vector<double> probs{0.1, 0.9};

  // Make a discrete prior factor and add it to the graph
  DiscretePriorFactor dpf(dk, probs);
  hfg.push_discrete(dpf);

  // Initial guess for discrete values (only used in certain circumstances)
  DiscreteValues initialGuessDiscrete;
  initialGuessDiscrete[dk.first] = 1;

  // Update DCSAM with the new factor
  dcsam.update(hfg, initialGuessDiscrete);

  // Solve
  DCValues dcvals = dcsam.calculateEstimate();

  // Get the most probable estimate
  size_t mpeD = dcvals.discrete.at(dk.first);

  // Ensure that the prediction is correct
  EXPECT_EQ(mpeD, 1);
}