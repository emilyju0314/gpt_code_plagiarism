TEST_F(AssocTest, AssocWhileScanning) {
  // Create our device instance
  Init();

  // Start up fake AP
  simulation::FakeAp ap(env_.get(), kDefaultBssid, kDefaultSsid, kDefaultChannel);
  ap.EnableBeacon(zx::msec(100));
  aps_.push_back(&ap);

  context_.expected_results.push_front(WLAN_ASSOC_RESULT_REFUSED_REASON_UNSPECIFIED);
  context_.on_assoc_req_callback = std::bind(&AssocTest::SendMultipleResp, this);

  ScheduleAssocReq(zx::msec(10));

  wlanif_scan_req_t scan_req = {
      .txn_id = 42,
      .bss_type = WLAN_BSS_TYPE_INFRASTRUCTURE,
      .scan_type = WLAN_SCAN_TYPE_PASSIVE,
      .num_channels = 11,
      .channel_list = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11},
      .min_channel_time = 100,
      .max_channel_time = 100,
      .num_ssids = 0,
  };
  client_ifc_->if_impl_ops_->start_scan(client_ifc_->if_impl_ctx_, &scan_req);

  env_->Run();

  EXPECT_EQ(context_.assoc_resp_count, 1U);
}