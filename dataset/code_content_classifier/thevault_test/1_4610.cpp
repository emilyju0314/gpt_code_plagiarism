const char *Argmin(Tensor a, int64_t *dim, int8_t keepdim, Tensor *result) {
  try {
    if (dim == nullptr) {
      *result = new at::Tensor(a->argmin());
    } else {
      *result = new at::Tensor(a->argmin(*dim, static_cast<bool>(keepdim)));
    }
    return nullptr;
  } catch (const std::exception &e) {
    return exception_str(e.what());
  }
}