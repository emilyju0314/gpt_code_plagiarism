double SampleIterator::NormalizeSamples() {
  double total_weight = 0.0;
  int sample_count = 0;
  for (Begin(); !AtEnd(); Next()) {
    const TrainingSample &sample = GetSample();
    total_weight += sample.weight();
    ++sample_count;
  }
  // Normalize samples.
  double min_assigned_sample_weight = 1.0;
  if (total_weight > 0.0) {
    for (Begin(); !AtEnd(); Next()) {
      TrainingSample *sample = MutableSample();
      double weight = sample->weight() / total_weight;
      if (weight < min_assigned_sample_weight) {
        min_assigned_sample_weight = weight;
      }
      sample->set_weight(weight);
    }
  }
  return min_assigned_sample_weight;
}