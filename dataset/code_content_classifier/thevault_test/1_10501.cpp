void Reconfig::Forward(bool debug, const NetworkIO &input, const TransposedArray *input_transpose,
                       NetworkScratch *scratch, NetworkIO *output) {
  output->ResizeScaled(input, x_scale_, y_scale_, no_);
  back_map_ = input.stride_map();
  StrideMap::Index dest_index(output->stride_map());
  do {
    int out_t = dest_index.t();
    StrideMap::Index src_index(input.stride_map(), dest_index.index(FD_BATCH),
                               dest_index.index(FD_HEIGHT) * y_scale_,
                               dest_index.index(FD_WIDTH) * x_scale_);
    // Stack x_scale_ groups of y_scale_ inputs together.
    for (int x = 0; x < x_scale_; ++x) {
      for (int y = 0; y < y_scale_; ++y) {
        StrideMap::Index src_xy(src_index);
        if (src_xy.AddOffset(x, FD_WIDTH) && src_xy.AddOffset(y, FD_HEIGHT)) {
          output->CopyTimeStepGeneral(out_t, (x * y_scale_ + y) * ni_, ni_, input, src_xy.t(), 0);
        }
      }
    }
  } while (dest_index.Increment());
}