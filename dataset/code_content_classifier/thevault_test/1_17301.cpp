static Value ReshapeSelectPredIfNecessary(OpBuilder *builder, Location loc,
                                          Value cond, int data_rank) {
  auto cond_tensor = cond.getType().cast<RankedTensorType>();
  // Reshape is only needed in the case that the cond rank is 1 (i.e. it is
  // a vector) AND t/e rank is > 1.
  if (cond_tensor.getRank() != 1 || data_rank <= 1) {
    // No reshape necessary. Leave cond as it is.
    return cond;
  }

  // This is the case where a reshape is needed. We want to construct the
  // shape [x,1,...1], where x is the value in the pred tensor and the
  // length of the shape is equal to data_rank.
  SmallVector<int64_t, 8> shape(data_rank, 1);
  shape[0] = cond_tensor.getShape().front();
  auto new_shape_type =
      RankedTensorType::get({data_rank}, builder->getIntegerType(64));
  auto shape_attr = DenseIntElementsAttr::get(new_shape_type, shape);
  auto new_shape = builder->create<ConstOp>(loc, shape_attr);
  return builder->create<ReshapeOp>(loc, cond, new_shape);
}