void check_mlu_tensors(const std::vector<at::Tensor>& tensors) {
  if (tensors.size() == 0) {
    throw std::runtime_error("Tensor list must be nonempty");
  }
  if (tensors.size() > static_cast<size_t>(torch_mlu::device_count())) {
    throw std::runtime_error(
        "Tensor list mustn't be larger than the number of available MLUs");
  }

  const auto& first = tensors.front();
  if (!torch_mlu::is_mlu(first) || first.is_sparse()) {
    throw std::runtime_error("Tensors must be MLU and dense");
  }
  if (!first.is_non_overlapping_and_dense()) {
    throw std::runtime_error("Tensors must be non-overlapping and dense");
  }

  if (tensors.size() != 1) {
    throw std::runtime_error(
        "MLU Tensors must be on a single MLU device per process");
  }
}