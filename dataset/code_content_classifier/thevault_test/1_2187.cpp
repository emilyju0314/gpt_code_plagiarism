void AmlogicVideo::SetDefaultInstance(std::unique_ptr<VideoDecoder> decoder, bool hevc) {
  DecoderCore* core = hevc ? hevc_core_.get() : vdec1_core_.get();
  assert(!stream_buffer_);
  assert(!current_instance_);
  current_instance_ = std::make_unique<DecoderInstance>(std::move(decoder), core);
  video_decoder_ = current_instance_->decoder();
  stream_buffer_ = current_instance_->stream_buffer();
  core_ = core;
  core_->PowerOn();
}