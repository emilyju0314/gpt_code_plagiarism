UrlRecord* UrlLoopBuffer::GetRecord(int index) {
  // Normalize the index.
  index += data_->begin;
  if (index >= kUrlBufferSize) {
    index -= kUrlBufferSize;
  }

  // Validate the index.
  if (index < 0 || index >= kUrlBufferSize) {
    return NULL;
  }

  return &(data_->records[index]);
}