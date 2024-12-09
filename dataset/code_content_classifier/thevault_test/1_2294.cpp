TEST_F(AssocTest, DisassocFromSta) {
  // Schedule assoc req
  auto handler = new std::function<void()>;
  *handler = std::bind(&simulation::Environment::TxAssocReq, &env_, this, kDefaultChannel,
                       kClientMacAddr, kApBssid);
  env_.ScheduleNotification(this, zx::sec(1), static_cast<void*>(handler));

  // Schedule Disassoc request from STA
  handler = new std::function<void()>;
  *handler = std::bind(&simulation::Environment::TxDisassocReq, &env_, this, kDefaultChannel,
                       kClientMacAddr, kApBssid, kClientDisassocReason);
  env_.ScheduleNotification(this, zx::sec(2), static_cast<void*>(handler));

  env_.Run();

  // Verify that one assoc resp was seen and after disassoc the number of
  // clients should be 0.
  EXPECT_EQ(assoc_resp_count_, 1U);
  ASSERT_EQ(assoc_status_list_.size(), (size_t)1);
  EXPECT_EQ(assoc_status_list_.front(), (uint16_t)WLAN_STATUS_CODE_SUCCESS);
  EXPECT_EQ(ap_.GetNumClients(), 0U);
  assoc_status_list_.pop_front();
}