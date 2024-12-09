unsigned ObjectPackProducer::ProduceNext(
  const unsigned buf_size,
  unsigned char *buf)
{
  const unsigned remaining_in_header =
    (pos_ < header_.size()) ? (header_.size() - pos_) : 0;
  const unsigned nbytes_header = std::min(remaining_in_header, buf_size);
  if (nbytes_header) {
    memcpy(buf, header_.data() + pos_, nbytes_header);
    pos_ += nbytes_header;
  }

  unsigned remaining_in_buf = buf_size - nbytes_header;
  if (remaining_in_buf == 0)
    return nbytes_header;
  unsigned nbytes_payload = 0;

  if (big_file_) {
    size_t nbytes = fread(buf + nbytes_header, 1, remaining_in_buf, big_file_);
    nbytes_payload = nbytes;
    pos_ += nbytes_payload;
  } else if (idx_ < pack_->buckets_.size()) {
    // Copy a few buckets more
    while ((remaining_in_buf) > 0 && (idx_ < pack_->buckets_.size())) {
      const unsigned remaining_in_bucket =
        pack_->buckets_[idx_]->size - pos_in_bucket_;
      const unsigned nbytes = std::min(remaining_in_buf, remaining_in_bucket);
      memcpy(buf + nbytes_header + nbytes_payload,
             pack_->buckets_[idx_]->content + pos_in_bucket_,
             nbytes);

      pos_in_bucket_ += nbytes;
      nbytes_payload += nbytes;
      remaining_in_buf -= nbytes;
      if (nbytes == remaining_in_bucket) {
        pos_in_bucket_ = 0;
        idx_++;
      }
    }
  }

  return nbytes_header + nbytes_payload;
}