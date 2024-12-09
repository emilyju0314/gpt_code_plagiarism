TEST_F(MixingTest, FourChannelsWithOnlyThreeMixed) {
  const int16_t kInputValue = 1000;
  const int16_t kExpectedOutput = kInputValue * 3;
  RunMixingTest(4, 0, 4, false, kInputValue, 1.1 * kExpectedOutput,
                0.9 * kExpectedOutput, kCodecL16);
}