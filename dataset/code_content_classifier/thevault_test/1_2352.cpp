TEST_F(AssocTest, IgnoreExtraResp) {
  // Create our device instance
  Init();

  // Start up fake AP
  simulation::FakeAp ap(env_.get(), kDefaultBssid, kDefaultSsid, kDefaultChannel);
  ap.EnableBeacon(zx::msec(100));

  // We want the association request to be ignored so we can inject responses and verify that
  // they are being ignored.
  ap.SetAssocHandling(simulation::FakeAp::ASSOC_IGNORED);

  aps_.push_back(&ap);

  context_.expected_results.push_front(WLAN_ASSOC_RESULT_SUCCESS);
  context_.on_assoc_req_callback = std::bind(&AssocTest::SendMultipleResp, this);

  ScheduleAssocReq(zx::msec(10));

  env_->Run();

  // Make sure that the firmware/driver only responded to the first response
  EXPECT_EQ(context_.assoc_resp_count, 1U);
}