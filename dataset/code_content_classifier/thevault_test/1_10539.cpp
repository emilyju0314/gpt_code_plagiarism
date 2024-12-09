TEST_F(LSTMTrainerTest, DeterminismTest) {
  SetupTrainerEng("[1,32,0,1 S4,2 L2xy16 Ct1,1,16 S8,1 Lbx100 O1c1]", "2-D-2-layer-lstm", false,
                  false);
  double lstm_2d_err_a = TrainIterations(kTrainerIterations);
  double act_error_a = trainer_->ActivationError();
  double char_error_a = trainer_->CharError();
  std::vector<char> trainer_a_data;
  EXPECT_TRUE(trainer_->SaveTrainingDump(NO_BEST_TRAINER, *trainer_, &trainer_a_data));
  SetupTrainerEng("[1,32,0,1 S4,2 L2xy16 Ct1,1,16 S8,1 Lbx100 O1c1]", "2-D-2-layer-lstm", false,
                  false);
  double lstm_2d_err_b = TrainIterations(kTrainerIterations);
  double act_error_b = trainer_->ActivationError();
  double char_error_b = trainer_->CharError();
  EXPECT_FLOAT_EQ(lstm_2d_err_a, lstm_2d_err_b);
  EXPECT_FLOAT_EQ(act_error_a, act_error_b);
  EXPECT_FLOAT_EQ(char_error_a, char_error_b);
  // Now train some more iterations.
  lstm_2d_err_b = TrainIterations(kTrainerIterations / 3);
  act_error_b = trainer_->ActivationError();
  char_error_b = trainer_->CharError();
  // Unpack into a new trainer and train that some more too.
  SetupTrainerEng("[1,32,0,1 S4,2 L2xy16 Ct1,1,16 S8,1 Lbx100 O1c1]", "2-D-2-layer-lstm", false,
                  false);
  EXPECT_TRUE(trainer_->ReadTrainingDump(trainer_a_data, *trainer_));
  lstm_2d_err_a = TrainIterations(kTrainerIterations / 3);
  act_error_a = trainer_->ActivationError();
  char_error_a = trainer_->CharError();
  EXPECT_FLOAT_EQ(lstm_2d_err_a, lstm_2d_err_b);
  EXPECT_FLOAT_EQ(act_error_a, act_error_b);
  EXPECT_FLOAT_EQ(char_error_a, char_error_b);
  LOG(INFO) << "********** *** ************\n";
}