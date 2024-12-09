std::vector<int64_t> compute_shapes(const at::Tensor& self,
                                    const at::Tensor& indice) {
    std::vector<int64_t> output_dims;
    auto self_size = self.sizes().vec();
    output_dims.emplace_back(indice.numel());
    if (indice.dim() != self.dim()) {
        for (int64_t i = indice.dim(); i < self.dim(); ++i) {
            output_dims.emplace_back(self_size[i]);
        }
    }
    return output_dims;
}