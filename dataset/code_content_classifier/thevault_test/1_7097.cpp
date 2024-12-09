int Fl::get_awake_handler_(Fl_Awake_Handler &func, void *&data)
{
  int ret = 0;
  lock_ring();
  if (!awake_ring_ || awake_ring_head_ == awake_ring_tail_) {
    ret = -1;
  } else {
    func = awake_ring_[awake_ring_tail_];
    data = awake_data_[awake_ring_tail_];
    ++awake_ring_tail_;
    if (awake_ring_tail_ == awake_ring_size_)
      awake_ring_tail_ = 0;
  }
  unlock_ring();
  return ret;
}