TEST_F(LSTMTrainerTest, TestAdam) {
  // A 2-layer LSTM with a 2-D feature-extracting LSTM on the bottom.
  SetupTrainerEng("[1,32,0,1 S4,2 L2xy16 Ct1,1,16 S8,1 Lbx100 O1c1]", "2-D-2-layer-lstm", false,
                  true);
  double lstm_2d_err = TrainIterations(kTrainerIterations);
  EXPECT_LT(lstm_2d_err, 70);
  LOG(INFO) << "********** Expected   < 70 ************\n";
  TestIntMode(kTrainerIterations);
}