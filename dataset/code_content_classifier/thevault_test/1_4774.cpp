MemRefDescriptor::MemRefDescriptor(Value descriptor)
    : StructBuilder(descriptor) {
  assert(value != nullptr && "value cannot be null");
  indexType = value->getType().cast<LLVM::LLVMType>().getStructElementType(
      kOffsetPosInMemRefDescriptor);
}