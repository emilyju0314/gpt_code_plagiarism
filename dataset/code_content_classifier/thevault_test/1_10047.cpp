TEST(IntelligibilityUtilsTest, TestVarianceArray) {
  const int kFreqs = 10;
  const int kSamples = 100;
  const int kWindowSize = 10;  // Should pass for all kWindowSize > 1.
  const float kDecay = 0.5f;
  vector<VarianceArray::StepType> step_types;
  step_types.push_back(VarianceArray::kStepInfinite);
  step_types.push_back(VarianceArray::kStepDecaying);
  step_types.push_back(VarianceArray::kStepWindowed);
  step_types.push_back(VarianceArray::kStepBlocked);
  step_types.push_back(VarianceArray::kStepBlockBasedMovingAverage);
  const vector<vector<complex<float>>> test_data(
      GenerateTestData(kFreqs, kSamples));
  for (auto step_type : step_types) {
    VarianceArray variance_array(kFreqs, step_type, kWindowSize, kDecay);
    EXPECT_EQ(0, variance_array.variance()[0]);
    EXPECT_EQ(0, variance_array.array_mean());
    variance_array.ApplyScale(2.0f);
    EXPECT_EQ(0, variance_array.variance()[0]);
    EXPECT_EQ(0, variance_array.array_mean());

    // Makes sure Step is doing something.
    variance_array.Step(&test_data[0][0]);
    for (int i = 1; i < kSamples; i++) {
      variance_array.Step(&test_data[i][0]);
      EXPECT_GE(variance_array.array_mean(), 0.0f);
      EXPECT_LE(variance_array.array_mean(), 1.0f);
      for (int j = 0; j < kFreqs; j++) {
        EXPECT_GE(variance_array.variance()[j], 0.0f);
        EXPECT_LE(variance_array.variance()[j], 1.0f);
      }
    }
    variance_array.Clear();
    EXPECT_EQ(0, variance_array.variance()[0]);
    EXPECT_EQ(0, variance_array.array_mean());
  }
}