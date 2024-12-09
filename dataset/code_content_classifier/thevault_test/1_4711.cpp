void VerifyEventCounts(const std::vector<ProducerCaptureEvent>& events, size_t expected_counts) {
  constexpr size_t kEventCountsErrorTolerance = 2;

  size_t num_received_events = 0;
  for (const auto& event : events) {
    if (event.event_case() == ProducerCaptureEvent::kMemoryUsageEvent) num_received_events++;
  }

  EXPECT_GE(num_received_events, expected_counts - kEventCountsErrorTolerance);
}