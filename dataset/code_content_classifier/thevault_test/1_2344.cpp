TEST_F(AssocTest, NoAps) {
  // Create our device instance
  Init();

  const common::MacAddr kBssid({0x12, 0x34, 0x56, 0x78, 0x9a, 0xbc});
  context_.bssid = kBssid;
  context_.expected_results.push_front(WLAN_ASSOC_RESULT_REFUSED_REASON_UNSPECIFIED);
  context_.ssid = {.len = 6, .ssid = "TestAP"};
  context_.channel = {.primary = 9, .cbw = WLAN_CHANNEL_BANDWIDTH__20, .secondary80 = 0};

  ScheduleAssocReq(zx::msec(10));

  env_->Run();

  EXPECT_EQ(context_.assoc_resp_count, 1U);
}