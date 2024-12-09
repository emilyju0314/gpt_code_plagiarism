void CheckAvgIterations(Results const& e) {
  double its = e.NumIterations();
  // check that the values are within 0.1% of the expected value
  CHECK_FLOAT_COUNTER_VALUE(e, "foo", EQ, 1. / its, 0.001);
  CHECK_FLOAT_COUNTER_VALUE(e, "bar", EQ, 2. / its, 0.001);
}