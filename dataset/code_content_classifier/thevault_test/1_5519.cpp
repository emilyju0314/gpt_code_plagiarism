TEST(TestSuite, dcsam_initialization) {
  // Make a factor graph.
  HybridFactorGraph hfg;

  // Values for initial guess.
  gtsam::Values initialGuess;
  // Initial guess for discrete variables.
  DiscreteValues initialGuessDiscrete;

  gtsam::Symbol x0('x', 0);
  gtsam::Symbol l1('l', 1);
  gtsam::Symbol lc1('c', 1);

  // Create a discrete key for landmark 1 class with cardinality 2.
  gtsam::DiscreteKey lm1_class(lc1, 2);

  // Set up initial pose
  gtsam::Pose2 pose0(0, 0, 0);

  double prior_sigma = 0.1;
  double meas_sigma = 1.0;
  gtsam::Point2 landmark1(1.0, 1.0);

  /// Noise models for measurements and priors
  // Prior noise for pose and landmarks.
  gtsam::noiseModel::Isotropic::shared_ptr prior_noise =
      gtsam::noiseModel::Isotropic::Sigma(3, prior_sigma);
  gtsam::noiseModel::Isotropic::shared_ptr prior_lm_noise =
      gtsam::noiseModel::Isotropic::Sigma(2, prior_sigma);

  // 0.1 rad std on bearing, 10cm on range.
  gtsam::noiseModel::Isotropic::shared_ptr br_noise =
      gtsam::noiseModel::Isotropic::Sigma(2, 0.1);

  // Landmark 1 initial class estimate.
  std::vector<double> prior_lm1_class;
  prior_lm1_class.push_back(0.9);
  prior_lm1_class.push_back(0.1);

  // Add prior factors to the graph and solve.
  gtsam::PriorFactor<gtsam::Pose2> p0(x0, pose0, prior_noise);
  gtsam::PriorFactor<gtsam::Point2> pl1(l1, landmark1, prior_lm_noise);
  DiscretePriorFactor plc1(lm1_class, prior_lm1_class);

  initialGuess.insert(x0, pose0);
  initialGuess.insert(l1, landmark1);
  // Add initial guess for discrete vars (only used for mixtures)
  initialGuessDiscrete[lm1_class.first] = 0;

  hfg.push_nonlinear(p0);
  hfg.push_discrete(plc1);

  // Setup dcsam
  DCSAM dcsam;
  dcsam.update(hfg, initialGuess, initialGuessDiscrete);

  DCValues dcval_start = dcsam.calculateEstimate();
  std::cout << "Printing first values" << std::endl;
  dcval_start.discrete.print();

  hfg.clear();
  initialGuess.clear();
  initialGuessDiscrete.clear();

  /**
   * Now DCSAM should have an estimate of the continuous values based on the
   * previous solve. We'll add a new DCFactor now which depends on x0 and l1,
   * but does not explicitly initialize them again when the new factor is added.
   */

  // Add bearing-range measurement from pose (x, y, theta) = (0, 0, 0) to
  // landmark (x, y) = (1, 1)
  gtsam::Rot2 bearing = gtsam::Rot2::fromDegrees(45);
  double range = sqrt(2);
  gtsam::BearingRangeFactor<gtsam::Pose2, gtsam::Point2> brfactor(
      x0, l1, bearing, range, br_noise);

  // Set a semantic bearing-range factor up with BR measurement above and
  // semantic measurement equal to the landmark class prior.
  gtsam::KeyVector lm_keys{x0, l1};
  hfg.push_dc(SemanticBearingRangeFactor<gtsam::Pose2, gtsam::Point2>(
      x0, l1, lm1_class, prior_lm1_class, bearing, range, br_noise));

  // If DCSAM isn't initializing `x0` and `l1` properly for the new factor, this
  // will fail.
  dcsam.update(hfg);

  // Attempt a solve if we made it this far.
  DCValues dcval_final = dcsam.calculateEstimate();

  // If we made it here without an AssertionError, the test passed.
  EXPECT_EQ(true, true);
}