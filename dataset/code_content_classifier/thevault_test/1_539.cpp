TEST_F(ChessClockTester, TimeIsExtensible_TimeLimit_Under10Seconds) {
    EXPECT_EQ(cc.time_is_extensible(), false);

    /// UCI Options allocated time is < 10 seconds, so time isn't extensible
    uci_options.b_time_milli = 1000;
    uci_options.w_time_milli = 1000;

    /// Test white and black
    cc.alloc_time(uci_options, WHITE);
    EXPECT_EQ(cc.time_is_extensible(), false);
    cc.alloc_time(uci_options, BLACK);
    EXPECT_EQ(cc.time_is_extensible(), false);

    /// UCI Options allocated time is < 10 seconds, so time isn't extensible
    uci_options.b_time_milli = 9999;
    uci_options.w_time_milli = 10;

    /// Test white and black
    cc.alloc_time(uci_options, WHITE);
    EXPECT_EQ(cc.time_is_extensible(), false);
    cc.alloc_time(uci_options, BLACK);
    EXPECT_EQ(cc.time_is_extensible(), false);
}