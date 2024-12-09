static LogicalResult Verify(BiasAddOp op) {
  StringRef format = op.data_format();
  if (format == "NHWC") {
    if (!HasRankAtLeast(op.value(), 2))
      return op.emitOpError(
          "requires value operand to have rank at least two with `NHWC` data "
          "format");
  } else {
    // Op definition requires data_format to be either NHWC or NCHW.
    DCHECK_EQ(format.str(), "NCHW");
    if (!HasRankAtLeast(op.value(), 3))
      return op.emitOpError(
          "requires value operand to have rank at least three with `NCHW` data "
          "format");
  }

  if (!IsOfRankOrUnranked(op.bias(), 1))
    return op.emitOpError("requires bias operand to have rank exactly one");

  RankedTensorType value_ty = op.value().getType().dyn_cast<RankedTensorType>();
  RankedTensorType bias_ty = op.bias().getType().dyn_cast<RankedTensorType>();
  if (!bias_ty || !value_ty) return success();

  // TODO(hinsu): Leverage tensor_format.h utility in TensorFlow to compute
  // dimension indices based on format.
  int64_t feature_dim_idx = format == "NHWC" ? value_ty.getRank() - 1 : 1;
  int64_t feature_dim = value_ty.getDimSize(feature_dim_idx);
  int64_t bias_len = bias_ty.getDimSize(0);
  if (feature_dim != -1 && bias_len != -1 && feature_dim != bias_len) {
    return op.emitOpError()
           << "requires channel dimension and feature dimension to match; "
              "found "
           << feature_dim << " and " << bias_len << ", respectively";
  }
  return success();
}