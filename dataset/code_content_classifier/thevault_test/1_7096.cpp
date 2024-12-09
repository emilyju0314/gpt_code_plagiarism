int Fl::add_awake_handler_(Fl_Awake_Handler func, void *data)
{
  int ret = 0;
  lock_ring();
  if (!awake_ring_) {
    awake_ring_size_ = AWAKE_RING_SIZE;
    awake_ring_ = (Fl_Awake_Handler*)malloc(awake_ring_size_*sizeof(Fl_Awake_Handler));
    awake_data_ = (void**)malloc(awake_ring_size_*sizeof(void*));
  }
  if (awake_ring_head_==awake_ring_tail_-1 || awake_ring_head_+1==awake_ring_tail_) {
    // ring is full. Return -1 as an error indicator.
    ret = -1;
  } else {
    awake_ring_[awake_ring_head_] = func;
    awake_data_[awake_ring_head_] = data;
    ++awake_ring_head_;
    if (awake_ring_head_ == awake_ring_size_)
      awake_ring_head_ = 0;
  }
  unlock_ring();
  return ret;
}