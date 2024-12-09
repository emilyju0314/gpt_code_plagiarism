static bool checkIntelFPGARegisterAttrCompatibility(Sema &S, Decl *D,
                                                    const ParsedAttr &Attr) {
  bool InCompat = false;
  if (auto *MA = D->getAttr<IntelFPGAMemoryAttr>())
    if (!MA->isImplicit() &&
        checkAttrMutualExclusion<IntelFPGAMemoryAttr>(S, D, Attr))
      InCompat = true;
  if (checkAttrMutualExclusion<IntelFPGADoublePumpAttr>(S, D, Attr))
    InCompat = true;
  if (checkAttrMutualExclusion<IntelFPGASinglePumpAttr>(S, D, Attr))
    InCompat = true;
  if (checkAttrMutualExclusion<IntelFPGABankWidthAttr>(S, D, Attr))
    InCompat = true;
  if (checkAttrMutualExclusion<IntelFPGAPrivateCopiesAttr>(S, D, Attr))
    InCompat = true;
  if (auto *NBA = D->getAttr<IntelFPGANumBanksAttr>())
    if (!NBA->isImplicit() &&
        checkAttrMutualExclusion<IntelFPGANumBanksAttr>(S, D, Attr))
      InCompat = true;
  if (checkAttrMutualExclusion<IntelFPGAMaxReplicatesAttr>(S, D, Attr))
    InCompat = true;
  if (checkAttrMutualExclusion<IntelFPGASimpleDualPortAttr>(S, D, Attr))
    InCompat = true;
  if (checkAttrMutualExclusion<IntelFPGAMergeAttr>(S, D, Attr))
    InCompat = true;
  if (checkAttrMutualExclusion<IntelFPGABankBitsAttr>(S, D, Attr))
    InCompat = true;
  if (checkAttrMutualExclusion<IntelFPGAForcePow2DepthAttr>(S, D, Attr))
    InCompat = true;

  return InCompat;
}