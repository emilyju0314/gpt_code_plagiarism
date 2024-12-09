TEST_F(StatsTest, AddMany) {
  int nbr_of_frames = 1000;
  for (int i = 0; i < nbr_of_frames; ++i) {
    FrameStatistic& frameStat = stats_->NewFrame(i);
    EXPECT_EQ(i, frameStat.frame_number);
  }
  EXPECT_EQ(nbr_of_frames, static_cast<int>(stats_->stats_.size()));

  stats_->PrintSummary();  // should not crash
}