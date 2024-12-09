double I420PSNR(const VideoFrame* ref_frame, const VideoFrame* test_frame) {
  if (!ref_frame || !test_frame)
    return -1;
  else if ((ref_frame->width() !=  test_frame->width()) ||
          (ref_frame->height() !=  test_frame->height()))
    return -1;
  else if (ref_frame->width() < 0 || ref_frame->height() < 0)
    return -1;

  double psnr = libyuv::I420Psnr(ref_frame->buffer(kYPlane),
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
  // LibYuv sets the max psnr value to 128, we restrict it here.
  // In case of 0 mse in one frame, 128 can skew the results significantly.
  return (psnr > kPerfectPSNR) ? kPerfectPSNR : psnr;
}