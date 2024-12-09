TEST(TestSuite, simple_mixture_factor) {
  // We'll make a variable with 2 possible assignments
  const size_t cardinality = 2;
  gtsam::DiscreteKey dk(gtsam::Symbol('d', 1), cardinality);

  // Make a symbol for a single continuous variable and add to KeyVector
  gtsam::Symbol x1 = gtsam::Symbol('x', 1);
  gtsam::KeyVector keys;
  keys.push_back(x1);

  // Make a factor for non-null hypothesis
  double loc = 0.0;
  double sigma1 = 1.0;
  gtsam::noiseModel::Isotropic::shared_ptr prior_noise1 =
      gtsam::noiseModel::Isotropic::Sigma(1, sigma1);
  gtsam::PriorFactor<double> f1(x1, loc, prior_noise1);

  // Make a factor for null hypothesis
  double sigmaNullHypo = 8.0;
  gtsam::noiseModel::Isotropic::shared_ptr prior_noiseNullHypo =
      gtsam::noiseModel::Isotropic::Sigma(1, sigmaNullHypo);

  gtsam::PriorFactor<double> fNullHypo(x1, loc, prior_noiseNullHypo);
  std::vector<gtsam::PriorFactor<double>> factorComponents{f1, fNullHypo};

  DCMixtureFactor<gtsam::PriorFactor<double>> dcMixture(keys, dk,
                                                        factorComponents);

  // Make an empty hybrid factor graph
  HybridFactorGraph hfg;

  hfg.push_dc(dcMixture);

  gtsam::DiscreteKey dkTest = dcMixture.discreteKeys()[0];
  std::cout << "DK 1st: " << dkTest.first << std::endl;
  std::cout << "DK 2nd: " << dkTest.second << std::endl;

  // Plot the cost functions for each hypothesis
#ifdef ENABLE_PLOTTING
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

  // Let's make an initial guess
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

  // Let's make a solver
  DCSAM dcsam;

  // Add the HybridFactorGraph to DCSAM
  dcsam.update(hfg, initialGuess, initialGuessDiscrete);

  // Solve
  DCValues dcvals = dcsam.calculateEstimate();

  // Run another iteration
  dcsam.update();

  // Update DCVals
  dcvals = dcsam.calculateEstimate();

  // And add it to the plot
#ifdef ENABLE_PLOTTING
  std::vector<double> updatedVec{dcvals.continuous.at<double>(x1)};
  std::vector<double> updatedError1{dcMixture.error(dcvals.continuous, dv1)};
  std::vector<double> updatedErrorNH{dcMixture.error(dcvals.continuous, dvNH)};

  plt::scatter(updatedVec, updatedError1, {{"color", "b"}});
  plt::scatter(updatedVec, updatedErrorNH, {{"color", "b"}});
  plt::show();
#endif

#ifdef ENABLE_PLOTTING
  plt::show();
#endif

  // Ensure that the prediction is correct
  size_t mpeD = dcvals.discrete.at(dk.first);
  EXPECT_EQ(mpeD, 0);
}