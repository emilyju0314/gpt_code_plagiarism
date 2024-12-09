static Type InferReductionOpType(Value input, Value reduction_indices,
                                 BoolAttr keep_dims, Builder *builder) {
  Type input_ty = input.getType();
  Type element_ty = getElementTypeOrSelf(input_ty);

  // Output type is unranked if input type is not ranked.
  auto ranked_ty = input_ty.dyn_cast<RankedTensorType>();
  if (!ranked_ty) return UnrankedTensorType::get(element_ty);
  int64_t rank = ranked_ty.getRank();

  DenseIntElementsAttr indices;
  if (!matchPattern(reduction_indices, m_Constant(&indices))) {
    // Output type is unranked if reduction indices are not constant and reduced
    // dimensions are not kept.
    if (!keep_dims.getValue()) return UnrankedTensorType::get(element_ty);

    // Otherwise, output type has same rank as the input.
    return RankedTensorType::get(SmallVector<int64_t, 4>(rank, -1), element_ty);
  }

  int64_t num_reduce_dim = 0;
  llvm::SmallVector<bool, 4> is_reduce_dim(rank, false);
  for (const APInt &index : indices.getValues<APInt>()) {
    int64_t dim = GetDimForAxis(index.getSExtValue(), rank);
    // Invalid input.
    if (dim < 0 || dim >= rank) return UnrankedTensorType::get(element_ty);

    if (!is_reduce_dim[dim]) {
      is_reduce_dim[dim] = true;
      num_reduce_dim++;
    }
  }

  ArrayRef<int64_t> shape = ranked_ty.getShape();
  SmallVector<int64_t, 4> out_shape;
  out_shape.reserve(rank - (keep_dims.getValue() ? 0 : num_reduce_dim));
  for (int64_t i = 0; i < rank; ++i) {
    if (!is_reduce_dim[i])
      out_shape.push_back(shape[i]);
    else if (keep_dims.getValue())
      out_shape.push_back(1);
  }
  return RankedTensorType::get(out_shape, element_ty);
}