TEST_F(ChessClockTester, AllocateTime_SearchToDepthX) {
    /// UCI Options allocated time is < 10 seconds, so time isn't extensible
    EXPECT_EQ(uci_options.search_to_depth_x, -1);
    EXPECT_EQ(uci_options.search_for_time_x, -1);
    uci_options.search_to_depth_x = 10;

    /// Test white and black
    cc.alloc_time(uci_options, WHITE);
    EXPECT_EQ(cc.allocated_time(), -1);
    cc.alloc_time(uci_options, BLACK);
    EXPECT_EQ(cc.allocated_time(), -1);

    /// UCI Options allocated time is < 10 seconds, so time isn't extensible
    uci_options.search_to_depth_x = 15;
    uci_options.w_time_milli = 100000;
    uci_options.b_time_milli = 100000;

    /// Test white and black
    cc.alloc_time(uci_options, WHITE);
    EXPECT_EQ(cc.allocated_time(), -1);
    cc.alloc_time(uci_options, BLACK);
    EXPECT_EQ(cc.allocated_time(), -1);
}