TEST_F(AssocTest, ApRejectedRequest) {
  // Create our device instance
  Init();

  // Start up fake APs
  simulation::FakeAp ap(env_.get(), kDefaultBssid, kDefaultSsid, kDefaultChannel);
  ap.EnableBeacon(zx::msec(100));
  ap.SetAssocHandling(simulation::FakeAp::ASSOC_REJECTED);
  aps_.push_back(&ap);

  context_.expected_results.push_front(WLAN_ASSOC_RESULT_REFUSED_REASON_UNSPECIFIED);

  ScheduleAssocReq(zx::msec(10));

  env_->Run();

  // We should have gotten a rejection from the fake AP
  EXPECT_EQ(assoc_responses_.size(), 1U);
  EXPECT_EQ(assoc_responses_.front().status, WLAN_STATUS_CODE_REFUSED);

  // Make sure we got our response from the driver
  EXPECT_EQ(context_.assoc_resp_count, 1U);
}