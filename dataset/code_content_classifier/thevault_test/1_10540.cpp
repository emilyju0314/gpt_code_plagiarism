TEST_F(LSTMTrainerTest, SoftmaxBaselineTest) {
  // A basic single-layer, single direction LSTM.
  SetupTrainerEng("[1,1,0,32 Lfx96 O1c1]", "1D-lstm", false, true);
  double lstm_uni_err = TrainIterations(kTrainerIterations * 2);
  EXPECT_LT(lstm_uni_err, 60);
  //  EXPECT_GT(lstm_uni_err, 48);
  LOG(INFO) << "********** Expected  < 60 ************\n";
  // Check that it works in int mode too.
  TestIntMode(kTrainerIterations);
  // If we run TestIntMode again, it tests that int_mode networks can
  // serialize and deserialize correctly.
  double delta = TestIntMode(kTrainerIterations);
  // The two tests (both of int mode this time) should be almost identical.
  LOG(INFO) << "Delta in Int mode error rates = " << delta << "\n";
  EXPECT_LT(delta, 0.01);
}