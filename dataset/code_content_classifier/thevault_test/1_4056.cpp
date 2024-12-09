at::Generator createMLUGenerator(at::DeviceIndex device_index) {
  std::call_once(num_mlu_init_flag, initMLUGenVector);
  at::DeviceIndex idx = device_index;
  if (idx == -1) {
    idx = current_device();
  }
  TORCH_CHECK(idx >= 0 && idx < num_mlus, "The device_index is invalid.");
  auto generator = at::make_generator<MLUGeneratorImpl>(idx);
  auto gen_impl = at::check_generator<MLUGeneratorImpl>(generator);
  gen_impl->set_current_seed(c10::default_rng_seed_val);
  return generator;
}