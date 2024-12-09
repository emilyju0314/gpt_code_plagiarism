void ARM64InterceptRouting::BuildFastForwardTrampoline() {
  TurboAssembler turbo_assembler_;
  CodeGen codegen(&turbo_assembler_);
  uint64_t forward_address;

  if (entry_->type == kFunctionInlineHook) {
    forward_address = (uint64_t)entry_->replace_call;
  } else if (entry_->type == kDynamicBinaryInstrumentation) {
    forward_address = (uint64_t)entry_->prologue_dispatch_bridge;
  } else if (entry_->type == kFunctionWrapper) {
    forward_address = (uint64_t)entry_->prologue_dispatch_bridge;
  } else {
    UNREACHABLE();
  }

  codegen.LiteralLdrBranch(forward_address);

  // Patch
  CodeChunk::MemoryOperationError err;
  err = CodeChunk::PatchCodeBuffer(fast_forward_region->pointer(), turbo_assembler_.GetCodeBuffer());
  CHECK_EQ(err, CodeChunk::kMemoryOperationSuccess);
  Code *code = Code::FinalizeFromAddress((uintptr_t)fast_forward_region->pointer(), turbo_assembler_.CodeSize());

  entry_->fast_forward_trampoline = (void *)code->raw_instruction_start();
}