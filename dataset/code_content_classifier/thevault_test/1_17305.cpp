Type ShuffleRankedTensorType(Type type, ArrayRef<int64_t> permutation) {
  if (auto ranked_type = type.dyn_cast<RankedTensorType>()) {
    ArrayRef<int64_t> shape = ranked_type.getShape();
    assert(permutation.size() == shape.size());

    SmallVector<int64_t, 4> new_shape(permutation.size());
    for (size_t i = 0; i < permutation.size(); ++i)
      new_shape[i] = shape[permutation[i]];

    return RankedTensorType::get(new_shape, ranked_type.getElementType());
  }

  return type;
}