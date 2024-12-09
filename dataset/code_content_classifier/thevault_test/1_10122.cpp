void DelayPeakDetector::SetPacketAudioLength(int length_ms) {
  if (length_ms > 0) {
    peak_detection_threshold_ = kPeakHeightMs / length_ms;
  }
}