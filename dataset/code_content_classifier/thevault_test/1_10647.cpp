BLOB_CHOICE_LIST *Wordrec::call_matcher(TBLOB *tessblob) {
  // Rotate the blob for classification if necessary.
  TBLOB *rotated_blob = tessblob->ClassifyNormalizeIfNeeded();
  if (rotated_blob == nullptr) {
    rotated_blob = tessblob;
  }
  auto *ratings = new BLOB_CHOICE_LIST(); // matcher result
  AdaptiveClassifier(rotated_blob, ratings);
  if (rotated_blob != tessblob) {
    delete rotated_blob;
  }
  return ratings;
}