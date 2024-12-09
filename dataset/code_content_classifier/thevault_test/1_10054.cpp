TEST_F(ScreenshareLayerTestVP9, TimestampWrap) {
  InitScreenshareLayers(2);
  ConfigureBitrateForLayer(100, 0);

  expected_.layer[0].upd_buf = 0;
  expected_.layer[0].ref_buf1 = 0;
  expected_.layer[1].upd_buf = 1;
  expected_.layer[1].ref_buf1 = 1;
  expected_.start_layer = 0;
  expected_.stop_layer = 1;

  // Advance time to just before the timestamp wraps.
  AdvanceTime(std::numeric_limits<uint32_t>::max() / (kTickFrequency / 1000));
  EqualToExpected();
  AddKilobitsToLayer(200, 0);

  // Wrap
  expected_.start_layer = 1;
  AdvanceTime(1);
  EqualToExpected();
}