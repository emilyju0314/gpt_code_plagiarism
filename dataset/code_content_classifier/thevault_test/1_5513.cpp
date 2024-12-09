TEST(TestSuite, dcdiscrete_mixture) {
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

  // Let's make an initial guess for the continuous values
  gtsam::Values initialGuess;
  double initVal = -2.5;
  initialGuess.insert(x1, initVal);

  // We also need an initial guess for the discrete variables (this will only be
  // used if it is needed by your factors), here it is ignored.
  DiscreteValues initialGuessDiscrete;
  initialGuessDiscrete[dk.first] = 0;

  // Let's make a discrete factor graph
  gtsam::DiscreteFactorGraph dfg;

  // Pack DCMixture into a DCDiscreteFactor
  for (auto& it : dcfg) {
    DCDiscreteFactor dcDiscrete(it->discreteKeys()[0], it);
    dfg.push_back(dcDiscrete);
  }

  // Update continuous info
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

  // Get the marginals
  gtsam::DiscreteMarginals newDiscreteMarginals(dfg);
  gtsam::Vector newMargProbs = newDiscreteMarginals.marginalProbabilities(dk);

  // Ensure that the prediction is correct
  EXPECT_EQ(mpeD, 1);
}