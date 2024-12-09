bool Elf::StepIfSignalHandler(uint64_t rel_pc, Regs* regs, Memory* process_memory) {
  if (!valid_) {
    return false;
  }

  // Convert the rel_pc to an elf_offset.
  if (rel_pc < static_cast<uint64_t>(load_bias_)) {
    return false;
  }
  return regs->StepIfSignalHandler(rel_pc - load_bias_, this, process_memory);
}