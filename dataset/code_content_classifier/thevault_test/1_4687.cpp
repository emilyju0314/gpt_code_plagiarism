void PerfEvent::Accept(PerfEventVisitor* visitor) const {
  std::visit([event_timestamp = timestamp,
              visitor](auto&& event_data) { visitor->Visit(event_timestamp, event_data); },
             data);
}