void FullyConnected::Forward(bool debug, const NetworkIO &input,
                             const TransposedArray *input_transpose, NetworkScratch *scratch,
                             NetworkIO *output) {
  int width = input.Width();
  if (type_ == NT_SOFTMAX) {
    output->ResizeFloat(input, no_);
  } else {
    output->Resize(input, no_);
  }
  SetupForward(input, input_transpose);
  std::vector<NetworkScratch::FloatVec> temp_lines(kNumThreads);
  std::vector<NetworkScratch::FloatVec> curr_input(kNumThreads);
  int ro = no_;
  if (IntSimdMatrix::intSimdMatrix) {
    ro = IntSimdMatrix::intSimdMatrix->RoundOutputs(ro);
  }
  for (int i = 0; i < kNumThreads; ++i) {
    temp_lines[i].Init(ro, scratch);
    curr_input[i].Init(ni_, scratch);
  }
#ifdef _OPENMP
#  pragma omp parallel for num_threads(kNumThreads)
  for (int t = 0; t < width; ++t) {
    // Thread-local pointer to temporary storage.
    int thread_id = omp_get_thread_num();
#else
  for (int t = 0; t < width; ++t) {
    // Thread-local pointer to temporary storage.
    int thread_id = 0;
#endif
    TFloat *temp_line = temp_lines[thread_id];
    if (input.int_mode()) {
      ForwardTimeStep(input.i(t), t, temp_line);
    } else {
      input.ReadTimeStep(t, curr_input[thread_id]);
      ForwardTimeStep(curr_input[thread_id], t, temp_line);
    }
    output->WriteTimeStep(t, temp_line);
    if (IsTraining() && type_ != NT_SOFTMAX) {
      acts_.CopyTimeStepFrom(t, *output, t);
    }
  }
  // Zero all the elements that are in the padding around images that allows
  // multiple different-sized images to exist in a single array.
  // acts_ is only used if this is not a softmax op.
  if (IsTraining() && type_ != NT_SOFTMAX) {
    acts_.ZeroInvalidElements();
  }
  output->ZeroInvalidElements();
#if DEBUG_DETAIL > 0
  tprintf("F Output:%s\n", name_.c_str());
  output->Print(10);
#endif
#ifndef GRAPHICS_DISABLED
  if (debug) {
    DisplayForward(*output);
  }
#endif
}