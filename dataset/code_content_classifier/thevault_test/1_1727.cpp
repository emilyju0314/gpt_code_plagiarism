int UrlLoopBuffer::WriteRecords(UrlRecord* records, int count) {
  int maxend = data_->begin - 1;
  if (maxend < 0) maxend += kUrlBufferSize;

  int i = 0;
  for (; i < count && data_->end != maxend; ++i) {
    data_->records[data_->end] = records[i];
    ++data_->end;
    if (data_->end >= kUrlBufferSize) {
      data_->end -= kUrlBufferSize;
    }
  }
  return i;
}