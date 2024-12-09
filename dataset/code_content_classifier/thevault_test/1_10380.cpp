TEST_F(TestReceiverThread, UniverseDataWaitsForPapAfterSamplingPeriod)
{
  RunThreadCycle();
  etcpal_getms_fake.return_val += (SACN_SAMPLE_TIME + 1u);
  RunThreadCycle();

  InitTestData(SACN_STARTCODE_DMX, kTestUniverse, kTestBuffer.data(), kTestBuffer.size());
  RunThreadCycle();
  EXPECT_EQ(universe_data_fake.call_count, 0u);

  for (int wait = 200; wait <= SACN_WAIT_FOR_PRIORITY; wait += 200)
  {
    etcpal_getms_fake.return_val += 200u;
    RunThreadCycle();
    EXPECT_EQ(universe_data_fake.call_count, 0u);
  }

  universe_data_fake.custom_fake = [](sacn_receiver_t, const EtcPalSockAddr*, const SacnRemoteSource*,
                                      const SacnRecvUniverseData* universe_data,
                                      void*) { EXPECT_EQ(universe_data->start_code, SACN_STARTCODE_PRIORITY); };

  InitTestData(SACN_STARTCODE_PRIORITY, kTestUniverse, kTestBuffer.data(), kTestBuffer.size());
  RunThreadCycle();
  EXPECT_EQ(universe_data_fake.call_count, 1u);

  universe_data_fake.custom_fake = [](sacn_receiver_t, const EtcPalSockAddr*, const SacnRemoteSource*,
                                      const SacnRecvUniverseData* universe_data,
                                      void*) { EXPECT_EQ(universe_data->start_code, SACN_STARTCODE_DMX); };

  InitTestData(SACN_STARTCODE_DMX, kTestUniverse, kTestBuffer.data(), kTestBuffer.size());
  RunThreadCycle();
  EXPECT_EQ(universe_data_fake.call_count, 2u);
}