void MLUGeneratorImpl::update_state() {
  // update the state tensor.
  if (is_floating_device && state_need_reset_) {
    std::lock_guard<std::mutex> lock(mutex_);
    auto state_impl = getMluTensorImpl(state_);
    auto state_ptr = state_impl->cnnlMalloc();
    TORCH_CHECK(state_ptr, "the state point is nullptr, "
                           "please init state before calling its point");
    auto handle = getCurrentHandle();
    TORCH_CNNL_CHECK(cnnlRandMakeMTGP32KernelState(handle, state_ptr, nullptr, nullptr, seed_));
    state_need_reset_ = false;
  }
}