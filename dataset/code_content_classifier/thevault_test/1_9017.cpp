static std::pair<AvailabilityResult, const NamedDecl *>
ShouldDiagnoseAvailabilityOfDecl(Sema &S, const NamedDecl *D,
                                 std::string *Message,
                                 ObjCInterfaceDecl *ClassReceiver) {
  AvailabilityResult Result = D->getAvailability(Message);

  // For typedefs, if the typedef declaration appears available look
  // to the underlying type to see if it is more restrictive.
  while (const auto *TD = dyn_cast<TypedefNameDecl>(D)) {
    if (Result == AR_Available) {
      if (const auto *TT = TD->getUnderlyingType()->getAs<TagType>()) {
        D = TT->getDecl();
        Result = D->getAvailability(Message);
        continue;
      }
    }
    break;
  }

  // Forward class declarations get their attributes from their definition.
  if (const auto *IDecl = dyn_cast<ObjCInterfaceDecl>(D)) {
    if (IDecl->getDefinition()) {
      D = IDecl->getDefinition();
      Result = D->getAvailability(Message);
    }
  }

  if (const auto *ECD = dyn_cast<EnumConstantDecl>(D))
    if (Result == AR_Available) {
      const DeclContext *DC = ECD->getDeclContext();
      if (const auto *TheEnumDecl = dyn_cast<EnumDecl>(DC)) {
        Result = TheEnumDecl->getAvailability(Message);
        D = TheEnumDecl;
      }
    }

  // For +new, infer availability from -init.
  if (const auto *MD = dyn_cast<ObjCMethodDecl>(D)) {
    if (S.NSAPIObj && ClassReceiver) {
      ObjCMethodDecl *Init = ClassReceiver->lookupInstanceMethod(
          S.NSAPIObj->getInitSelector());
      if (Init && Result == AR_Available && MD->isClassMethod() &&
          MD->getSelector() == S.NSAPIObj->getNewSelector() &&
          MD->definedInNSObject(S.getASTContext())) {
        Result = Init->getAvailability(Message);
        D = Init;
      }
    }
  }

  return {Result, D};
}