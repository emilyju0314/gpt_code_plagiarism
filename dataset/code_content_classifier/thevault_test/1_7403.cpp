std::vector<XLATensor> WrapIndicesOnce(const XLATensor& base,
                                       absl::Span<const XLATensor> indices,
                                       int start_dim) {
  std::vector<XLATensor> canonical_indices;
  auto base_shape_ref = base.shape();
  XLA_CHECK_LE(indices.size(), base_shape_ref.get().rank());
  for (size_t dim_idx = 0; dim_idx < indices.size(); ++dim_idx) {
    const XLATensor& dim_index = indices[dim_idx];
    int64_t dim_size = base_shape_ref.get().dimensions(dim_idx + start_dim);
    XLATensor wrapped_dim_index = XLATensor::Create(
        dim_index.GetIrValue() +
            XLATensor::GetIrValueForScalar(dim_size, dim_index.shape(),
                                           base.GetDevice()),
        base.GetDevice());
    XLATensor wrap_cond =
        XLATensor::lt(indices[dim_idx], at::Scalar(int64_t(0)));
    canonical_indices.push_back(
        XLATensor::where(wrap_cond, wrapped_dim_index, dim_index));
  }
  return canonical_indices;
}