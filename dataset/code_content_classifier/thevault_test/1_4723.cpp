std::optional<DiscardedPerfEvent> PerfEventProcessor::HandleOutOfOrderEvent(
    uint64_t event_timestamp_ns) {
  const uint64_t discarded_begin = event_timestamp_ns;
  const uint64_t discarded_end = last_processed_timestamp_ns_;

  std::optional<DiscardedPerfEvent> optional_discarded_event = std::nullopt;

  CHECK(discarded_end >= last_discarded_end_);
  if (discarded_end == last_discarded_end_ && discarded_begin < last_discarded_begin_) {
    optional_discarded_event = optional_discarded_event = DiscardedPerfEvent{
        .timestamp = discarded_end,
        .data = {.begin_timestamp_ns = discarded_begin},
    };
    last_discarded_begin_ = discarded_begin;
  } else if (discarded_end == last_discarded_end_ && discarded_begin >= last_discarded_begin_) {
    // This is the only case that doesn't generate a DiscardedPerfEvent.
  } else if (discarded_end > last_discarded_end_ && discarded_begin < last_discarded_begin_) {
    optional_discarded_event = DiscardedPerfEvent{
        .timestamp = discarded_end,
        .data = {.begin_timestamp_ns = discarded_begin},
    };
    last_discarded_begin_ = discarded_begin;
  } else if (discarded_end > last_discarded_end_ && discarded_begin <= last_discarded_end_) {
    optional_discarded_event = DiscardedPerfEvent{
        .timestamp = discarded_end,
        .data = {.begin_timestamp_ns = discarded_begin},
    };
    // Don't update last_discarded_begin_.
  } else if (discarded_end > last_discarded_end_ && discarded_begin > last_discarded_end_) {
    optional_discarded_event = DiscardedPerfEvent{
        .timestamp = discarded_end,
        .data = {.begin_timestamp_ns = discarded_begin},
    };
    last_discarded_begin_ = discarded_begin;
  } else {
    UNREACHABLE();
  }

  last_discarded_end_ = discarded_end;

  // The timestamp of DiscardedPerfEvent is last_processed_timestamp_ns_, so the event can be
  // processed and it will probably be processed next.
  return optional_discarded_event;
}