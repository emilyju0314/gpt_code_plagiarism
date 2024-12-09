void ScrollView::StartEventHandler() {
  SVEvent *new_event;

  for (;;) {
    stream_->Flush();
    semaphore_->Wait();
    new_event = nullptr;
    int serial = -1;
    int k = -1;
    mutex_.lock();
    // Check every table entry if he is is valid and not already processed.

    for (int i = 0; i < SVET_COUNT; i++) {
      if (event_table_[i] != nullptr && (serial < 0 || event_table_[i]->counter < serial)) {
        new_event = event_table_[i];
        serial = event_table_[i]->counter;
        k = i;
      }
    }
    // If we didn't find anything we had an old alarm and just sleep again.
    if (new_event != nullptr) {
      event_table_[k] = nullptr;
      mutex_.unlock();
      if (event_handler_ != nullptr) {
        event_handler_->Notify(new_event);
      }
      if (new_event->type == SVET_DESTROY) {
        // Signal the destructor that it is safe to terminate.
        event_handler_ended_ = true;
        delete new_event; // Delete the pointer after it has been processed.
        return;
      }
      delete new_event; // Delete the pointer after it has been processed.
    } else {
      mutex_.unlock();
    }
    // The thread should run as long as its associated window is alive.
  }
}