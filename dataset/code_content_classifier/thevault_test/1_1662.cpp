static void handleIntelFPGAMergeAttr(Sema &S, Decl *D, const ParsedAttr &AL) {
  checkForDuplicateAttribute<IntelFPGAMergeAttr>(S, D, AL);

  if (S.LangOpts.SYCLIsHost)
    return;

  if (checkAttrMutualExclusion<IntelFPGARegisterAttr>(S, D, AL))
    return;

  SmallVector<StringRef, 2> Results;
  for (int I = 0; I < 2; I++) {
    StringRef Str;
    if (!S.checkStringLiteralArgumentAttr(AL, I, Str))
      return;

    if (I == 1 && Str != "depth" && Str != "width") {
      S.Diag(AL.getLoc(), diag::err_intel_fpga_merge_dir_invalid) << AL;
      return;
    }
    Results.push_back(Str);
  }

  if (!D->hasAttr<IntelFPGAMemoryAttr>())
    D->addAttr(IntelFPGAMemoryAttr::CreateImplicit(
        S.Context, IntelFPGAMemoryAttr::Default));

  S.CheckDeprecatedSYCLAttributeSpelling(AL);

  D->addAttr(::new (S.Context)
                 IntelFPGAMergeAttr(S.Context, AL, Results[0], Results[1]));
}