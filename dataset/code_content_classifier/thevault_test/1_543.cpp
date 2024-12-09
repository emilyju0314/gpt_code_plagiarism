TEST_F(ChessClockTester, AllocateTime_TimeLimit) {
    EXPECT_EQ(cc.time_is_extensible(), false);

    /// UCI Options allocated time is < 10 seconds, so time isn't extensible
    uci_options.b_time_milli = 1000;
    uci_options.w_time_milli = 1000;

    /// Test white and black
    cc.alloc_time(uci_options, WHITE);
    EXPECT_EQ(cc.allocated_time(), 1000 / 40);
    cc.alloc_time(uci_options, BLACK);
    EXPECT_EQ(cc.allocated_time(), 1000 / 40);

    /// UCI Options allocated time is < 10 seconds, so time isn't extensible
    uci_options.b_time_milli = 9999;
    uci_options.w_time_milli = 10;

    /// Test white and black
    cc.alloc_time(uci_options, WHITE);
    EXPECT_EQ(cc.allocated_time(), 10 / 40);
    cc.alloc_time(uci_options, BLACK);
    EXPECT_EQ(cc.allocated_time(), 9999 / 40);

    /// UCI Options allocated time is < 10 seconds, so time isn't extensible
    uci_options.b_time_milli = 10000;
    uci_options.w_time_milli = 10000;

    /// Test white and black
    cc.alloc_time(uci_options, WHITE);
    EXPECT_EQ(cc.allocated_time(), 10000 / 40);
    cc.alloc_time(uci_options, BLACK);
    EXPECT_EQ(cc.allocated_time(), 10000 / 40);

    /// UCI Options allocated time is < 10 seconds, so time isn't extensible
    uci_options.b_time_milli = 100000;
    uci_options.w_time_milli = 1234567;

    /// Test white and black
    cc.alloc_time(uci_options, WHITE);
    EXPECT_EQ(cc.allocated_time(), 1234567 / 40);
    cc.alloc_time(uci_options, BLACK);
    EXPECT_EQ(cc.allocated_time(), 100000 / 40);
}