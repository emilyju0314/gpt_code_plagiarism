static void computeBatchSizes(GLConvolution::descriptor& geometry,
                              int& input_batch_size,
                              int& output_batch_size) {
  int kernel_size = std::max(geometry.kernel_size.x, geometry.kernel_size.y);
  int input_slices = (geometry.input_channels + 3) / 4;
  int output_slices = (geometry.output_channels + 3) / 4;

#if CAFFE2_ANDROID
  input_batch_size = input_slices % 2 == 0 ? 2 : 1;
  output_batch_size = output_slices % 2 == 0 ? 2 : 1;
#else
  if (iPhoneVersion() >= 8) {
    // iPhone 6S and up
    input_batch_size =
        input_slices % 8 == 0
            ? 8
            : input_slices % 4 == 0 ? 4 : input_slices % 3 == 0 ? 3 : input_slices % 2 == 0 ? 2 : 1;
    output_batch_size =
        output_slices % 4 == 0 ? 4 : output_slices % 3 == 0 ? 3 : output_slices % 2 == 0 ? 2 : 1;
  }
#endif
}