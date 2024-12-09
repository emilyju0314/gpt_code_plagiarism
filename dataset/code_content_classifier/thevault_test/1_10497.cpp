int SampleIterator::UniformSamples() {
  int num_good_samples = 0;
  for (Begin(); !AtEnd(); Next()) {
    TrainingSample *sample = MutableSample();
    sample->set_weight(1.0);
    ++num_good_samples;
  }
  NormalizeSamples();
  return num_good_samples;
}