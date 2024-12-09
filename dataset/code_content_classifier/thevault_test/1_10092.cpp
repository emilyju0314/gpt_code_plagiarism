int32_t VPMDeflickering::DetectFlicker() {
  uint32_t i;
  int32_t freqEst;  // (Q4) Frequency estimate to base detection upon
  int32_t ret_val = -1;

  /* Sanity check for mean_buffer_length_ */
  if (mean_buffer_length_ < 2) {
    /* Not possible to estimate frequency */
    return 2;
  }
  // Count zero crossings with a dead zone to be robust against noise. If the
  // noise std is 2 pixel this corresponds to about 95% confidence interval.
  int32_t deadzone = (kZeroCrossingDeadzone << kmean_valueScaling);  // Q4
  int32_t meanOfBuffer = 0;  // Mean value of mean value buffer.
  int32_t numZeros = 0;      // Number of zeros that cross the dead-zone.
  int32_t cntState = 0;      // State variable for zero crossing regions.
  int32_t cntStateOld = 0;   // Previous state for zero crossing regions.

  for (i = 0; i < mean_buffer_length_; i++) {
    meanOfBuffer += mean_buffer_[i];
  }
  meanOfBuffer += (mean_buffer_length_ >> 1);  // Rounding, not truncation.
  meanOfBuffer /= mean_buffer_length_;

  // Count zero crossings.
  cntStateOld = (mean_buffer_[0] >= (meanOfBuffer + deadzone));
  cntStateOld -= (mean_buffer_[0] <= (meanOfBuffer - deadzone));
  for (i = 1; i < mean_buffer_length_; i++) {
    cntState = (mean_buffer_[i] >= (meanOfBuffer + deadzone));
    cntState -= (mean_buffer_[i] <= (meanOfBuffer - deadzone));
    if (cntStateOld == 0) {
      cntStateOld = -cntState;
    }
    if (((cntState + cntStateOld) == 0) && (cntState != 0)) {
      numZeros++;
      cntStateOld = cntState;
    }
  }
  // END count zero crossings.

  /* Frequency estimation according to:
  * freqEst = numZeros * frame_rate / 2 / mean_buffer_length_;
  *
  * Resolution is set to Q4
  */
  freqEst = ((numZeros * 90000) << 3);
  freqEst /=
      (timestamp_buffer_[0] - timestamp_buffer_[mean_buffer_length_ - 1]);

  /* Translate frequency estimate to regions close to 100 and 120 Hz */
  uint8_t freqState = 0;  // Current translation state;
                          // (0) Not in interval,
                          // (1) Within valid interval,
                          // (2) Out of range
  int32_t freqAlias = freqEst;
  if (freqEst > kMinFrequencyToDetect) {
    uint8_t aliasState = 1;
    while (freqState == 0) {
      /* Increase frequency */
      freqAlias += (aliasState * frame_rate_);
      freqAlias += ((freqEst << 1) * (1 - (aliasState << 1)));
      /* Compute state */
      freqState = (abs(freqAlias - (100 << 4)) <= kFrequencyDeviation);
      freqState += (abs(freqAlias - (120 << 4)) <= kFrequencyDeviation);
      freqState += 2 * (freqAlias > ((120 << 4) + kFrequencyDeviation));
      /* Switch alias state */
      aliasState++;
      aliasState &= 0x01;
    }
  }
  /* Is frequency estimate within detection region? */
  if (freqState == 1) {
    ret_val = 1;
  } else if (freqState == 0) {
    ret_val = 2;
  } else {
    ret_val = 0;
  }
  return ret_val;
}