void batchCheckErrors(const at::Tensor& infos, const char* name, bool allow_singular) {
  auto batch_size = infos.numel();
  auto infos_cpu = infos.to(at::kCPU);
  auto infos_data = infos_cpu.data_ptr<int>();
  for (int64_t i = 0; i < batch_size; i++) {
    auto info = infos_data[i];
    if (info < 0) {
      CNLOG(ERROR) << name << ": For batch " << i << ": Argument " << -info << " has illegal value";
    } else if (info > 0) {
      if (strstr(name, "svd")) {
        CNLOG(ERROR) << name << ": the "  << i
                     << "-th input matrix SVD computation do not converge, "
                     << "(error: " << info << ") the precision of the results might be low.";
      } else if (strstr(name, "symeig")) {
        CNLOG(ERROR) << name << ": For batch " << i << ": the algorithm failed to converge; "
                     << info << " off-diagonal elements of an intermediate tridiagonal"
                     << " form did not converge to zero.";
      } else if (!allow_singular) {
        CNLOG(ERROR) << name << ": For batch " << i << ": U("
                     << info << "," << info << ") is zero, singular U.";
      }
    }
  }
}