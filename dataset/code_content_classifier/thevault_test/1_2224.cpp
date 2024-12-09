zx_status_t Environment::CancelNotification(StationIfc* sta, uint64_t id) {
  for (auto& event_iter : events_) {
    if (event_iter->requester == sta && event_iter->id == id) {
      events_.remove(event_iter);
      return ZX_OK;
    }
  }
  return ZX_ERR_NOT_FOUND;
}