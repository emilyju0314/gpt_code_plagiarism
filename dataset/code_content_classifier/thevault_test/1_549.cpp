TEST_F(ChessClockTester, ExtendTime_SearchForXSeconds) {
/// UCI Options allocated time is < 10 seconds, so time isn't extensible
    EXPECT_EQ(uci_options.search_to_depth_x, -1);
    EXPECT_EQ(uci_options.search_for_time_x, -1);
    uci_options.search_for_time_x = 10;

    /// Test white and black
    cc.alloc_time(uci_options, WHITE);
    EXPECT_EQ(cc.allocated_time(), 10 * 1000);
    cc.extend_time(0);
    EXPECT_EQ(cc.allocated_time(), 10 * 1000);
    cc.alloc_time(uci_options, BLACK);
    EXPECT_EQ(cc.allocated_time(), 10 * 1000);
    cc.extend_time(12);
    EXPECT_EQ(cc.allocated_time(), 10 * 1000);

    /// UCI Options allocated time is < 10 seconds, so time isn't extensible
    uci_options.search_for_time_x = 15;
    uci_options.w_time_milli = 100000;
    uci_options.b_time_milli = 100000;

    /// Test white and black
    cc.alloc_time(uci_options, WHITE);
    EXPECT_EQ(cc.allocated_time(), 15 * 1000);
    cc.extend_time(0);
    EXPECT_EQ(cc.allocated_time(), 15 * 1000);
    cc.alloc_time(uci_options, BLACK);
    EXPECT_EQ(cc.allocated_time(), 15 * 1000);
    cc.extend_time(2);
    EXPECT_EQ(cc.allocated_time(), 15 * 1000);
}