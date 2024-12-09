void CheckIsIterationInvariantRate(Results const& e) {
  double its = e.NumIterations();
  double t = e.DurationCPUTime();  // this (and not real time) is the time used
  // check that the values are within 0.1% of the expected values
  CHECK_FLOAT_COUNTER_VALUE(e, "foo", EQ, its * 1. / t, 0.001);
  CHECK_FLOAT_COUNTER_VALUE(e, "bar", EQ, its * 2. / t, 0.001);
}