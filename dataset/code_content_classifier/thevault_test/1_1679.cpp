static void UnsortedSegmentReductionValidation(OpKernel* op_kernel,
                                               OpKernelContext* context,
                                               const Tensor& data,
                                               const Tensor& segment_ids,
                                               const Tensor& num_segments) {
  OP_REQUIRES(
      context, op_kernel->IsLegacyScalar(num_segments.shape()),
      errors::InvalidArgument("num_segments should be a scalar, not shape ",
                              num_segments.shape().DebugString()));
  OP_REQUIRES(
      context, TensorShapeUtils::StartsWith(data.shape(), segment_ids.shape()),
      errors::InvalidArgument("data.shape = ", data.shape().DebugString(),
                              " does not start with segment_ids.shape = ",
                              segment_ids.shape().DebugString()));
}