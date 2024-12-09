inline static void svd_cusolver_gesvdj(const Tensor& A, const Tensor& U, const Tensor& S, const Tensor& V, const Tensor& infos, bool full_matrices, bool compute_uv) {
  AT_DISPATCH_FLOATING_AND_COMPLEX_TYPES(A.scalar_type(), "svd_cuda_gesvdj", [&] {
    apply_svd_cusolver_gesvdj<scalar_t>(A, U, S, V, infos, full_matrices, compute_uv);
  });
}