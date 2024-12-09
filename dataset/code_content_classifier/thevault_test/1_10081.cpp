double I420SSIM(const VideoFrame* ref_frame, const VideoFrame* test_frame) {
  if (!ref_frame || !test_frame)
    return -1;
  else if ((ref_frame->width() !=  test_frame->width()) ||
          (ref_frame->height() !=  test_frame->height()))
    return -1;
  else if (ref_frame->width() < 0 || ref_frame->height()  < 0)
    return -1;

  return libyuv::I420Ssim(ref_frame->buffer(kYPlane),
                          ref_frame->stride(kYPlane),
                          ref_frame->buffer(kUPlane),
                          ref_frame->stride(kUPlane),
                          ref_frame->buffer(kVPlane),
                          ref_frame->stride(kVPlane),
                          test_frame->buffer(kYPlane),
                          test_frame->stride(kYPlane),
                          test_frame->buffer(kUPlane),
                          test_frame->stride(kUPlane),
                          test_frame->buffer(kVPlane),
                          test_frame->stride(kVPlane),
                          test_frame->width(), test_frame->height());
}