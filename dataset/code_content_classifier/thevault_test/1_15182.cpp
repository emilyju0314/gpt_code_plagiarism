void ARM64InterceptRouting::Active() {
  uint64_t target_address = (uint64_t)entry_->target_address;
  TurboAssembler turbo_assembler_;
#define _ turbo_assembler_.
  if (branch_type_ == ARM64_B_Branch) {
    _ b((int64_t)entry_->fast_forward_trampoline - (int64_t)target_address);
  } else {
    CodeGen codegen(&turbo_assembler_);
    // check if enable "fast forward trampoline"
    if (entry_->fast_forward_trampoline)
      codegen.LiteralLdrBranch((uint64_t)entry_->fast_forward_trampoline);
    else if (entry_->prologue_dispatch_bridge)
      codegen.LiteralLdrBranch((uint64_t)entry_->prologue_dispatch_bridge);
    else {
      if (entry_->type == kFunctionInlineHook)
        codegen.LiteralLdrBranch((uint64_t)entry_->replace_call);
    }
  }

  CodeChunk::MemoryOperationError err;
  err = CodeChunk::PatchCodeBuffer((void *)target_address, turbo_assembler_.GetCodeBuffer());
  CHECK_EQ(err, CodeChunk::kMemoryOperationSuccess);
  Code::FinalizeFromAddress(target_address, turbo_assembler_.CodeSize());

  DLOG("[*] Active the routing at %p\n", entry_->target_address);
}