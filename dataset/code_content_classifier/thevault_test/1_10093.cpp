TEST_F(FileBeforeStreamingTest, TestStartPlayingFileLocallyWithStartPlayout) {
  GenerateInputFile();

  TEST_LOG("Playout is not started. File will not be played out.\n");
  EXPECT_EQ(0, voe_file_->StartPlayingFileLocally(
      channel_, input_filename_.c_str(), true));
  EXPECT_EQ(1, voe_file_->IsPlayingFileLocally(channel_));
  RecordOutput();
  VerifyEmptyOutput();

  TEST_LOG("Playout is now started. File will be played out.\n");
  EXPECT_EQ(0, voe_base_->StartPlayout(channel_));
  RecordOutput();
  VerifyOutput(kInputValue);

  TEST_LOG("Stop playing file. Only silence will be played out.\n");
  EXPECT_EQ(0, voe_file_->StopPlayingFileLocally(channel_));
  EXPECT_EQ(0, voe_file_->IsPlayingFileLocally(channel_));
  RecordOutput();
  VerifyOutput(kSilenceValue);

  TEST_LOG("Start playing file again. File will be played out.\n");
  EXPECT_EQ(0, voe_file_->StartPlayingFileLocally(
      channel_, input_filename_.c_str(), true));
  EXPECT_EQ(1, voe_file_->IsPlayingFileLocally(channel_));
  RecordOutput();
  VerifyOutput(kInputValue);

  EXPECT_EQ(0, voe_base_->StopPlayout(channel_));
  EXPECT_EQ(0, voe_file_->StopPlayingFileLocally(channel_));
}