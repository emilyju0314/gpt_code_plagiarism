TEST(ZmqEventLoopTest, CopyCapture) {
  ZmqEventLoop evl;
  auto const& now = std::chrono::steady_clock::now();

  auto callback = std::function<void()>([&]() noexcept {
    SUCCEED();
    evl.stop();
  });
  evl.scheduleTimeout(std::chrono::seconds(0), callback);

  LOG(INFO) << "Starting loop...";
  evl.run();
  EXPECT_GE(
      evl.getTimestamp().time_since_epoch().count(),
      now.time_since_epoch().count());

  LOG(INFO) << "Stopping loop...";
  SUCCEED();
}