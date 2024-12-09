void TWERD::ComputeBoundingBoxes() {
  for (auto &blob : blobs) {
    blob->ComputeBoundingBoxes();
  }
}