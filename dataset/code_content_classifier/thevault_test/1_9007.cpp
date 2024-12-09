static void handleObjCBoxable(Sema &S, Decl *D, const ParsedAttr &AL) {
  bool notify = false;

  auto *RD = dyn_cast<RecordDecl>(D);
  if (RD && RD->getDefinition()) {
    RD = RD->getDefinition();
    notify = true;
  }

  if (RD) {
    ObjCBoxableAttr *BoxableAttr = ::new (S.Context)
                          ObjCBoxableAttr(AL.getRange(), S.Context,
                                          AL.getAttributeSpellingListIndex());
    RD->addAttr(BoxableAttr);
    if (notify) {
      // we need to notify ASTReader/ASTWriter about
      // modification of existing declaration
      if (ASTMutationListener *L = S.getASTMutationListener())
        L->AddedAttributeToRecord(BoxableAttr, RD);
    }
  }
}