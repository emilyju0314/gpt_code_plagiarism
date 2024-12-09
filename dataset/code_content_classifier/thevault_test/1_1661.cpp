static void handleIntelFPGARegisterAttr(Sema &S, Decl *D, const ParsedAttr &A) {

  if (S.LangOpts.SYCLIsHost)
    return;

  checkForDuplicateAttribute<IntelFPGARegisterAttr>(S, D, A);
  if (checkIntelFPGARegisterAttrCompatibility(S, D, A))
    return;

  S.CheckDeprecatedSYCLAttributeSpelling(A, "fpga_register");

  handleSimpleAttribute<IntelFPGARegisterAttr>(S, D, A);
}