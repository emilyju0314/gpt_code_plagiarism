static llvm::Value *
emitInPlaceTypeMetadataAccessFunctionBody(IRGenFunction &IGF,
                                          CanNominalType type,
                                          llvm::Constant *cacheVariable,
                                    InPlaceMetadataInitializer &&initializer) {
  llvm::Constant *metadata = IGF.IGM.getAddrOfTypeMetadata(type, false);

  // We might not have interesting initialization to do.
  assert((cacheVariable == nullptr) ==
            isTypeMetadataAccessTrivial(IGF.IGM, type));
  if (!cacheVariable)
    return metadata;

  // Okay, we have non-trivial initialization to do.
  // Ensure that we don't have multiple threads racing to do this.
  llvm::GlobalVariable *onceGuard =
    new llvm::GlobalVariable(IGF.IGM.Module, IGF.IGM.OnceTy, /*constant*/ false,
                             llvm::GlobalValue::PrivateLinkage,
                             llvm::Constant::getNullValue(IGF.IGM.OnceTy),
                             Twine(IGF.CurFn->getName()) + ".once_token");

  // There's no point in performing the fast-path token check here
  // because we've already checked the cache variable.  We're just using
  // swift_once to guarantee thread safety.
  assert(cacheVariable && "lazy initialization but no cache variable");

  // Create the protected function.  swift_once wants this as an i8*.
  llvm::Value *onceFn =
    createInPlaceMetadataInitializationFunction(IGF.IGM, type, metadata,
                                                cacheVariable,
                                                std::move(initializer));
  onceFn = IGF.Builder.CreateBitCast(onceFn, IGF.IGM.Int8PtrTy);
  auto context = llvm::UndefValue::get(IGF.IGM.Int8PtrTy);

  auto onceCall = IGF.Builder.CreateCall(IGF.IGM.getOnceFn(),
                                         {onceGuard, onceFn, context});
  onceCall->setCallingConv(IGF.IGM.DefaultCC);

  // We can just load the cache now.
  // TODO: this should be consume-ordered when LLVM supports it.
  Address cacheAddr = Address(cacheVariable, IGF.IGM.getPointerAlignment());
  llvm::LoadInst *relocatedMetadata = IGF.Builder.CreateLoad(cacheAddr);
  // Make this barrier explicit when building for TSan to avoid false positives.
  if (IGF.IGM.IRGen.Opts.Sanitizers & SanitizerKind::Thread)
    relocatedMetadata->setOrdering(llvm::AtomicOrdering::Acquire);

  // emitLazyCacheAccessFunction will see that the value was loaded from
  // the guard variable and skip the redundant store back.
  return relocatedMetadata;
}