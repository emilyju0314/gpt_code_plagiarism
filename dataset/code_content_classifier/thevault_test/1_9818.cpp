void ARMInterceptRouting::Active() {
  if (execute_state_ == ARMExecuteState) {
    DLOG("[*] Active the routing at %p\n", entry_->target_address);
    active_arm_intercept_routing();
  } else {
    DLOG("[*] Active the routing at %p\n", entry_->target_address);
    active_thumb_intercept_routing();
  }
}