TEST_P(BweSimulation, GccComparison1) {
  RunVariableCapacity1SingleFlow(GetParam());
  BweTest gcc_test(false);
  gcc_test.RunVariableCapacity1SingleFlow(kFullSendSideEstimator);
}