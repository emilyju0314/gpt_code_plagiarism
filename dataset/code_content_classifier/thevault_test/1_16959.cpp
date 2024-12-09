TEST_F(QbonePacketProcessorTest, FilterHelperFunctions) {
  auto filter_owned = std::make_unique<TestFilter>(client_ip_, network_ip_);
  TestFilter* filter = filter_owned.get();
  processor_->set_filter(std::move(filter_owned));

  EXPECT_CALL(stats_, OnPacketDroppedSilently(Direction::FROM_OFF_NETWORK));
  SendPacketFromClient(kReferenceClientPacket);
  ASSERT_EQ(1, filter->called());
}