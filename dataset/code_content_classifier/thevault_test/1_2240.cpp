TEST_F(ActiveScanTest, RandomMacThreeAps) {
  // Start time and end time of this test case
  constexpr zx::duration kScanStartTime = zx::sec(1);
  constexpr zx::duration kDefaultTestDuration = zx::sec(10);

  // Create simulated device
  Init();

  // Start the first AP
  StartFakeAp(kAp1Bssid, kAp1Ssid, kDefaultChannel1);
  StartFakeAp(kAp2Bssid, kAp2Ssid, kDefaultChannel1);
  StartFakeAp(kAp3Bssid, kAp3Ssid, kDefaultChannel2);
  // Get firmware mac address and tmp mac address for active scan
  GetFirmwareMac();

  auto scan_handler = new std::function<void()>;
  *scan_handler = std::bind(&ActiveScanTest::StartScan, this);
  env_->ScheduleNotification(this, kScanStartTime, scan_handler);

  // Schedule scan end in environment
  auto end_handler = new std::function<void()>;
  *end_handler = std::bind(&ActiveScanTest::EndSimulation, this);
  env_->ScheduleNotification(this, kDefaultTestDuration, end_handler);

  env_->Run();

  EXPECT_EQ(all_aps_seen_, true);
}