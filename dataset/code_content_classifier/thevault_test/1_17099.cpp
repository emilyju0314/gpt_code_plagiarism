TEST_F(ReportingDeliveryAgentTest, SerializeUploadsToGroup) {
  static const GURL kDifferentEndpoint("https://endpoint2/");

  ASSERT_TRUE(SetEndpointInCache(kGroupKey_, kEndpoint_, kExpires_));
  ASSERT_TRUE(SetEndpointInCache(kGroupKey_, kDifferentEndpoint, kExpires_));

  // Trigger and complete an upload to start the delivery timer.
  UploadFirstReportAndStartTimer();

  // First upload causes this group key to become pending.
  AddReport(kNik_, kUrl_, kGroup_);
  EXPECT_EQ(0u, pending_uploads().size());
  EXPECT_TRUE(delivery_timer()->IsRunning());
  delivery_timer()->Fire();
  EXPECT_EQ(1u, pending_uploads().size());

  // Second upload isn't started because the group is pending.
  AddReport(kNik_, kUrl_, kGroup_);
  EXPECT_TRUE(delivery_timer()->IsRunning());
  delivery_timer()->Fire();
  ASSERT_EQ(1u, pending_uploads().size());

  // Resolve the first upload.
  pending_uploads()[0]->Complete(ReportingUploader::Outcome::SUCCESS);
  EXPECT_EQ(0u, pending_uploads().size());

  // Now the other upload can happen.
  EXPECT_TRUE(delivery_timer()->IsRunning());
  delivery_timer()->Fire();
  ASSERT_EQ(1u, pending_uploads().size());
  pending_uploads()[0]->Complete(ReportingUploader::Outcome::SUCCESS);
  EXPECT_EQ(0u, pending_uploads().size());

  // A total of 2 reports were uploaded.
  {
    ReportingEndpoint::Statistics stats =
        GetEndpointStatistics(kGroupKey_, kEndpoint_);
    ReportingEndpoint::Statistics different_stats =
        GetEndpointStatistics(kGroupKey_, kDifferentEndpoint);
    EXPECT_EQ(2, stats.attempted_uploads + different_stats.attempted_uploads);
    EXPECT_EQ(2, stats.successful_uploads + different_stats.successful_uploads);
    EXPECT_EQ(2, stats.attempted_reports + different_stats.attempted_reports);
    EXPECT_EQ(2, stats.successful_reports + different_stats.successful_reports);
  }
}