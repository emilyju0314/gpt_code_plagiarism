TEST_F(AssocTest, BasicUse) {
  // Schedule first request
  auto handler = new std::function<void()>;
  *handler = std::bind(&simulation::Environment::TxAssocReq, &env_, this, kDefaultChannel,
                       kClientMacAddr, kApBssid);
  env_.ScheduleNotification(this, zx::usec(50), static_cast<void*>(handler));

  // Schedule second request
  handler = new std::function<void()>;
  *handler = std::bind(&simulation::Environment::TxAssocReq, &env_, this, kDefaultChannel,
                       kClientMacAddr, kApBssid);
  env_.ScheduleNotification(this, zx::usec(100), static_cast<void*>(handler));

  // Schedule third request
  handler = new std::function<void()>;
  *handler = std::bind(&simulation::Environment::TxAssocReq, &env_, this, kDefaultChannel,
                       kClientMacAddr, kApBssid);
  env_.ScheduleNotification(this, zx::usec(150), static_cast<void*>(handler));

  env_.Run();

  EXPECT_EQ(assoc_resp_count_, 3U);
  ASSERT_EQ(assoc_status_list_.size(), (size_t)3);
  EXPECT_EQ(assoc_status_list_.front(), (uint16_t)WLAN_STATUS_CODE_SUCCESS);
  assoc_status_list_.pop_front();
  EXPECT_EQ(assoc_status_list_.front(), (uint16_t)WLAN_STATUS_CODE_REFUSED_TEMPORARILY);
  assoc_status_list_.pop_front();
  EXPECT_EQ(assoc_status_list_.front(), (uint16_t)WLAN_STATUS_CODE_REFUSED_TEMPORARILY);
  assoc_status_list_.pop_front();
}