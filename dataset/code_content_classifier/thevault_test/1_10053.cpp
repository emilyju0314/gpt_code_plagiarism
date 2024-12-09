TEST_F(ScreenshareLayerTestVP9, AccumelateUsedBitsOverLayers) {
  const int kNumLayers = kMaxVp9NumberOfSpatialLayers;
  InitScreenshareLayers(kNumLayers);
  for (int l = 0; l < kNumLayers - 1; ++l)
    ConfigureBitrateForLayer(100, l);
  for (int l = 0; l < kNumLayers; ++l) {
    expected_.layer[l].upd_buf = l;
    expected_.layer[l].ref_buf1 = l;
  }

  expected_.start_layer = 0;
  expected_.stop_layer = kNumLayers - 1;
  EqualToExpected();

  for (int layer = 0; layer < kNumLayers - 1; ++layer) {
    expected_.start_layer = layer;
    EqualToExpected();
    AddKilobitsToLayer(101, layer);
  }
}