TrainingSample *TrainingSample::RandomizedCopy(int index) const {
  TrainingSample *sample = Copy();
  if (index >= 0 && index < kSampleRandomSize) {
    ++index; // Remove the first combination.
    const int yshift = kYShiftValues[index / kSampleScaleSize];
    double scaling = kScaleValues[index % kSampleScaleSize];
    for (uint32_t i = 0; i < num_features_; ++i) {
      double result = (features_[i].X - kRandomizingCenter) * scaling;
      result += kRandomizingCenter;
      sample->features_[i].X = ClipToRange<int>(result + 0.5, 0, UINT8_MAX);
      result = (features_[i].Y - kRandomizingCenter) * scaling;
      result += kRandomizingCenter + yshift;
      sample->features_[i].Y = ClipToRange<int>(result + 0.5, 0, UINT8_MAX);
    }
  }
  return sample;
}