TEST_F(StatsTest, AddOne) {
  stats_->NewFrame(0u);
  FrameStatistic* frameStat = &stats_->stats_[0];
  EXPECT_EQ(0, frameStat->frame_number);
}