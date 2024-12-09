int ConvertFromYV12(const VideoFrame& src_frame,
                    VideoType dst_video_type,
                    int dst_sample_size,
                    uint8_t* dst_frame) {
  // YV12 = Y, V, U
  return libyuv::ConvertFromI420(src_frame.buffer(kYPlane),
                                 src_frame.stride(kYPlane),
                                 src_frame.buffer(kVPlane),
                                 src_frame.stride(kVPlane),
                                 src_frame.buffer(kUPlane),
                                 src_frame.stride(kUPlane),
                                 dst_frame, dst_sample_size,
                                 src_frame.width(), src_frame.height(),
                                 ConvertVideoType(dst_video_type));
}