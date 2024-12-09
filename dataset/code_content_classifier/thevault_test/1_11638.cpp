void SILFunction::print(SILPrintContext &PrintCtx) const {
  llvm::raw_ostream &OS = PrintCtx.OS();
  if (PrintCtx.printDebugInfo()) {
    auto &SM = getModule().getASTContext().SourceMgr;
    for (auto &BB : *this)
      for (auto &I : BB) {
        SILPrinter P(PrintCtx);
        P.printDebugScope(I.getDebugScope(), SM);
      }
    OS << "\n";
  }

  if (SILPrintGenericSpecializationInfo) {
    if (isSpecialization()) {
      printGenericSpecializationInfo(OS, "function", getName(),
                                     getSpecializationInfo());
    }
  }

  OS << "// " << demangleSymbol(getName()) << '\n';
  OS << "sil ";
  printLinkage(OS, getLinkage(), isDefinition());

  if (isTransparent())
    OS << "[transparent] ";

  switch (isSerialized()) {
  case IsNotSerialized: break;
  case IsSerializable: OS << "[serializable] "; break;
  case IsSerialized: OS << "[serialized] "; break;
  }

  switch (isThunk()) {
  case IsNotThunk: break;
  case IsThunk: OS << "[thunk] "; break;
  case IsReabstractionThunk: OS << "[reabstraction_thunk] "; break;
  }

  if (isGlobalInit())
    OS << "[global_init] ";
  
  switch (getInlineStrategy()) {
    case NoInline: OS << "[noinline] "; break;
    case AlwaysInline: OS << "[always_inline] "; break;
    case InlineDefault: break;
  }

  if (getEffectsKind() == EffectsKind::ReadOnly)
    OS << "[readonly] ";
  else if (getEffectsKind() == EffectsKind::ReadNone)
      OS << "[readnone] ";
  if (getEffectsKind() == EffectsKind::ReadWrite)
    OS << "[readwrite] ";

  for (auto &Attr : getSemanticsAttrs())
    OS << "[_semantics \"" << Attr << "\"] ";

  for (auto *Attr : getSpecializeAttrs()) {
    OS << "[_specialize "; Attr->print(OS); OS << "] ";
  }

  // TODO: Handle clang node owners which don't have a name.
  if (hasClangNode() && getClangNodeOwner()->hasName()) {
    OS << "[clang ";
    printValueDecl(getClangNodeOwner(), OS);
    OS << "] ";
  }

  printName(OS);
  OS << " : $";
  
  // Print the type by substituting our context parameter names for the dependent
  // parameters. In SIL, we may end up with multiple generic parameters that
  // have the same name from different contexts, for instance, a generic
  // protocol requirement with a generic method parameter <T>, which is
  // witnessed by a generic type that has a generic type parameter also named
  // <T>, so we may need to introduce disambiguating aliases.
  llvm::DenseMap<CanType, Identifier> Aliases;
  llvm::DenseSet<Identifier> UsedNames;
  
  auto sig = getLoweredFunctionType()->getGenericSignature();
  auto *env = getGenericEnvironment();
  if (sig && env) {
    llvm::SmallString<16> disambiguatedNameBuf;
    unsigned disambiguatedNameCounter = 1;
    for (auto *paramTy : sig->getGenericParams()) {
      auto sugaredTy = env->getSugaredType(paramTy);
      Identifier name = sugaredTy->getName();
      while (!UsedNames.insert(name).second) {
        disambiguatedNameBuf.clear();
        {
          llvm::raw_svector_ostream names(disambiguatedNameBuf);
          names << sugaredTy->getName() << disambiguatedNameCounter++;
        }
        name = getASTContext().getIdentifier(disambiguatedNameBuf);
      }
      if (name != sugaredTy->getName()) {
        Aliases[paramTy->getCanonicalType()] = name;

        // Also for the archetype
        auto archetypeTy = env->mapTypeIntoContext(paramTy)
            ->getAs<ArchetypeType>();
        if (archetypeTy)
          Aliases[archetypeTy->getCanonicalType()] = name;
      }
    }
  }

  {
    PrintOptions withGenericEnvironment = PrintOptions::printSIL();
    withGenericEnvironment.GenericEnv = env;
    withGenericEnvironment.AlternativeTypeNames =
      Aliases.empty() ? nullptr : &Aliases;
    LoweredType->print(OS, withGenericEnvironment);
  }
  
  if (!isExternalDeclaration()) {
    OS << " {\n";

    SILPrinter(PrintCtx, (Aliases.empty() ? nullptr : &Aliases))
        .print(this);
    OS << "} // end sil function '" << getName() << '\'';
  }

  OS << "\n\n";
}