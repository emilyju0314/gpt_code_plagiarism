void WERD_RES::InitForRetryRecognition(const WERD_RES &source) {
  word = source.word;
  CopySimpleFields(source);
  if (source.blamer_bundle != nullptr) {
    blamer_bundle = new BlamerBundle();
    blamer_bundle->CopyTruth(*source.blamer_bundle);
  }
}