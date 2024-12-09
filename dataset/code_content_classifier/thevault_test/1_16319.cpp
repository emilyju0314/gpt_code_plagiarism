ObjectPackConsumerBase::BuildState ObjectPackConsumer::ConsumeNext(
  const unsigned buf_size,
  const unsigned char *buf)
{
  if (buf_size == 0)
    return state_;
  if (state_ == kStateDone) {
    state_ = kStateTrailingBytes;
    return state_;
  }
  if (state_ != kStateContinue)
    return state_;

  const unsigned remaining_in_header =
    (pos_ < expected_header_size_) ? (expected_header_size_ - pos_) : 0;
  const unsigned nbytes_header = std::min(remaining_in_header, buf_size);
  if (nbytes_header) {
    raw_header_ += string(reinterpret_cast<const char *>(buf), nbytes_header);
    pos_ += nbytes_header;
  }

  if (pos_ < expected_header_size_)
    return kStateContinue;

  // This condition can only be true once through the lifetime of the Consumer.
  if (nbytes_header && (pos_ == expected_header_size_)) {
    shash::Any digest(expected_digest_.algorithm);
    shash::HashString(raw_header_, &digest);
    if (digest != expected_digest_) {
      state_ = kStateCorrupt;
      return state_;
    } else {
      bool retval = ParseHeader();
      if (!retval) {
        state_ = kStateBadFormat;
        return state_;
      }
      // We don't need the raw string anymore
      raw_header_.clear();
    }

    // Empty pack?
    if ((buf_size == nbytes_header) && (index_.size() == 0)) {
      state_ = kStateDone;
      return state_;
    }
  }

  unsigned remaining_in_buf = buf_size - nbytes_header;
  const unsigned char *payload = buf + nbytes_header;
  return ConsumePayload(remaining_in_buf, payload);
}