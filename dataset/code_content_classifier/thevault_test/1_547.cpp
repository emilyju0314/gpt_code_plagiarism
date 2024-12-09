TEST_F(ChessClockTester, ExtendTime_TimeLimit) {
    /// UCI Options allocated time is < 10 seconds, so time isn't extensible
    uci_options.b_time_milli = 1000;
    uci_options.w_time_milli = 1000;

    /// Test white and black
    cc.alloc_time(uci_options, WHITE);
    EXPECT_EQ(cc.allocated_time(), 1000 / 40);
    cc.extend_time(0);
    EXPECT_EQ(cc.allocated_time(), 1000 / 40);
    cc.extend_time(10);
    EXPECT_EQ(cc.allocated_time(), 1000 / 40);
    cc.alloc_time(uci_options, BLACK);
    EXPECT_EQ(cc.allocated_time(), 1000 / 40);
    cc.extend_time(0);
    EXPECT_EQ(cc.allocated_time(), 1000 / 40);
    cc.extend_time(10);
    EXPECT_EQ(cc.allocated_time(), 1000 / 40);

    /// UCI Options allocated time is < 10 seconds, so time isn't extensible
    uci_options.b_time_milli = 9999;
    uci_options.w_time_milli = 10;

    /// Test white and black
    cc.alloc_time(uci_options, WHITE);
    EXPECT_EQ(cc.allocated_time(), 10 / 40);
    cc.extend_time(2);
    EXPECT_EQ(cc.allocated_time(), 10 / 40);
    cc.extend_time(3);
    EXPECT_EQ(cc.allocated_time(), 10 / 40);
    cc.alloc_time(uci_options, BLACK);
    EXPECT_EQ(cc.allocated_time(), 9999 / 40);
    cc.extend_time(0);
    EXPECT_EQ(cc.allocated_time(), 9999 / 40);
    cc.extend_time(9);
    EXPECT_EQ(cc.allocated_time(), 9999 / 40);

    /// UCI Options allocated time is < 10 seconds, so time isn't extensible
    uci_options.b_time_milli = 10000;
    uci_options.w_time_milli = 10000;

    /// Test white and black
    cc.alloc_time(uci_options, WHITE);
    EXPECT_EQ(cc.allocated_time(), 10000 / 40);
    cc.extend_time(0);
    EXPECT_EQ(cc.allocated_time(), 10000 / 40 + 250 * 0);
    cc.extend_time(3);
    EXPECT_EQ(cc.allocated_time(), 10000 / 40 + 250 * 0);
    cc.alloc_time(uci_options, BLACK);
    EXPECT_EQ(cc.allocated_time(), 10000 / 40);
    cc.extend_time(10);
    EXPECT_EQ(cc.allocated_time(), 10000 / 40 + 250 * 10);
    cc.extend_time(9);
    EXPECT_EQ(cc.allocated_time(), 10000 / 40 + 250 * 10);

    /// UCI Options allocated time is < 10 seconds, so time isn't extensible
    uci_options.b_time_milli = 100000;
    uci_options.w_time_milli = 1234567;

    /// Test white and black
    cc.alloc_time(uci_options, WHITE);
    EXPECT_EQ(cc.allocated_time(), 1234567 / 40);
    cc.extend_time(4);
    EXPECT_EQ(cc.allocated_time(), 1234567 / 40 + 250 * 4);
    cc.extend_time(0);
    EXPECT_EQ(cc.allocated_time(), 1234567 / 40 + 250 * 4);
    cc.alloc_time(uci_options, BLACK);
    EXPECT_EQ(cc.allocated_time(), 100000 / 40);
    cc.extend_time(1);
    EXPECT_EQ(cc.allocated_time(), 100000 / 40 + 250 * 1);
    cc.extend_time(15);
    EXPECT_EQ(cc.allocated_time(), 100000 / 40 + 250 * 1);
}