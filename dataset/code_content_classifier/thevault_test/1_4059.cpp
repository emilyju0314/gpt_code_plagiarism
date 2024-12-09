void MLUGeneratorImpl::delay_init_state_once() {
  // resize and set the state tensor.
  // TODO(zhangguopeng): the nullptr arg of cnnlRandGetMTGP32StateSize maybe not right.
  if (is_floating_device) {
    std::lock_guard<std::mutex> lock(mutex_);
    std::call_once(init_state_flag, [&] {
      size_t state_size = 0;
      TORCH_CNNL_CHECK(cnnlRandGetMTGP32StateSize(nullptr, &state_size));
      auto options = at::TensorOptions().device(device_).dtype(at::kByte);
      state_ = at::empty(state_size, options);
    });
  }
}