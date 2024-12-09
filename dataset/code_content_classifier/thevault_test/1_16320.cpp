ObjectPackConsumerBase::BuildState ObjectPackConsumer::ConsumePayload(
  const unsigned buf_size,
  const unsigned char *buf)
{
  uint64_t pos_in_buf = 0;
  while ((pos_in_buf < buf_size) && (idx_ < index_.size())) {
    // Fill the accumulator or process next small object
    uint64_t nbytes;  // How many bytes are consumed in this iteration
    const uint64_t remaining_in_buf = buf_size - pos_in_buf;
    const uint64_t remaining_in_object = index_[idx_].size - pos_in_object_;
    const bool is_small_rest = remaining_in_buf < kAccuSize;

    // We use the accumulator if there is already something in or if we have a
    // small piece of data of a larger object.
    nbytes = std::min(remaining_in_object, remaining_in_buf);
    if ((pos_in_accu_ > 0) ||
        ((remaining_in_buf < remaining_in_object) && is_small_rest))
    {
      const uint64_t remaining_in_accu = kAccuSize - pos_in_accu_;
      nbytes = std::min(remaining_in_accu, nbytes);
      memcpy(accumulator_ + pos_in_accu_, buf + pos_in_buf, nbytes);
      pos_in_accu_ += nbytes;
      if ((pos_in_accu_ == kAccuSize) || (nbytes == remaining_in_object)) {
        NotifyListeners(BuildEvent(index_[idx_].id, index_[idx_].size,
                                   pos_in_accu_, accumulator_));
        pos_in_accu_ = 0;
      }
    } else {  // directly trigger listeners using buf
      NotifyListeners(BuildEvent(index_[idx_].id, index_[idx_].size,
                                 nbytes, buf + pos_in_buf));
    }

    pos_in_buf += nbytes;
    pos_in_object_ += nbytes;
    if (nbytes == remaining_in_object) {
      idx_++;
      pos_in_object_ = 0;
    }
  }

  pos_ += buf_size;

  if (idx_ == index_.size())
    state_ = (pos_in_buf == buf_size) ? kStateDone : kStateTrailingBytes;
  else
    state_ = kStateContinue;
  return state_;
}