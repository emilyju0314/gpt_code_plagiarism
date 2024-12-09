static NDVectorTypeInfo extractNDVectorTypeInfo(VectorType vectorType,
                                                LLVMTypeConverter &converter) {
  assert(vectorType.getRank() > 1 && "expected >1D vector type");
  NDVectorTypeInfo info;
  info.llvmArrayTy =
      converter.convertType(vectorType).dyn_cast<LLVM::LLVMType>();
  if (!info.llvmArrayTy)
    return info;
  info.arraySizes.reserve(vectorType.getRank() - 1);
  auto llvmTy = info.llvmArrayTy;
  while (llvmTy.isArrayTy()) {
    info.arraySizes.push_back(llvmTy.getArrayNumElements());
    llvmTy = llvmTy.getArrayElementType();
  }
  if (!llvmTy.isVectorTy())
    return info;
  info.llvmVectorTy = llvmTy;
  return info;
}