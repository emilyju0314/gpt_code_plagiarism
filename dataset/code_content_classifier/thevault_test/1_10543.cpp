TEST_F(LSTMTrainerTest, TestLayerAccess) {
  // A 2-layer LSTM with a Squashed feature-extracting LSTM on the bottom.
  SetupTrainerEng("[1,32,0,1 Ct5,5,16 Mp2,2 Lfys32 Lbx128 O1c1]", "SQU-lstm", false, false);
  // Number of layers.
  const size_t kNumLayers = 8;
  // Expected layer names.
  const char *kLayerIds[kNumLayers] = {":0", ":1:0", ":1:1", ":2", ":3:0", ":4:0", ":4:1:0", ":5"};
  const char *kLayerNames[kNumLayers] = {"Input",  "Convolve",  "ConvNL", "Maxpool",
                                         "Lfys32", "Lbx128LTR", "Lbx128", "Output"};
  // Expected number of weights.
  const int kNumWeights[kNumLayers] = {0,
                                       0,
                                       16 * (25 + 1),
                                       0,
                                       32 * (4 * (32 + 16 + 1)),
                                       128 * (4 * (128 + 32 + 1)),
                                       128 * (4 * (128 + 32 + 1)),
                                       112 * (2 * 128 + 1)};

  auto layers = trainer_->EnumerateLayers();
  EXPECT_EQ(kNumLayers, layers.size());
  for (unsigned i = 0; i < kNumLayers && i < layers.size(); ++i) {
    EXPECT_STREQ(kLayerIds[i], layers[i].c_str());
    EXPECT_STREQ(kLayerNames[i], trainer_->GetLayer(layers[i])->name().c_str());
    EXPECT_EQ(kNumWeights[i], trainer_->GetLayer(layers[i])->num_weights());
  }
}