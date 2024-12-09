static llvm::Constant *
createInPlaceMetadataInitializationFunction(IRGenModule &IGM, 
                                            CanNominalType type,
                                            llvm::Constant *metadata,
                                            llvm::Constant *cacheVariable,
                                     InPlaceMetadataInitializer &&initialize) {
  // There's an ignored i8* parameter.
  auto fnTy = llvm::FunctionType::get(IGM.VoidTy, {IGM.Int8PtrTy},
                                      /*variadic*/ false);
  llvm::Function *fn = llvm::Function::Create(fnTy,
                                       llvm::GlobalValue::PrivateLinkage,
                                       Twine("initialize_metadata_")
                                           + type->getDecl()->getName().str(),
                                       &IGM.Module);
  fn->setAttributes(IGM.constructInitialAttributes());
  
  // Set up the function.
  IRGenFunction IGF(IGM, fn);
  if (IGM.DebugInfo)
    IGM.DebugInfo->emitArtificialFunction(IGF, fn);

  // Skip instrumentation when building for TSan to avoid false positives.
  // The synchronization for this happens in the Runtime and we do not see it.
  if (IGM.IRGen.Opts.Sanitizers & SanitizerKind::Thread)
    fn->removeFnAttr(llvm::Attribute::SanitizeThread);

  // Emit the initialization.
  llvm::Value *relocatedMetadata = initialize(IGF, metadata);

  // Store back to the cache variable.
  IGF.Builder.CreateStore(relocatedMetadata,
                          Address(cacheVariable, IGM.getPointerAlignment()))
    ->setAtomic(llvm::AtomicOrdering::Release);

  IGF.Builder.CreateRetVoid();
  return fn;
}