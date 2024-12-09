TEST_F(LSTMTrainerTest, ColorTest) {
  // A basic single-layer, single direction LSTM.
  SetupTrainerEng("[1,32,0,3 S4,2 L2xy16 Ct1,1,16 S8,1 Lbx100 O1c1]", "2D-color-lstm", true, true);
  double lstm_uni_err = TrainIterations(kTrainerIterations);
  EXPECT_LT(lstm_uni_err, 85);
  //  EXPECT_GT(lstm_uni_err, 66);
  LOG(INFO) << "********** Expected  < 85 ************\n";
}