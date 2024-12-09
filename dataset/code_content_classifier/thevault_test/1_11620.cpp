static llvm::Value *emitTypeMetadataAccessFunctionBody(IRGenFunction &IGF,
                                                       CanType type) {
  assert(!type->hasArchetype() &&
         "cannot emit metadata accessor for context-dependent type");

  // We only take this path for That means
  // everything except non-generic nominal types.
  auto typeDecl = type->getAnyNominal();
  if (!typeDecl)
    return emitDirectTypeMetadataRef(IGF, type);

  if (typeDecl->isGenericContext() &&
      !(isa<ClassDecl>(typeDecl) &&
        isa<ClangModuleUnit>(typeDecl->getModuleScopeContext()))) {
    // This is a metadata accessor for a fully substituted generic type.
    return emitDirectTypeMetadataRef(IGF, type);
  }

  // We should never be emitting a metadata accessor for resilient nominal
  // types outside of their defining module.  We'd only do that anyway for
  // types that don't guarantee the existence of a non-unique access
  // function, and that should never be true of a resilient type with
  // external availability.
  //
  // (The type might still not have a statically-known layout.  It just
  // can't be resilient at the top level: we have to know its immediate
  // members, or we can't even begin to approach the problem of emitting
  // metadata for it.)
  assert(!IGF.IGM.isResilient(typeDecl, ResilienceExpansion::Maximal));

  // Non-native types are just wrapped in various ways.
  if (auto classDecl = dyn_cast<ClassDecl>(typeDecl)) {
    // We emit a completely different pattern for foreign classes.
    if (classDecl->getForeignClassKind() == ClassDecl::ForeignKind::CFType) {
      return emitForeignTypeMetadataRef(IGF, type);
    }

    // Classes that might not have Swift metadata use a different
    // symbol name.
    if (!hasKnownSwiftMetadata(IGF.IGM, classDecl)) {
      return emitObjCMetadataRef(IGF, classDecl);
    }

  // Imported value types require foreign metadata uniquing.
  } else if (isa<ClangModuleUnit>(typeDecl->getModuleScopeContext())) {
    return emitForeignTypeMetadataRef(IGF, type);
  }

  // Okay, everything else is built from a Swift metadata object.
  llvm::Constant *metadata = IGF.IGM.getAddrOfTypeMetadata(type, false);

  // We should not be doing more serious work along this path.
  assert(isTypeMetadataAccessTrivial(IGF.IGM, type));

  return metadata;
}