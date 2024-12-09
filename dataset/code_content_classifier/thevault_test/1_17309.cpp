static LogicalResult Verify(SizeOp op) {
  if (!HasRankAtMost(op.input(), std::numeric_limits<int32_t>::max()))
    return op.emitOpError(
        "requires ranked input tensor to be of rank INT32_MAX or less");

  return success();
}