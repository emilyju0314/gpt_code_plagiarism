const char *Tensor_FromBlob(void *data, int8_t dtype, int64_t *sizes_data,
                            int64_t sizes_data_len, Tensor *result) {
  try {
    auto t = at::from_blob(data, at::IntArrayRef(sizes_data, sizes_data_len),
                           torch::dtype(at::ScalarType(dtype)))
                 .clone();
    *result = new at::Tensor(t);
    return nullptr;
  } catch (const std::exception &e) {
    return exception_str(e.what());
  }
}