int WERD_RES::GetBlobsGap(unsigned blob_index) const {
  if (blob_index >= blob_gaps.size()) {
    return 0;
  }
  return blob_gaps[blob_index];
}