TrainingSample *TrainingSample::DeSerializeCreate(bool swap, FILE *fp) {
  auto *sample = new TrainingSample;
  if (sample->DeSerialize(swap, fp)) {
    return sample;
  }
  delete sample;
  return nullptr;
}