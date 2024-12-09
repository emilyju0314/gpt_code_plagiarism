bool Parallel::Backward(bool debug, const NetworkIO &fwd_deltas, NetworkScratch *scratch,
                        NetworkIO *back_deltas) {
  // If this parallel is a replicator of convolvers, or holds a 1-d LSTM pair,
  // or a 2-d LSTM quad, do debug locally, and don't pass the flag on.
  if (debug && type_ != NT_PARALLEL) {
#ifndef GRAPHICS_DISABLED
    DisplayBackward(fwd_deltas);
#endif
    debug = false;
  }
  auto stack_size = stack_.size();
  if (type_ == NT_PAR_2D_LSTM) {
    // Special case, run parallel in parallel.
    std::vector<NetworkScratch::IO> in_deltas(stack_size);
    std::vector<NetworkScratch::IO> out_deltas(stack_size);
    // Split the forward deltas for each stack element.
    int feature_offset = 0;
    for (unsigned i = 0; i < stack_.size(); ++i) {
      int num_features = stack_[i]->NumOutputs();
      in_deltas[i].Resize(fwd_deltas, num_features, scratch);
      out_deltas[i].Resize(fwd_deltas, stack_[i]->NumInputs(), scratch);
      in_deltas[i]->CopyUnpacking(fwd_deltas, feature_offset, num_features);
      feature_offset += num_features;
    }
#ifdef _OPENMP
#  pragma omp parallel for num_threads(stack_size)
#endif
    for (unsigned i = 0; i < stack_size; ++i) {
      stack_[i]->Backward(debug, *in_deltas[i], scratch, i == 0 ? back_deltas : out_deltas[i]);
    }
    if (needs_to_backprop_) {
      for (unsigned i = 1; i < stack_size; ++i) {
        back_deltas->AddAllToFloat(*out_deltas[i]);
      }
    }
  } else {
    // Revolving partial deltas.
    NetworkScratch::IO in_deltas(fwd_deltas, scratch);
    // The sum of deltas from different sources, which will eventually go into
    // back_deltas.
    NetworkScratch::IO out_deltas;
    int feature_offset = 0;
    for (unsigned i = 0; i < stack_.size(); ++i) {
      int num_features = stack_[i]->NumOutputs();
      in_deltas->CopyUnpacking(fwd_deltas, feature_offset, num_features);
      feature_offset += num_features;
      if (stack_[i]->Backward(debug, *in_deltas, scratch, back_deltas)) {
        if (i == 0) {
          out_deltas.ResizeFloat(*back_deltas, back_deltas->NumFeatures(), scratch);
          out_deltas->CopyAll(*back_deltas);
        } else if (back_deltas->NumFeatures() == out_deltas->NumFeatures()) {
          // Widths are allowed to be different going back, as we may have
          // input nets, so only accumulate the deltas if the widths are the
          // same.
          out_deltas->AddAllToFloat(*back_deltas);
        }
      }
    }
    if (needs_to_backprop_) {
      back_deltas->CopyAll(*out_deltas);
    }
  }
  if (needs_to_backprop_) {
    back_deltas->ScaleFloatBy(1.0f / stack_size);
  }
  return needs_to_backprop_;
}