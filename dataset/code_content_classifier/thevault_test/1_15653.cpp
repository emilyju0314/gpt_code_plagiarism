void AudioRecordJni::OnDataIsRecorded(int length) {
  DCHECK(thread_checker_java_.CalledOnValidThread());
  if (!audio_device_buffer_) {
    ALOGE("AttachAudioBuffer has not been called!");
    return;
  }
  if (playout_delay_in_milliseconds_ == 0) {
    playout_delay_in_milliseconds_ = delay_provider_->PlayoutDelayMs();
    ALOGD("cached playout delay: %d", playout_delay_in_milliseconds_);
  }
  audio_device_buffer_->SetRecordedBuffer(direct_buffer_address_,
                                          frames_per_buffer_);
  audio_device_buffer_->SetVQEData(playout_delay_in_milliseconds_,
                                   kHardwareDelayInMilliseconds,
                                   0 /* clockDrift */);
  if (audio_device_buffer_->DeliverRecordedData() == 1) {
    ALOGE("AudioDeviceBuffer::DeliverRecordedData failed!");
  }
}