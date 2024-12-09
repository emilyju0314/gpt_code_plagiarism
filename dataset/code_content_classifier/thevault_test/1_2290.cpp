TEST_F(AssocTest, IgnoredRequests) {
  constexpr wlan_channel_t kWrongChannel = {
      .primary = 10, .cbw = WLAN_CHANNEL_BANDWIDTH__20, .secondary80 = 0};
  static const common::MacAddr kWrongBssid({0x12, 0x34, 0x56, 0x78, 0x9a, 0xbd});

  // Schedule assoc req on different channel
  auto handler = new std::function<void()>;
  *handler = std::bind(&simulation::Environment::TxAssocReq, &env_, this, kWrongChannel,
                       kClientMacAddr, kApBssid);
  env_.ScheduleNotification(this, zx::sec(1), static_cast<void*>(handler));

  // Schedule assoc req to different bssid
  handler = new std::function<void()>;
  *handler = std::bind(&simulation::Environment::TxAssocReq, &env_, this, kDefaultChannel,
                       kClientMacAddr, kWrongBssid);
  env_.ScheduleNotification(this, zx::sec(2), static_cast<void*>(handler));

  env_.Run();

  // Verify that no assoc responses were seen in the environment
  EXPECT_EQ(assoc_resp_count_, 0U);
}