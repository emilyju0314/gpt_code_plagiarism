inline void
  UContext::yield_until(libport::utime_t deadline) const
  {
    return ctx_->yield_until(deadline);
  }