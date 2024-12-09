int WERD_RES::GetBlobsWidth(int start_blob, int last_blob) const {
  int result = 0;
  for (int b = start_blob; b <= last_blob; ++b) {
    result += blob_widths[b];
    if (b < last_blob) {
      result += blob_gaps[b];
    }
  }
  return result;
}