Type LLVMTypeConverter::convertFunctionType(FunctionType type) {
  SignatureConversion conversion(type.getNumInputs());
  LLVM::LLVMType converted =
      convertFunctionSignature(type, /*isVariadic=*/false, conversion);
  return converted.getPointerTo();
}