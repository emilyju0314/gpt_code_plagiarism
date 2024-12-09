TEST_F(AssocTest, WrongIds) {
  // Create our device instance
  Init();

  constexpr wlan_channel_t kWrongChannel = {
      .primary = 8, .cbw = WLAN_CHANNEL_BANDWIDTH__20, .secondary80 = 0};
  ASSERT_NE(kDefaultChannel.primary, kWrongChannel.primary);
  constexpr wlan_ssid_t kWrongSsid = {.len = 14, .ssid = "Fuchsia Fake AP"};
  ASSERT_NE(kDefaultSsid.len, kWrongSsid.len);
  const common::MacAddr kWrongBssid({0x12, 0x34, 0x56, 0x78, 0x9b, 0xbc});
  ASSERT_NE(kDefaultBssid, kWrongBssid);

  // Start up fake APs
  simulation::FakeAp ap1(env_.get(), kDefaultBssid, kDefaultSsid, kWrongChannel);
  ap1.EnableBeacon(zx::msec(100));
  aps_.push_back(&ap1);
  simulation::FakeAp ap2(env_.get(), kWrongBssid, kDefaultSsid, kDefaultChannel);
  ap2.EnableBeacon(zx::msec(90));
  aps_.push_back(&ap2);
  simulation::FakeAp ap3(env_.get(), kDefaultBssid, kWrongSsid, kDefaultChannel);
  ap3.EnableBeacon(zx::msec(80));
  aps_.push_back(&ap3);

  context_.expected_results.push_front(WLAN_ASSOC_RESULT_REFUSED_REASON_UNSPECIFIED);

  ScheduleAssocReq(zx::msec(10));

  env_->Run();

  // The APs aren't giving us a response, but the driver is telling us that the operation failed
  // because it couldn't find a matching AP.
  EXPECT_EQ(context_.assoc_resp_count, 1U);
}