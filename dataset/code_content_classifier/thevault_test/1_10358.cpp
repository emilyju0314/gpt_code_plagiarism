void GetEncodingOfMat(const cv::Mat& mat, std::string* encoding) {
  ROS_ASSERT(encoding);
  if (mat.dims == 2) {

    // Check for all the generic type codes
#define CHECK_CV_TYPE(code)                            \
    if (mat.type() == CV_##code) *encoding = enc::TYPE_##code; 
  /***/
#define CHECK_CV_CHANNEL_TYPE(t)                   \
  CHECK_CV_TYPE(t##1);                         \
  CHECK_CV_TYPE(t##2);                         \
  CHECK_CV_TYPE(t##3);                         \
  CHECK_CV_TYPE(t##4);                         \
  /***/

    CHECK_CV_CHANNEL_TYPE(8UC);
    CHECK_CV_CHANNEL_TYPE(8SC);
    CHECK_CV_CHANNEL_TYPE(16UC);
    CHECK_CV_CHANNEL_TYPE(16SC);
    CHECK_CV_CHANNEL_TYPE(32SC);
    CHECK_CV_CHANNEL_TYPE(32FC);
    CHECK_CV_CHANNEL_TYPE(64FC);

#undef CHECK_CV_TYPE
#undef CHECK_CV_CHANNEL_TYPE

  } else if (mat.dims > 2) {
    // It's a multiple dimensional array so the encoding can only be
    // of basic types.
    if (mat.depth() == CV_8U) *encoding = enc::TYPE_8U;
    if (mat.depth() == CV_8S) *encoding = enc::TYPE_8S;
    if (mat.depth() == CV_16U) *encoding = enc::TYPE_16U;
    if (mat.depth() == CV_16S) *encoding = enc::TYPE_16S;
    if (mat.depth() == CV_32S) *encoding = enc::TYPE_32S;
    if (mat.depth() == CV_32F) *encoding = enc::TYPE_32F;
    if (mat.depth() == CV_64F) *encoding = enc::TYPE_64F;
  }
}