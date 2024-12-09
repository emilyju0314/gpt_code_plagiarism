inline static void svd_cusolver_gesvd(const Tensor& A, const Tensor& U, const Tensor& S, const Tensor& V,
  const Tensor& infos, bool full_matrices, bool compute_uv,
  const bool calculate_all_batches = true,
  const std::vector<int64_t>& batches = {}
) {
  // We need to pass a copy of A, as it will be overwritten
  // gesvd just knows how to handle m >= n, so in the other case we need to transpose A
  const auto not_A_H = A.size(-2) >= A.size(-1);
  AT_DISPATCH_FLOATING_AND_COMPLEX_TYPES(A.scalar_type(), "svd_cuda_gesvd", [&] {
    apply_svd_cusolver_gesvd<scalar_t>(cloneBatchedColumnMajor(not_A_H ? A : A.mH()),
                                       not_A_H ? U : V,
                                       S,
                                       not_A_H ? V : U,
                                       infos,
                                       full_matrices, compute_uv, calculate_all_batches, batches);
  });
}