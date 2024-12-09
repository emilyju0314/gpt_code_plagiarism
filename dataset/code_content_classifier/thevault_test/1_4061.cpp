void* MLUGeneratorImpl::get_state_ptr() const {
  // update the state tensor.
  auto state_impl = getMluTensorImpl(state_);
  auto state_ptr = state_impl->cnnlMalloc();
  TORCH_CHECK(state_ptr, "the state point is nullptr, please init state before calling its point");
  return state_ptr;
}