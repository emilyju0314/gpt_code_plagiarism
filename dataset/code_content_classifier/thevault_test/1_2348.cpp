TEST_F(AssocTest, RepeatedAssocTest) {
  // Create our device instance
  Init();

  // Start up our fake AP
  simulation::FakeAp ap(env_.get(), kDefaultBssid, kDefaultSsid, kDefaultChannel);
  ap.EnableBeacon(zx::msec(100));
  aps_.push_back(&ap);

  // The associations at 11ms and 12ms should be immediately rejected (because there is already
  // an association in progress), and eventually the association that was in progress should
  // succeed
  context_.expected_results.push_back(WLAN_ASSOC_RESULT_REFUSED_REASON_UNSPECIFIED);
  context_.expected_results.push_back(WLAN_ASSOC_RESULT_REFUSED_REASON_UNSPECIFIED);
  context_.expected_results.push_back(WLAN_ASSOC_RESULT_SUCCESS);

  ScheduleAssocReq(zx::msec(10));
  ScheduleAssocReq(zx::msec(11));
  ScheduleAssocReq(zx::msec(12));

  env_->Run();

  EXPECT_EQ(context_.assoc_resp_count, 3U);
}