int64_t modify_dim_based_on_layout(const int64_t dim,
            const c10::MemoryFormat memory_format) {
  int64_t target_dim;
  switch (memory_format) {
    case c10::MemoryFormat::ChannelsLast:
      transLayoutParameterDim(CNNL_LAYOUT_NCHW, CNNL_LAYOUT_NHWC, dim, &target_dim);
      break;
    case c10::MemoryFormat::ChannelsLast3d:
      transLayoutParameterDim(CNNL_LAYOUT_NCDHW, CNNL_LAYOUT_NDHWC, dim, &target_dim);
      break;
    case c10::MemoryFormat::Contiguous:
      target_dim = dim;
      break;
    default:
      TORCH_MLU_CHECK(false, "memory format not support.");
      break;
  }
  return target_dim;
}