void Parallel::Forward(bool debug, const NetworkIO &input, const TransposedArray *input_transpose,
                       NetworkScratch *scratch, NetworkIO *output) {
  bool parallel_debug = false;
  // If this parallel is a replicator of convolvers, or holds a 1-d LSTM pair,
  // or a 2-d LSTM quad, do debug locally, and don't pass the flag on.
  if (debug && type_ != NT_PARALLEL) {
    parallel_debug = true;
    debug = false;
  }
  int stack_size = stack_.size();
  if (type_ == NT_PAR_2D_LSTM) {
    // Special case, run parallel in parallel.
    std::vector<NetworkScratch::IO> results(stack_size);
    for (int i = 0; i < stack_size; ++i) {
      results[i].Resize(input, stack_[i]->NumOutputs(), scratch);
    }
#ifdef _OPENMP
#  pragma omp parallel for num_threads(stack_size)
#endif
    for (int i = 0; i < stack_size; ++i) {
      stack_[i]->Forward(debug, input, nullptr, scratch, results[i]);
    }
    // Now pack all the results (serially) into the output.
    int out_offset = 0;
    output->Resize(*results[0], NumOutputs());
    for (int i = 0; i < stack_size; ++i) {
      out_offset = output->CopyPacking(*results[i], out_offset);
    }
  } else {
    // Revolving intermediate result.
    NetworkScratch::IO result(input, scratch);
    // Source for divided replicated.
    NetworkScratch::IO source_part;
    TransposedArray *src_transpose = nullptr;
    if (IsTraining() && type_ == NT_REPLICATED) {
      // Make a transposed copy of the input.
      input.Transpose(&transposed_input_);
      src_transpose = &transposed_input_;
    }
    // Run each network, putting the outputs into result.
    int out_offset = 0;
    for (int i = 0; i < stack_size; ++i) {
      stack_[i]->Forward(debug, input, src_transpose, scratch, result);
      // All networks must have the same output width
      if (i == 0) {
        output->Resize(*result, NumOutputs());
      } else {
        ASSERT_HOST(result->Width() == output->Width());
      }
      out_offset = output->CopyPacking(*result, out_offset);
    }
  }
#ifndef GRAPHICS_DISABLED
  if (parallel_debug) {
    DisplayForward(*output);
  }
#endif
}