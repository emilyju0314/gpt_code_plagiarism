TEST_F(ChessClockTester, Duration) {
    using namespace std::chrono_literals;
    cc.start();
    std::this_thread::sleep_for(2s);
    cc.stop();
    EXPECT_NEAR(cc.duration() * 1e-9, 2.0, ERROR);
}