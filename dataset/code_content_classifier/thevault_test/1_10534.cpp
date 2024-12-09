TEST_F(LSTMTrainerTest, BasicTest) {
  // A Convolver sliding window classifier without LSTM.
  SetupTrainer(
      "[1,32,0,1 Ct5,5,16 Mp4,4 Ct1,1,16 Ct3,3,128 Mp4,1 Ct1,1,64 S2,1 "
      "Ct1,1,64O1c1]",
      "no-lstm", "eng/eng.unicharset", "eng.Arial.exp0.lstmf", false, false, 2e-4, false, "eng");
  double non_lstm_err = TrainIterations(kTrainerIterations * 4);
  EXPECT_LT(non_lstm_err, 98);
  LOG(INFO) << "********** Expected  < 98 ************\n";

  // A basic single-layer, single direction LSTM.
  SetupTrainerEng("[1,1,0,32 Lfx100 O1c1]", "1D-lstm", false, false);
  double lstm_uni_err = TrainIterations(kTrainerIterations * 2);
  EXPECT_LT(lstm_uni_err, 86);
  LOG(INFO) << "********** Expected  < 86 ************\n";
  // Beats the convolver. (Although it does have a lot more weights, it still
  // iterates faster.)
  EXPECT_LT(lstm_uni_err, non_lstm_err);
}