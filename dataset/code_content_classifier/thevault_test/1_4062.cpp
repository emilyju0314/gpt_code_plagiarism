at::Tensor MLUGeneratorImpl::get_state() {
  delay_init_state_once();
  update_state();
  return state_;
}