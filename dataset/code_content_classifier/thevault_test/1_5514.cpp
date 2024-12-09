TEST(TestSuite, dccontinuous_mixture) {
  // Make an empty discrete factor graph
  DCFactorGraph dcfg;

  // We'll make a variable with 2 possible assignments
  const size_t cardinality = 2;
  gtsam::DiscreteKey dk(gtsam::Symbol('d', 1), cardinality);

  // Make a symbol for a single continuous variable and add to KeyVector
  gtsam::Symbol x1 = gtsam::Symbol('x', 1);
  gtsam::KeyVector keys;
  keys.push_back(x1);

  // Make a factor for non-null hypothesis
  const double loc = 0.0;
  const double sigma1 = 1.0;
  gtsam::noiseModel::Isotropic::shared_ptr prior_noise1 =
      gtsam::noiseModel::Isotropic::Sigma(1, sigma1);
  gtsam::PriorFactor<double> f1(x1, loc, prior_noise1);

  // Make a factor for null hypothesis
  const double sigmaNullHypo = 8.0;
  gtsam::noiseModel::Isotropic::shared_ptr prior_noiseNullHypo =
      gtsam::noiseModel::Isotropic::Sigma(1, sigmaNullHypo);

  gtsam::PriorFactor<double> fNullHypo(x1, loc, prior_noiseNullHypo);
  std::vector<gtsam::PriorFactor<double>> factorComponents{f1, fNullHypo};

  DCMixtureFactor<gtsam::PriorFactor<double>> dcMixture(keys, dk,
                                                        factorComponents);
  dcfg.push_back(dcMixture);

  gtsam::DiscreteKey dkTest = dcMixture.discreteKeys()[0];
  std::cout << "DK 1st: " << dkTest.first << std::endl;
  std::cout << "DK 2nd: " << dkTest.second << std::endl;

// Plot the cost functions for each hypothesis
#ifdef ENABLE_PLOTTING
  // Query cost function
  std::vector<double> xs = linspace(-5.0, 5.0, 50);
  DiscreteValues dv1, dvNH;
  dv1[dk.first] = 0;
  dvNH[dk.first] = 1;
  std::vector<double> errors1;
  std::vector<double> errorsNH;
  gtsam::Values xvals;
  for (size_t i = 0; i < xs.size(); i++) {
    xvals.insert(x1, xs[i]);
    errors1.push_back(dcMixture.error(xvals, dv1));
    errorsNH.push_back(dcMixture.error(xvals, dvNH));
    xvals.clear();
  }

  plt::plot(xs, errors1);
  plt::plot(xs, errorsNH);
#endif

  // Let's make an initial guess for the continuous values
  gtsam::Values initialGuess;
  double initVal = -2.5;
  initialGuess.insert(x1, initVal);

  // And add it to the plot
#ifdef ENABLE_PLOTTING
  std::vector<double> initVec{initVal};
  std::vector<double> initError1{dcMixture.error(initialGuess, dv1)};
  std::vector<double> initErrorNH{dcMixture.error(initialGuess, dvNH)};

  plt::scatter(initVec, initError1, {{"color", "r"}});
  plt::scatter(initVec, initErrorNH, {{"color", "r"}});
#endif

  // We also need an initial guess for the discrete variables (this will only be
  // used if it is needed by your factors), here it is ignored.
  DiscreteValues initialGuessDiscrete;
  initialGuessDiscrete[dk.first] = 0;

  // Let's make some factor graphs
  gtsam::DiscreteFactorGraph dfg;
  gtsam::NonlinearFactorGraph graph;

  // Pack DCMixture into a DCContinuousFactor
  for (auto& it : dcfg) {
    DCDiscreteFactor dcDiscrete(it);
    DCContinuousFactor dcContinuous(it);
    dfg.push_back(dcDiscrete);
    graph.push_back(dcContinuous);
  }

  // Update continuous info inside DCDiscreteFactor
  for (size_t j = 0; j < dfg.size(); j++) {
    boost::shared_ptr<DCDiscreteFactor> dcDiscreteFactor =
        boost::dynamic_pointer_cast<DCDiscreteFactor>(dfg[j]);
    if (dcDiscreteFactor) {
      dcDiscreteFactor->updateContinuous(initialGuess);
      dcDiscreteFactor->updateDiscrete(initialGuessDiscrete);
    }
  }

  // Solve for discrete given continuous
  gtsam::DiscreteFactor::sharedValues mostProbableEstimate = dfg.optimize();

  // Get the most probable estimate
  size_t mpeD = (*mostProbableEstimate).at(dk.first);

  // From previous test we know this is == 1
  EXPECT_EQ(mpeD, 1);

  // Get the marginals
  gtsam::DiscreteMarginals newDiscreteMarginals(dfg);
  gtsam::Vector newMargProbs = newDiscreteMarginals.marginalProbabilities(dk);

  // Update discrete info inside DCContinuousFactor
  for (size_t j = 0; j < graph.size(); j++) {
    boost::shared_ptr<DCContinuousFactor> dcContinuousFactor =
        boost::dynamic_pointer_cast<DCContinuousFactor>(graph[j]);
    if (dcContinuousFactor)
      dcContinuousFactor->updateDiscrete((*mostProbableEstimate));
  }

  // Setup isam
  gtsam::ISAM2Params isam_params;
  isam_params.relinearizeThreshold = 0.01;
  isam_params.relinearizeSkip = 1;
  isam_params.setOptimizationParams(gtsam::ISAM2DoglegParams());
  gtsam::ISAM2 isam(isam_params);
  isam.update(graph, initialGuess);

  // Solve for updated continuous value
  gtsam::Values values = isam.calculateEstimate();

  // And add it to the plot
#ifdef ENABLE_PLOTTING
  std::vector<double> updatedVec{values.at<double>(x1)};
  std::vector<double> updatedError1{dcMixture.error(values, dv1)};
  std::vector<double> updatedErrorNH{dcMixture.error(values, dvNH)};

  plt::scatter(updatedVec, updatedError1, {{"color", "b"}});
  plt::scatter(updatedVec, updatedErrorNH, {{"color", "b"}});
  plt::show();
#endif

  // Now update the continuous info in the discrete solver
  for (size_t j = 0; j < dfg.size(); j++) {
    boost::shared_ptr<DCDiscreteFactor> dcDiscreteFactor =
        boost::dynamic_pointer_cast<DCDiscreteFactor>(dfg[j]);
    if (dcDiscreteFactor) dcDiscreteFactor->updateContinuous(values);
    // NOTE: we won't updateDiscrete explicitly here anymore, because we don't
    // need to.
  }

  // Re-solve discrete to verify that output has switched
  mostProbableEstimate = dfg.optimize();
  mpeD = (*mostProbableEstimate).at(dk.first);

  // Ensure that the prediction is correct
  EXPECT_EQ(mpeD, 0);
}