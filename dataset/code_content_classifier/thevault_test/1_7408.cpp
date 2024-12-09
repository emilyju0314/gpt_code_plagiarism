BatchInput CreateBatchInput(xla::XlaOp input, xla::int64 spatial_dim_count) {
  const xla::Shape& input_shape = XlaHelpers::ShapeOfXlaOp(input);
  xla::int64 rank = input_shape.rank();
  XLA_CHECK(rank == spatial_dim_count + 1 || rank == spatial_dim_count + 2)
      << "Input must be a " << spatial_dim_count + 1 << "-D or "
      << spatial_dim_count + 2 << "-D tensor";
  if (rank == spatial_dim_count + 1) {
    return {BuildUnsqueeze(input, 0), rank};
  }
  return {input, rank};
}