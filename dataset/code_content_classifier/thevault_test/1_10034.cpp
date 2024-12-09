TEST(DelayPeakDetector, TriggerPeakMode) {
  DelayPeakDetector detector;
  const int kPacketSizeMs = 30;
  detector.SetPacketAudioLength(kPacketSizeMs);

  // Load up normal arrival times; 0 ms, 30 ms, 60 ms, 90 ms, ...
  const int kNumPackets = 1000;
  int arrival_times_ms[kNumPackets];
  for (int i = 0; i < kNumPackets; ++i) {
    arrival_times_ms[i] = i * kPacketSizeMs;
  }

  // Delay three packets.
  const int kPeakDelayMs = 100;
  // First delay peak.
  arrival_times_ms[100] += kPeakDelayMs;
  // Second delay peak.
  arrival_times_ms[200] += kPeakDelayMs;
  // Third delay peak. Trigger peak-mode after this packet.
  arrival_times_ms[400] += kPeakDelayMs;
  // The second peak period is the longest, 200 packets.
  const int kWorstPeakPeriod = 200 * kPacketSizeMs;
  int peak_mode_start_ms = arrival_times_ms[400];
  // Expect to disengage after no peaks are observed for two period times.
  int peak_mode_end_ms = peak_mode_start_ms + 2 * kWorstPeakPeriod;

  // Load into detector.
  int time = 0;
  int next = 1;  // Start with the second packet to get a proper IAT.
  while (next < kNumPackets) {
    while (next < kNumPackets && arrival_times_ms[next] <= time) {
      int iat_packets = (arrival_times_ms[next] - arrival_times_ms[next - 1]) /
          kPacketSizeMs;
      const int kTargetBufferLevel = 1;  // Define peaks to be iat > 2.
      if (time < peak_mode_start_ms || time > peak_mode_end_ms) {
        EXPECT_FALSE(detector.Update(iat_packets, kTargetBufferLevel));
      } else {
        EXPECT_TRUE(detector.Update(iat_packets, kTargetBufferLevel));
        EXPECT_EQ(kWorstPeakPeriod, detector.MaxPeakPeriod());
        EXPECT_EQ(kPeakDelayMs / kPacketSizeMs + 1, detector.MaxPeakHeight());
      }
      ++next;
    }
    detector.IncrementCounter(10);
    time += 10;  // Increase time 10 ms.
  }
}