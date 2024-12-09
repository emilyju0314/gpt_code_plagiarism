TEST_F(AudioRendererImplTest, MinLeadTimePadding) {
  auto fake_output = testing::FakeAudioOutput::Create(&threading_model(), &device_registry_);

  // We must set our output's lead time, before linking it, before calling SetPcmStreamType().
  fake_output->SetMinLeadTime(kMinLeadTime);

  // Our RouteGraph links one FakeAudioOutput to the Renderer-under-test. Thus we can set our
  // output's MinLeadTime, fully expecting this value to be reflected as-is to renderer+clients.
  route_graph_.AddRenderer(renderer_);
  route_graph_.AddOutput(fake_output.get());

  // SetPcmStreamType triggers the routing preparation completion, which connects output(s) to
  // renderer. Renderers react to new outputs in `OnLinkAdded` by recalculating minimum lead time.
  SetPcmStreamType();

  auto lead_time_ns = kInvalidLeadTimeNs;
  renderer_->GetMinLeadTime(
      [&lead_time_ns](int64_t received_lead_time_ns) { lead_time_ns = received_lead_time_ns; });

  RunLoopUntilIdle();
  ASSERT_NE(lead_time_ns, kInvalidLeadTimeNs) << "No response received for GetMinLeadTime";
  EXPECT_EQ(lead_time_ns, kMinLeadTime.to_nsecs()) << "Incorrect GetMinLeadTime received";
}