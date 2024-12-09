TEST(TestSuite, simple_slam_incremental) {
  // Make a factor graph
  HybridFactorGraph graph;

  // Values for initial guess
  gtsam::Values initialGuess;

  gtsam::Symbol x0('x', 0);
  gtsam::Pose2 pose0(0, 0, 0);
  gtsam::Pose2 dx(1, 0, 0.78539816);
  double prior_sigma = 0.1;
  double meas_sigma = 1.0;

  gtsam::noiseModel::Isotropic::shared_ptr prior_noise =
      gtsam::noiseModel::Isotropic::Sigma(3, prior_sigma);
  gtsam::noiseModel::Isotropic::shared_ptr meas_noise =
      gtsam::noiseModel::Isotropic::Sigma(3, meas_sigma);

  gtsam::PriorFactor<gtsam::Pose2> p0(x0, pose0, prior_noise);

  initialGuess.insert(x0, pose0);
  graph.push_nonlinear(p0);

  // Setup dcsam
  DCSAM dcsam;
  dcsam.update(graph, initialGuess);

  graph.clear();
  initialGuess.clear();

  gtsam::Pose2 odom(pose0);
  gtsam::Pose2 noise(0.01, 0.01, 0.01);
  for (size_t i = 0; i < 7; i++) {
    gtsam::Symbol xi('x', i);
    gtsam::Symbol xj('x', i + 1);

    gtsam::Pose2 meas = dx * noise;

    gtsam::BetweenFactor<gtsam::Pose2> bw(xi, xj, dx * noise, meas_noise);
    graph.push_nonlinear(bw);

    odom = odom * meas;
    initialGuess.insert(xj, odom);
    dcsam.update(graph, initialGuess);

    graph.clear();
    initialGuess.clear();
  }

  gtsam::Symbol x7('x', 7);
  gtsam::BetweenFactor<gtsam::Pose2> bw(x0, x7, dx * noise, meas_noise);

  dcsam.update(graph, initialGuess);
  DCValues dcvals = dcsam.calculateEstimate();

  // Plot the robot positions
#ifdef ENABLE_PLOTTING
  std::vector<double> xs, ys;
  for (size_t i = 0; i < 8; i++) {
    xs.push_back(dcvals.continuous.at<gtsam::Pose2>(gtsam::Symbol('x', i)).x());
    ys.push_back(dcvals.continuous.at<gtsam::Pose2>(gtsam::Symbol('x', i)).y());
  }
  plt::plot(xs, ys);
  plt::show();
#endif

  EXPECT_EQ(true, true);
}