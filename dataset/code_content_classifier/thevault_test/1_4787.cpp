UnrankedMemRefDescriptor UnrankedMemRefDescriptor::undef(OpBuilder &builder,
                                                         Location loc,
                                                         Type descriptorType) {
  Value descriptor =
      builder.create<LLVM::UndefOp>(loc, descriptorType.cast<LLVM::LLVMType>());
  return UnrankedMemRefDescriptor(descriptor);
}