IsSerialized_t SILDeclRef::isSerialized() const {
  DeclContext *dc;
  if (auto closure = getAbstractClosureExpr())
    dc = closure->getLocalContext();
  else {
    auto *d = getDecl();

    // Default argument generators are serialized if the function was
    // type-checked in Swift 4 mode.
    if (kind == SILDeclRef::Kind::DefaultArgGenerator) {
      auto *afd = cast<AbstractFunctionDecl>(d);
      switch (afd->getDefaultArgumentResilienceExpansion()) {
      case ResilienceExpansion::Minimal:
        return IsSerialized;
      case ResilienceExpansion::Maximal:
        return IsNotSerialized;
      }
    }

    dc = getDecl()->getInnermostDeclContext();

    // Enum element constructors are serialized if the enum is
    // @_versioned or public.
    if (isEnumElement())
      if (d->getEffectiveAccess() >= AccessLevel::Public)
        return IsSerialized;

    // Currying thunks are serialized if referenced from an inlinable
    // context -- Sema's semantic checks ensure the serialization of
    // such a thunk is valid, since it must in turn reference a public
    // symbol, or dispatch via class_method or witness_method.
    if (isCurried)
      if (d->getEffectiveAccess() >= AccessLevel::Public)
        return IsSerializable;

    if (isForeignToNativeThunk())
      return IsSerializable;

    // The allocating entry point for designated initializers are serialized
    // if the class is @_versioned or public.
    if (kind == SILDeclRef::Kind::Allocator) {
      auto *ctor = cast<ConstructorDecl>(d);
      if (ctor->isDesignatedInit() &&
          ctor->getDeclContext()->getAsClassOrClassExtensionContext()) {
        if (ctor->getEffectiveAccess() >= AccessLevel::Public &&
            !ctor->hasClangNode())
          return IsSerialized;
      }
    }
  }

  // Declarations imported from Clang modules are serialized if
  // referenced from an inlineable context.
  if (isClangImported())
    return IsSerializable;

  // Otherwise, ask the AST if we're inside an @_inlineable context.
  if (dc->getResilienceExpansion() == ResilienceExpansion::Minimal)
    return IsSerialized;

  return IsNotSerialized;
}