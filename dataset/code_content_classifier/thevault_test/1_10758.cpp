SVEvent *ScrollView::AwaitEvent(SVEventType type) {
  // Initialize the waiting semaphore.
  auto *sem = new SVSemaphore();
  std::pair<ScrollView *, SVEventType> ea(this, type);
  waiting_for_events_mu->lock();
  waiting_for_events[ea] = std::pair<SVSemaphore *, SVEvent *>(sem, (SVEvent *)nullptr);
  waiting_for_events_mu->unlock();
  // Wait on it, but first flush.
  stream_->Flush();
  sem->Wait();
  // Process the event we got woken up for (its in waiting_for_events pair).
  waiting_for_events_mu->lock();
  SVEvent *ret = waiting_for_events[ea].second;
  waiting_for_events.erase(ea);
  delete sem;
  waiting_for_events_mu->unlock();
  return ret;
}