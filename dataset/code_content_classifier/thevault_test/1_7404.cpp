std::pair<xla::Shape, xla::Shape> InferTriangularSolveShape(
    const xla::Shape& rhs_shape, const xla::Shape& lhs_shape) {
  // Obtain the number of right-hand sides, and dimension of the square matrix.
  xla::int64 nrhs = rhs_shape.dimensions(rhs_shape.rank() - 1);
  xla::int64 n = lhs_shape.dimensions(lhs_shape.rank() - 1);
  xla::Shape rhs_batch_shape(rhs_shape);
  xla::Shape lhs_batch_shape(lhs_shape);
  rhs_batch_shape.DeleteDimension(rhs_batch_shape.rank() - 1);
  lhs_batch_shape.DeleteDimension(lhs_batch_shape.rank() - 1);
  // If the shapes match in the batch dimensions, then we don't need to get
  // the promoted shape, and can directly add the trailing dimension.
  if (xla::ShapeUtil::Compatible(lhs_batch_shape, rhs_batch_shape)) {
    rhs_batch_shape.add_dimensions(nrhs);
    lhs_batch_shape.add_dimensions(n);
    xla::LayoutUtil::SetToDefaultLayout(&rhs_batch_shape);
    xla::LayoutUtil::SetToDefaultLayout(&lhs_batch_shape);
    return std::pair<xla::Shape, xla::Shape>(rhs_batch_shape, lhs_batch_shape);
  }
  // Obtain the promoted shapes and add back the trailing dimension.
  xla::Shape rhs_batch_promoted_shape =
      XlaHelpers::GetPromotedShape(rhs_batch_shape, lhs_batch_shape);
  xla::Shape lhs_batch_promoted_shape(rhs_batch_promoted_shape);
  rhs_batch_promoted_shape.add_dimensions(nrhs);
  lhs_batch_promoted_shape.add_dimensions(n);
  xla::LayoutUtil::SetToDefaultLayout(&rhs_batch_promoted_shape);
  xla::LayoutUtil::SetToDefaultLayout(&lhs_batch_promoted_shape);
  return std::pair<xla::Shape, xla::Shape>(rhs_batch_promoted_shape,
                                           lhs_batch_promoted_shape);
}