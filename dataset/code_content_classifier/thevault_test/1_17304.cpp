ArrayAttr ShuffleArrayAttr(ArrayAttr attr, ArrayRef<int64_t> permutation,
                           int inner_size = 1) {
  if (attr.size() == 0) return attr;

  assert(attr.size() % inner_size == 0);
  assert(attr.size() / inner_size == permutation.size());

  SmallVector<Attribute, 8> values{attr.begin(), attr.end()};
  SmallVector<Attribute, 8> shuffled(values.size());

  for (size_t i = 0; i < permutation.size(); ++i) {
    for (size_t j = 0; j < inner_size; ++j) {
      shuffled[i * inner_size + j] = values[permutation[i] * inner_size + j];
    }
  }

  return ArrayAttr::get(shuffled, attr.getContext());
}