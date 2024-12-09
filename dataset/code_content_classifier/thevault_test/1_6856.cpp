void
TrafficSource::place() {
  if (previous_) {
    placeNextTo(previous_);
  } else {
    placeOnAgent();
  }
}