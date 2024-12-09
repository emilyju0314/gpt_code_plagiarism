TEST_F(AssocTest, IgnoreAssociations) {
  // Schedule assoc req
  auto handler = new std::function<void()>;
  *handler = std::bind(&simulation::Environment::TxAssocReq, &env_, this, kDefaultChannel,
                       kClientMacAddr, kApBssid);
  env_.ScheduleNotification(this, zx::sec(1), static_cast<void*>(handler));

  ap_.SetAssocHandling(simulation::FakeAp::ASSOC_IGNORED);

  env_.Run();

  // Verify that no assoc responses were seen in the environment
  EXPECT_EQ(assoc_resp_count_, 0U);
}