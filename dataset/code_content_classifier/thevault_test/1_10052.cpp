TEST_F(ScreenshareLayerTestVP9, DontAccumelateAvailableBitsOverTime) {
  InitScreenshareLayers(2);
  ConfigureBitrateForLayer(100, 0);

  expected_.layer[0].upd_buf = 0;
  expected_.layer[0].ref_buf1 = 0;
  expected_.layer[1].upd_buf = 1;
  expected_.layer[1].ref_buf1 = 1;
  expected_.start_layer = 0;
  expected_.stop_layer = 1;

  // Send 10 frames at a low bitrate (50 kbps)
  for (int i = 0; i < 10; ++i) {
    AdvanceTime(200);
    EqualToExpected();
    AddKilobitsToLayer(10, 0);
  }

  AdvanceTime(200);
  EqualToExpected();
  AddKilobitsToLayer(301, 0);

  // Send 10 frames at a high bitrate (200 kbps)
  expected_.start_layer = 1;
  for (int i = 0; i < 10; ++i) {
    AdvanceTime(200);
    EqualToExpected();
    AddKilobitsToLayer(40, 1);
  }
}