void AudioOutput::SetupMixBuffer(uint32_t max_mix_frames) {
  TRACE_DURATION("audio", "AudioOutput::SetupMixBuffer");
  FX_DCHECK(mix_format_ && mix_format_->channels() > 0u);
  FX_DCHECK(max_mix_frames > 0u);
  FX_DCHECK(static_cast<uint64_t>(max_mix_frames) * mix_format_->channels() <=
            std::numeric_limits<uint32_t>::max());

  mix_buf_frames_ = max_mix_frames;
  mix_buf_ = std::make_unique<float[]>(mix_buf_frames_ * mix_format_->channels());
}