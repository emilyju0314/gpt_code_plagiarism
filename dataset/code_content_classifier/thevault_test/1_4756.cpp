std::vector<int64_t> _check_gesvdj_convergence(const Tensor& infos, int64_t non_converging_info) {
  at::Tensor infos_cpu = infos.cpu();
  auto infos_cpu_data = infos_cpu.data_ptr<int>();

  std::vector<int64_t> res;

  for(int64_t i = 0; i < infos.numel(); i++) {
    int info_for_batch_i = infos_cpu_data[i];

    // From cusolver doc, if info < 0, the i-th function call parameter is wrong,
    // which means pytorch implementation of cusolver is wrong.
    TORCH_INTERNAL_ASSERT_DEBUG_ONLY(info_for_batch_i >= 0);

    // In our use case, gesvdj, gesvdjBatched, and gesvdaStridedBatched have the same notations for `info`.
    if (info_for_batch_i == non_converging_info) res.push_back(i);

    // However, it is not the same for gesvd, though we don't use this function to check gesvd convergence either.
    // If it's implemented some day in the future, this needs to be handled carefully.
  }

  return res;
}