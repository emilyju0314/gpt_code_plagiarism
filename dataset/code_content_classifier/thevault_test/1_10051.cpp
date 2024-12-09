int32_t VideoReceiveStream::Encoded(
    const EncodedImage& encoded_image,
    const CodecSpecificInfo* codec_specific_info,
    const RTPFragmentationHeader* fragmentation) {
  stats_proxy_->OnPreDecode(encoded_image, codec_specific_info);
  if (config_.pre_decode_callback) {
    // TODO(asapersson): Remove EncodedFrameCallbackAdapter.
    encoded_frame_proxy_.Encoded(
        encoded_image, codec_specific_info, fragmentation);
  }
  return 0;
}