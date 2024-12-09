TEST_F(LSTMTrainerTest, EncodedSoftmaxTest) {
  // LSTM with a built-in encoded softmax can beat the external softmax.
  SetupTrainerEng("[1,1,0,32 LE96]", "Lstm-+-softmax", false, true);
  double lstm_sm_err = TrainIterations(kTrainerIterations * 2);
  EXPECT_LT(lstm_sm_err, 62.0);
  LOG(INFO) << "********** Expected   < 62 ************\n";
  // Check that it works in int mode too.
  TestIntMode(kTrainerIterations);
}