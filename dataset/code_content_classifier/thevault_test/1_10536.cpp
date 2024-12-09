TEST_F(LSTMTrainerTest, Test2D) {
  // A 2-layer LSTM with a 2-D feature-extracting LSTM on the bottom.
  SetupTrainerEng("[1,32,0,1 S4,2 L2xy16 Ct1,1,16 S8,1 Lbx100 O1c1]", "2-D-2-layer-lstm", false,
                  false);
  double lstm_2d_err = TrainIterations(kTrainerIterations * 3 / 2);
  EXPECT_LT(lstm_2d_err, 98);
  //  EXPECT_GT(lstm_2d_err, 90);
  LOG(INFO) << "********** Expected  < 98 ************\n";
  // Int mode training is dead, so convert the trained network to int and check
  // that its error rate is close to the float version.
  TestIntMode(kTrainerIterations);
}