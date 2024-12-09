MLUGeneratorImpl* MLUGeneratorImpl::clone_impl() const {
  auto gen = new MLUGeneratorImpl(this->device().index());
  gen->set_current_seed(this->seed_);
  auto state = this->state_;
  auto state_clone = state.clone();
  gen->set_state(state_clone);
  gen->set_state_flag(this->state_need_reset_);
  return gen;
}