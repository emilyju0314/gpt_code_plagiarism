TEST_F(ChessClockTester, Constructor) {
    EXPECT_EQ(cc.start_time(), cc.end_time());
    EXPECT_EQ(cc.time_is_extensible(), false);
    EXPECT_EQ(cc.allocated_time(), 0);
}