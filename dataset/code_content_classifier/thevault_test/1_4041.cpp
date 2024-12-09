at::Tensor flatten_tensor_list(std::vector<std::vector<at::Tensor>>& tensor_lists,
    std::vector<at::Tensor>& other, size_t world_size) {
  if (tensor_lists.size() != 1 || other.size() != 1) {
    throw std::runtime_error(
        "MLU Tensors must be on a single MLU device per process");
  }

  auto device = other[0].device();
  for (const auto& t : tensor_lists[0]) {
    if (t.numel() != other[0].numel()) {
      throw std::runtime_error(
          "All tensor operands to scatter/gather must have the same size");
    }
    if (t.device() != device) {
      throw std::runtime_error("Expecting all tensors on the same device");
    }
  }

  std::vector<int64_t> new_size{static_cast<int64_t>(tensor_lists[0].size())};
  new_size.insert(new_size.end(), tensor_lists[0][0].sizes().begin(),
                  tensor_lists[0][0].sizes().end());
  return at::empty(new_size, tensor_lists[0][0].options());
}