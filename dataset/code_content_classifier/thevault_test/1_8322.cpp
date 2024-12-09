void CheckAvgIterationsRate(Results const& e) {
  double its = e.NumIterations();
  double t = e.DurationCPUTime();  // this (and not real time) is the time used
  // check that the values are within 0.1% of the expected values
  CHECK_FLOAT_COUNTER_VALUE(e, "foo", EQ, 1. / its / t, 0.001);
  CHECK_FLOAT_COUNTER_VALUE(e, "bar", EQ, 2. / its / t, 0.001);
}