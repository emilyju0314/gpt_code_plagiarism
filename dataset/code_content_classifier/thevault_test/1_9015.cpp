void Sema::ProcessDeclAttributes(Scope *S, Decl *D, const Declarator &PD) {
  // Apply decl attributes from the DeclSpec if present.
  if (!PD.getDeclSpec().getAttributes().empty())
    ProcessDeclAttributeList(S, D, PD.getDeclSpec().getAttributes());

  // Walk the declarator structure, applying decl attributes that were in a type
  // position to the decl itself.  This handles cases like:
  //   int *__attr__(x)** D;
  // when X is a decl attribute.
  for (unsigned i = 0, e = PD.getNumTypeObjects(); i != e; ++i)
    ProcessDeclAttributeList(S, D, PD.getTypeObject(i).getAttrs(),
                             /*IncludeCXX11Attributes=*/false);

  // Finally, apply any attributes on the decl itself.
  ProcessDeclAttributeList(S, D, PD.getAttributes());

  // Apply additional attributes specified by '#pragma clang attribute'.
  AddPragmaAttributes(S, D);

  // CHEERP: Inject asmjs/genericjs attribute if required
  MaybeInjectCheerpModeAttr(D);
}