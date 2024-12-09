std::tuple<int64_t, std::vector<int64_t>, std::vector<int64_t>>
compute_shapes(const at::Tensor& self,
               const std::vector<at::Tensor>& indices) {
  std::vector<int64_t> output_dims;
  auto self_dims = self.sizes().vec();
  auto indices_num = indices.size();
  std::vector<int64_t> indice_size;
  int64_t indice_dim;
  at::TensorOptions option;

  // reshape size for defined indices
  std::vector<int64_t> def_reshape_size;

  // check if defined indice has been calculated
  bool has_defined = false;

  // calculate output dims for indices
  for (int64_t j = 0; j < indices_num; ++j) {
    if (indices[j].defined()) {
      if (!has_defined) {
        indice_size = indices[j].sizes().vec();
        indice_dim = indices[j].dim();
        option = indices[j].options();
        output_dims.insert(output_dims.end(), indice_size.begin(), indice_size.end());
        def_reshape_size.insert(def_reshape_size.end(), indice_size.begin(), indice_size.end());
        std::vector<int64_t> ones_vec(indice_size.size(), 1);
        has_defined = true;
      }
    } else {
      output_dims.emplace_back(self_dims[j]);
      def_reshape_size.emplace_back(1);
    }
  }
  return std::make_tuple(indice_dim, output_dims, def_reshape_size);
}