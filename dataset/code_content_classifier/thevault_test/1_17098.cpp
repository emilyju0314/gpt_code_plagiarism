TEST_F(ReportingDeliveryAgentTest, OnlyBatchSameNikAndOrigin) {
  const ReportingEndpointGroupKey kGroupKeys[] = {
      ReportingEndpointGroupKey(kNik_, kOrigin_, kGroup_),
      ReportingEndpointGroupKey(kNik_, kOtherOrigin_, kGroup_),
      ReportingEndpointGroupKey(kOtherNik_, kOrigin_, kGroup_),
      ReportingEndpointGroupKey(kOtherNik_, kOtherOrigin_, kGroup_),
  };
  for (const ReportingEndpointGroupKey& group_key : kGroupKeys) {
    ASSERT_TRUE(SetEndpointInCache(group_key, kEndpoint_, kExpires_));
  }

  // Trigger and complete an upload to start the delivery timer.
  UploadFirstReportAndStartTimer();

  // Now that the delivery timer is running, these reports won't be immediately
  // uploaded.
  AddReport(kNik_, kUrl_, kGroup_);
  AddReport(kNik_, kOtherUrl_, kGroup_);
  AddReport(kNik_, kOtherUrl_, kGroup_);
  AddReport(kOtherNik_, kUrl_, kGroup_);
  AddReport(kOtherNik_, kUrl_, kGroup_);
  AddReport(kOtherNik_, kUrl_, kGroup_);
  AddReport(kOtherNik_, kOtherUrl_, kGroup_);
  AddReport(kOtherNik_, kOtherUrl_, kGroup_);
  AddReport(kOtherNik_, kOtherUrl_, kGroup_);
  AddReport(kOtherNik_, kOtherUrl_, kGroup_);
  EXPECT_EQ(0u, pending_uploads().size());

  // There should be one upload per (NIK, origin).
  EXPECT_TRUE(delivery_timer()->IsRunning());
  delivery_timer()->Fire();
  ASSERT_EQ(4u, pending_uploads().size());

  pending_uploads()[0]->Complete(ReportingUploader::Outcome::SUCCESS);
  pending_uploads()[0]->Complete(ReportingUploader::Outcome::SUCCESS);
  pending_uploads()[0]->Complete(ReportingUploader::Outcome::SUCCESS);
  pending_uploads()[0]->Complete(ReportingUploader::Outcome::SUCCESS);
  EXPECT_EQ(0u, pending_uploads().size());

  for (int i = 0; i < 4; ++i) {
    ReportingEndpoint::Statistics stats =
        GetEndpointStatistics(kGroupKeys[i], kEndpoint_);
    EXPECT_EQ(1, stats.attempted_uploads);
    EXPECT_EQ(1, stats.successful_uploads);
    EXPECT_EQ(i + 1, stats.attempted_reports);
    EXPECT_EQ(i + 1, stats.successful_reports);
  }
}