void ARM64InterceptRouting::Prepare() {
  uint64_t src_address     = (uint64_t)entry_->target_address;
  Interceptor *interceptor = Interceptor::SharedInstance();
  int relocate_size        = 0;
  MemoryRegion *region     = NULL;

  if (interceptor->options().enable_arm_arm64_b_branch) {
    DLOG("%s", "[*] Enable b branch maybe cause crash, if crashed, please disable it.\n");
    DLOG("%s", "[*] Use ARM64 B-xxx Branch.\n");
    region = CodeChunk::AllocateCodeCave(src_address, ARM64_B_XXX_RANGE, ARM64_TINY_REDIRECT_SIZE);
    if (region) {
      relocate_size = ARM64_TINY_REDIRECT_SIZE;
      branch_type_  = ARM64_B_Branch;
    } else {
      DLOG("%s", "[!] Can't find any cove cave, change to ldr branch");
    }
  }

  if (region)
    fast_forward_region = region;
  else {
    DLOG("%s", "[*] Use ARM64 Ldr Branch.\n");
    branch_type_  = ARM64_LDR_Branch;
    relocate_size = ARM64_FULL_REDIRECT_SIZE;
  }

  // Gen the relocated code
  Code *code;
  code                              = GenRelocateCode(src_address, &relocate_size);
  entry_->relocated_origin_function = (void *)code->raw_instruction_start();
  DLOG("[*] Relocate origin (prologue) instruction at %p.\n", (void *)code->raw_instruction_start());

  // save original prologue
  memcpy(entry_->origin_instructions.data, entry_->target_address, relocate_size);
  entry_->origin_instructions.size    = relocate_size;
  entry_->origin_instructions.address = entry_->target_address;
}