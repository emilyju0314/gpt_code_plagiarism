TEST_F(AssocTest, RejectAssociations) {
  // Schedule first request
  auto handler = new std::function<void()>;
  *handler = std::bind(&simulation::Environment::TxAssocReq, &env_, this, kDefaultChannel,
                       kClientMacAddr, kApBssid);
  env_.ScheduleNotification(this, zx::sec(1), static_cast<void*>(handler));

  ap_.SetAssocHandling(simulation::FakeAp::ASSOC_REJECTED);

  env_.Run();

  EXPECT_EQ(assoc_resp_count_, 1U);
  ASSERT_EQ(assoc_status_list_.size(), (size_t)1);
  EXPECT_EQ(assoc_status_list_.front(), (uint16_t)WLAN_STATUS_CODE_REFUSED);
  assoc_status_list_.pop_front();
}