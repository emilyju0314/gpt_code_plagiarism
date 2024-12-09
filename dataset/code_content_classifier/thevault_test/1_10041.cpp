TEST_F(MixingTest, VerifySaturationProtection) {
  const int16_t kInputValue = 20000;
  const int16_t kExpectedOutput = kLimiterHeadroom;
  // If this isn't satisfied, we're not testing anything.
  ASSERT_GT(kInputValue * 3, kInt16Max);
  ASSERT_LT(1.1 * kExpectedOutput, kInt16Max);
  RunMixingTest(3, 0, 3, false, kInputValue, 1.1 * kExpectedOutput,
               0.9 * kExpectedOutput, kCodecL16);
}