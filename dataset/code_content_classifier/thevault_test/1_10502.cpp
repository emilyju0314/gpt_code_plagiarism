bool Reconfig::Backward(bool debug, const NetworkIO &fwd_deltas, NetworkScratch *scratch,
                        NetworkIO *back_deltas) {
  back_deltas->ResizeToMap(fwd_deltas.int_mode(), back_map_, ni_);
  StrideMap::Index src_index(fwd_deltas.stride_map());
  do {
    int in_t = src_index.t();
    StrideMap::Index dest_index(back_deltas->stride_map(), src_index.index(FD_BATCH),
                                src_index.index(FD_HEIGHT) * y_scale_,
                                src_index.index(FD_WIDTH) * x_scale_);
    // Unstack x_scale_ groups of y_scale_ inputs that are together.
    for (int x = 0; x < x_scale_; ++x) {
      for (int y = 0; y < y_scale_; ++y) {
        StrideMap::Index dest_xy(dest_index);
        if (dest_xy.AddOffset(x, FD_WIDTH) && dest_xy.AddOffset(y, FD_HEIGHT)) {
          back_deltas->CopyTimeStepGeneral(dest_xy.t(), 0, ni_, fwd_deltas, in_t,
                                           (x * y_scale_ + y) * ni_);
        }
      }
    }
  } while (src_index.Increment());
  return needs_to_backprop_;
}