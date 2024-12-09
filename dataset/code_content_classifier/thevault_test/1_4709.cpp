bool Elf::Step(uint64_t rel_pc, Regs* regs, Memory* process_memory, bool* finished,
               bool* is_signal_frame) {
  if (!valid_) {
    return false;
  }

  // Lock during the step which can update information in the object.
  std::lock_guard<std::mutex> guard(lock_);
  return interface_->Step(rel_pc, regs, process_memory, finished, is_signal_frame);
}