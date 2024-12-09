TEST_F(ChessClockTester, TimeIsExtensible_TimeLimit_Over10Seconds) {
    EXPECT_EQ(cc.time_is_extensible(), false);

    /// UCI Options allocated time is < 10 seconds, so time isn't extensible
    EXPECT_EQ(uci_options.search_to_depth_x, -1);
    EXPECT_EQ(uci_options.search_for_time_x, -1);
    uci_options.b_time_milli = 10000;
    uci_options.w_time_milli = 10000;
    EXPECT_EQ(uci_options.b_time_milli, 10000);
    EXPECT_EQ(uci_options.w_time_milli, 10000);

    /// Test white and black
    cc.alloc_time(uci_options, WHITE);
    EXPECT_EQ(cc.time_is_extensible(), true);
    cc.alloc_time(uci_options, BLACK);
    EXPECT_EQ(cc.time_is_extensible(), true);

    /// UCI Options allocated time is < 10 seconds, so time isn't extensible
    uci_options.b_time_milli = 100000;
    uci_options.w_time_milli = 1234567;

    /// Test white and black
    cc.alloc_time(uci_options, WHITE);
    EXPECT_EQ(cc.time_is_extensible(), true);
    cc.alloc_time(uci_options, BLACK);
    EXPECT_EQ(cc.time_is_extensible(), true);
}