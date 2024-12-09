static void handleIntelFPGABankBitsAttr(Sema &S, Decl *D, const ParsedAttr &A) {
  checkForDuplicateAttribute<IntelFPGABankBitsAttr>(S, D, A);

  if (!checkAttributeAtLeastNumArgs(S, A, 1))
    return;

  if (checkAttrMutualExclusion<IntelFPGARegisterAttr>(S, D, A))
    return;

  SmallVector<Expr *, 8> Args;
  for (unsigned I = 0; I < A.getNumArgs(); ++I) {
    Args.push_back(A.getArgAsExpr(I));
  }

  S.CheckDeprecatedSYCLAttributeSpelling(A);

  S.AddIntelFPGABankBitsAttr(D, A, Args.data(), Args.size());
}