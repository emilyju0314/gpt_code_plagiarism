TEST_F(LSTMTrainerTest, SoftmaxTest) {
  // LSTM with a built-in softmax can beat the external softmax.
  SetupTrainerEng("[1,1,0,32 LS96]", "Lstm-+-softmax", false, true);
  double lstm_sm_err = TrainIterations(kTrainerIterations * 2);
  EXPECT_LT(lstm_sm_err, 49.0);
  LOG(INFO) << "********** Expected  < 49 ************\n";
  // Check that it works in int mode too.
  TestIntMode(kTrainerIterations);
}