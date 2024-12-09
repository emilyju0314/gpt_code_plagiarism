void gels_batched_cublas(const Tensor& a, Tensor& b, Tensor& infos) {
  AT_DISPATCH_FLOATING_AND_COMPLEX_TYPES(a.scalar_type(), "gels_batched_cublas", [&]{
    apply_gels_batched<scalar_t>(a, b, infos);
  });
}