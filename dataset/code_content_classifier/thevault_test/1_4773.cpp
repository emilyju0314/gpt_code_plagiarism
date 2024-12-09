LLVM::LLVMType LLVMTypeConverter::convertFunctionSignature(
    FunctionType type, bool isVariadic,
    LLVMTypeConverter::SignatureConversion &result) {
  // Convert argument types one by one and check for errors.
  for (auto &en : llvm::enumerate(type.getInputs())) {
    Type type = en.value();
    auto converted = convertType(type).dyn_cast_or_null<LLVM::LLVMType>();
    if (!converted)
      return {};
    if (type.isa<MemRefType>() || type.isa<UnrankedMemRefType>())
      converted = converted.getPointerTo();
    result.addInputs(en.index(), converted);
  }

  SmallVector<LLVM::LLVMType, 8> argTypes;
  argTypes.reserve(llvm::size(result.getConvertedTypes()));
  for (Type type : result.getConvertedTypes())
    argTypes.push_back(unwrap(type));

  // If function does not return anything, create the void result type,
  // if it returns on element, convert it, otherwise pack the result types into
  // a struct.
  LLVM::LLVMType resultType =
      type.getNumResults() == 0
          ? LLVM::LLVMType::getVoidTy(llvmDialect)
          : unwrap(packFunctionResults(type.getResults()));
  if (!resultType)
    return {};
  return LLVM::LLVMType::getFunctionTy(resultType, argTypes, isVariadic);
}