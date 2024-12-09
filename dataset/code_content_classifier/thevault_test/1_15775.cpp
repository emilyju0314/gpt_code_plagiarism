void AudioBuffer::Mix(int num_mixed_channels) {
  // We currently only support the stereo to mono case.
  assert(num_channels_ == 2);
  assert(num_mixed_channels == 1);

  StereoToMono(channels_[0].data,
               channels_[1].data,
               channels_[0].data,
               samples_per_channel_);

  num_channels_ = num_mixed_channels;
  data_was_mixed_ = true;
}