TEST(IntelligibilityUtilsTest, TestMovingBlockAverage) {
  // Exact, not unbiased estimates.
  const float kTestVarianceBufferNotFull = 16.5f;
  const float kTestVarianceBufferFull1 = 66.5f;
  const float kTestVarianceBufferFull2 = 333.375f;
  const int kFreqs = 2;
  const int kSamples = 50;
  const int kWindowSize = 2;
  const float kDecay = 0.5f;
  const float kMaxError = 0.0001f;

  VarianceArray variance_array(
      kFreqs, VarianceArray::kStepBlockBasedMovingAverage, kWindowSize, kDecay);

  vector<vector<complex<float>>> test_data(kSamples);
  for (int i = 0; i < kSamples; i++) {
    for (int j = 0; j < kFreqs; j++) {
      if (i < 30) {
        test_data[i].push_back(complex<float>(static_cast<float>(kSamples - i),
                                              static_cast<float>(i + 1)));
      } else {
        test_data[i].push_back(complex<float>(0.f, 0.f));
      }
    }
  }

  for (int i = 0; i < kSamples; i++) {
    variance_array.Step(&test_data[i][0]);
    for (int j = 0; j < kFreqs; j++) {
      if (i < 9) {  // In utils, kWindowBlockSize = 10.
        EXPECT_EQ(0, variance_array.variance()[j]);
      } else if (i < 19) {
        EXPECT_NEAR(kTestVarianceBufferNotFull, variance_array.variance()[j],
                    kMaxError);
      } else if (i < 39) {
        EXPECT_NEAR(kTestVarianceBufferFull1, variance_array.variance()[j],
                    kMaxError);
      } else if (i < 49) {
        EXPECT_NEAR(kTestVarianceBufferFull2, variance_array.variance()[j],
                    kMaxError);
      } else {
        EXPECT_EQ(0, variance_array.variance()[j]);
      }
    }
  }
}