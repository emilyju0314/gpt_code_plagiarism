aomdv_rqueue::aomdv_rqueue() {
  head_ = tail_ = 0;
  len_ = 0;
  limit_ = AOMDV_RTQ_MAX_LEN;
  timeout_ = AOMDV_RTQ_TIMEOUT;
}