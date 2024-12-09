TEST_F(ReportingDeliveryAgentTest, BatchReportsAcrossGroups) {
  static const std::string kDifferentGroup("group2");
  const ReportingEndpointGroupKey kDifferentGroupKey(kNik_, kOrigin_,
                                                     kDifferentGroup);

  ASSERT_TRUE(SetEndpointInCache(kGroupKey_, kEndpoint_, kExpires_));
  ASSERT_TRUE(SetEndpointInCache(kDifferentGroupKey, kEndpoint_, kExpires_));

  UploadFirstReportAndStartTimer();

  AddReport(kNik_, kUrl_, kGroup_);
  AddReport(kNik_, kUrl_, kDifferentGroup);

  EXPECT_TRUE(delivery_timer()->IsRunning());
  delivery_timer()->Fire();
  ASSERT_EQ(1u, pending_uploads().size());
  pending_uploads()[0]->Complete(ReportingUploader::Outcome::SUCCESS);
  EXPECT_EQ(0u, pending_uploads().size());

  {
    ReportingEndpoint::Statistics stats =
        GetEndpointStatistics(kGroupKey_, kEndpoint_);
    EXPECT_EQ(1, stats.attempted_uploads);
    EXPECT_EQ(1, stats.successful_uploads);
    EXPECT_EQ(1, stats.attempted_reports);
    EXPECT_EQ(1, stats.successful_reports);
  }
  {
    ReportingEndpoint::Statistics stats =
        GetEndpointStatistics(kDifferentGroupKey, kEndpoint_);
    EXPECT_EQ(1, stats.attempted_uploads);
    EXPECT_EQ(1, stats.successful_uploads);
    EXPECT_EQ(1, stats.attempted_reports);
    EXPECT_EQ(1, stats.successful_reports);
  }
}