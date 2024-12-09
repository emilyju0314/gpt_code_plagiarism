MediaTransportEncodedAudioFrame CreateAudioFrame(int sequence_number) {
  static constexpr int kSamplingRateHz = 48000;
  static constexpr int kStartingSampleIndex = 0;
  static constexpr int kSamplesPerChannel = 480;
  static constexpr uint8_t kPayloadType = 17;

  return MediaTransportEncodedAudioFrame(
      kSamplingRateHz, kStartingSampleIndex, kSamplesPerChannel,
      sequence_number, MediaTransportEncodedAudioFrame::FrameType::kSpeech,
      kPayloadType, std::vector<uint8_t>(kSamplesPerChannel));
}