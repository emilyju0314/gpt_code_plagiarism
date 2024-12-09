TEST_F(LSTMTrainerTest, SpeedTest) {
  SetupTrainerEng(
      "[1,30,0,1 Ct5,5,16 Mp2,2 L2xy24 Ct1,1,48 Mp5,1 Ct1,1,32 S3,1 Lbx64 "
      "O1c1]",
      "2-D-2-layer-lstm", false, true);
  TrainIterations(kTrainerIterations);
  LOG(INFO) << "********** *** ************\n";
}