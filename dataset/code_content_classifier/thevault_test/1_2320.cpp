bool MsdVslDevice::WriteInterruptEvent(uint32_t event_id,
                                       std::shared_ptr<magma::PlatformSemaphore> signal) {
  std::lock_guard<std::mutex> lock(events_mutex_);

  if (event_id >= kNumEvents) {
    return DRETF(false, "Invalid event id %u", event_id);
  }
  if (!events_[event_id].allocated) {
    return DRETF(false, "Event id %u was not allocated", event_id);
  }
  if (events_[event_id].submitted) {
    return DRETF(false, "Event id %u was already submitted", event_id);
  }
  events_[event_id].submitted = true;
  events_[event_id].signal = signal;
  MiEvent::write(ringbuffer_.get(), event_id);
  return true;
}