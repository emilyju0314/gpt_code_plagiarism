void ARMInterceptRouting::Prepare() {
  uintptr_t src_address = (uintptr_t)entry_->target_address;

  // set instruction running state
  execute_state_ = ARMExecuteState;
  if (src_address % 2) {
    execute_state_ = ThumbExecuteState;
  }

  // Determined which branch_type_, and corrreponding trampoline size
  if (execute_state_ == ThumbExecuteState) {
    prepare_thumb();
  } else {
    prepare_arm();
  }

  // Gen the relocated code
  Code *code;
  code                              = GenRelocateCode(src_address, &relocate_size);
  entry_->relocated_origin_function = (void *)code->raw_instruction_start();
  // If Thumb Execute, code snippet address should be odd.
  if (execute_state_ == ThumbExecuteState) {
    entry_->relocated_origin_function = (void *)((uint32_t)entry_->relocated_origin_function + 1);
  }
  DLOG("[*] Relocate origin (prologue) instruction at %p.\n", (void *)code->raw_instruction_start());

  // backup original prologue
  memcpy(entry_->origin_instructions.data, entry_->target_address, relocate_size);
  entry_->origin_instructions.size    = relocate_size;
  entry_->origin_instructions.address = entry_->target_address;
}